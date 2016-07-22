#include "scheduler.h"
#include "thread.h"
#include "mem.h"
#include "system.h"
#include "log.h"
#include "work.h"

#define MAX_LIST_SIZE 64

typedef struct SchEntry{
	uint32_t time;
	void (*func)(void *);
	void *arg;
	struct SchEntry *next;
} SchEntry;

static SchEntry *l_head;
static uint32_t l_listSize;

static Thread *l_thr;
static Mutex *l_mtx;
static CondVar *l_cond;
static uint32_t l_exit;

static void Scheduler(void *unused)
{
	SchEntry *tmp;
	while(!l_exit){
		MTX_Lock(l_mtx);

		// if the list is empty, wait until something gets scheduled
		if(!l_head){
			COND_Wait(l_cond, l_mtx);

			// this should not happen
			if(!l_head){
				MTX_Unlock(l_mtx);
				continue;
			}
		}

		// as the list is sorted by execution time
		// we need to check only the head time and
		// wait until it is time for its execution
		if(l_head->time > SYS_GetTickCount()){
			COND_TimedWait(l_cond, l_mtx, (l_head->time - SYS_GetTickCount()));

			//
			if(l_head->time > SYS_GetTickCount()){
				MTX_Unlock(l_mtx);
				continue;
			}
		}

		// when it's time for execution, dispatch
		// the task to the worker threads
		WRK_Dispatch(l_head->func, l_head->arg);

		// free list node
		tmp = l_head;
		l_head = l_head->next;
		MTX_Unlock(l_mtx);
		MEM_Free(tmp);
	}
}

void SCH_Init()
{
	l_head = NULL;
	l_listSize = 0;
	MTX_Create(&l_mtx);
	COND_Create(&l_cond);

	// spawn scheduler
	l_exit = 0;
	if(THR_Create(&l_thr, Scheduler, NULL))
		SYS_Error("SCH_Init: Failed to spawn scheduler thread!");
}

void SCH_Cleanup()
{
	SchEntry *it, *tmp;

	// kill scheduler
	MTX_Lock(l_mtx);
	l_exit = 1;
	COND_Signal(l_cond);
	MTX_Unlock(l_mtx);

	THR_Join(l_thr);

	// cleanup
	MTX_Destroy(l_mtx);
	COND_Destroy(l_cond);
	it = l_head;
	while(it){
		tmp = it;
		it = it->next;
		MEM_Free(tmp);
	}
}

SchEntry *SCH_Add(uint32_t delay, void (* func)(void *), void *arg)
{
	uint32_t time;
	SchEntry *entry;
	SchEntry **it;

	time = SYS_GetTickCount() + delay;
	entry = MEM_Alloc(sizeof(SchEntry));
	entry->time = time;
	entry->func = func;
	entry->arg = arg;
	entry->next = NULL;

	MTX_Lock(l_mtx);
	if(l_listSize >= MAX_LIST_SIZE){
		MTX_Unlock(l_mtx);
		MEM_Free(entry);
		LOG_ERROR("SCH_Add: Scheduler entry list is at maximum capacity!");
		return NULL;
	}

	// sort entries by execution time
	// using a double pointer for iteration
	it = &l_head;
	while(*it && time >= (*it)->time)
		it = &(*it)->next;

	if(*it)
		entry->next = (*it);

	*it = entry;
	//

	if(entry == l_head)
		COND_Signal(l_cond);

	++l_listSize;
	MTX_Unlock(l_mtx);

	return entry;
}

void SCH_Remove(SchEntry *entry)
{
	SchEntry **it;

	MTX_Lock(l_mtx);
	it = &l_head;
	while(*it && *it != entry)
		it = &(*it)->next;

	if(*it == entry){
		*it = (*it)->next;
		--l_listSize;
		MTX_Unlock(l_mtx);
		MEM_Free(entry);
	}
	else{
		MTX_Unlock(l_mtx);
		LOG_ERROR("SCH_Remove: Trying to remove invalid scheduler entry!");
	}
}

#if 0

static SchEntry *SCH_Next()
{
	SchEntry *entry;

	MTX_Lock(l_mtx);
	entry = l_head;
	if(entry == NULL || entry->time > SYS_GetTickCount()){
		MTX_Unlock(l_mtx);
		return NULL;
	}
	l_head = entry->next;
	entry->next = NULL;
	--l_listSize;
	MTX_Unlock(l_mtx);
	return entry;
}

#endif