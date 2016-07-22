#include "work.h"
#include "thread.h"
#include "system.h"
#include "event.h"
#include "scheduler.h"
#include "log.h"

#include <string.h>

// l_workPool will work as a ring buffer
// 1024 should be enough to be reliable
#define MAX_WORK 1024

typedef struct Work{
	uint32_t complete;
	void (*fp)(void *);
	void *arg;
} Work;

static Work l_workPool[MAX_WORK];
static uint32_t l_readPos;
static uint32_t l_writePos;
static uint32_t l_pendingWork;
static Mutex *l_mtx;
static CondVar *l_cond;

// Number of concurrent worker threads will depend
// on the system number of cores! Too many threads
// doing the same thing on a single core CPU will
// actually decrease the performance.
#define MAX_THREADS 2

static Thread *l_threadPool[MAX_THREADS];
static uint32_t l_exitSignal[MAX_THREADS];
static uint32_t l_numThreads;

static void WorkerThread(void *ptr)
{
	Work *wrk;
	uint32_t *exit;

	exit = ptr;
	while(!*exit){
		MTX_Lock(l_mtx);
		if(l_pendingWork == 0){
			COND_Wait(l_cond, l_mtx);

			if(l_pendingWork == 0){
				MTX_Unlock(l_mtx);
				continue;
			}
		}

		wrk = &l_workPool[l_readPos];
		++l_readPos;
		if(l_readPos >= MAX_WORK)
			l_readPos = 0;
		--l_pendingWork;
		MTX_Unlock(l_mtx);

		// execute work
		wrk->fp(wrk->arg);
		wrk->complete = 1;
	}
}

void WRK_Init()
{
	uint32_t i;

	l_readPos = 0;
	l_writePos = 0;
	l_pendingWork = 0;
	MTX_Create(&l_mtx);
	COND_Create(&l_cond);

	i = SYS_GetCPUCount();
	if(i > MAX_THREADS)
		l_numThreads = MAX_THREADS;

	for(i = 0; i < l_numThreads; ++i){
		l_exitSignal[i] = 0;
		if(THR_Create(&l_threadPool[i], WorkerThread, &l_exitSignal[i]) != 0)
			SYS_Error("WRK_Init: Failed to spawn worker thread!");
	}
}

void WRK_Cleanup()
{
	uint32_t i;
	MTX_Lock(l_mtx);
	for(i = 0; i < l_numThreads; ++i)
		l_exitSignal[i] = 1;
	COND_Broadcast(l_cond);
	MTX_Unlock(l_mtx);

	for(i = 0; i < l_numThreads; ++i)
		THR_Join(l_threadPool[i]);

	MTX_Destroy(l_mtx);
	COND_Destroy(l_cond);
}

uint32_t *WRK_Dispatch(void (*fp)(void *), void *arg)
{
	uint32_t *complete;
	Work wrk = {
		.complete = 0,
		.fp = fp,
		.arg = arg
	};

	MTX_Lock(l_mtx);
	if(l_pendingWork >= MAX_WORK){
		MTX_Unlock(l_mtx);
		LOG_ERROR("Work ring buffer is at maximum capacity!");
		return NULL;
	}

	memcpy(&l_workPool[l_writePos], &wrk, sizeof(Work));
	complete = &l_workPool[l_writePos].complete;
	++l_writePos;
	if(l_writePos >= MAX_WORK)
		l_writePos = 0;
	++l_pendingWork;
	COND_Signal(l_cond);
	MTX_Unlock(l_mtx);
	return complete;
}

#if 0

static Work *WRK_Next()
{
	Work *wrk;

	MTX_Lock(l_mtx);
	if(l_pendingWork == 0){
		MTX_Unlock(l_mtx);
		return NULL;
	}

	wrk = &l_workPool[l_readPos];
	++l_readPos;
	if(l_readPos >= MAX_WORK)
		l_readPos = 0;
	--l_pendingWork;
	MTX_Unlock(l_mtx);
	return wrk;
}

#endif
