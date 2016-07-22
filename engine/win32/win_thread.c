#include "../thread.h"
#include "../mem.h"
#include "../log.h"

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <process.h>


// Thread
// ==================
typedef struct Thread{
	HANDLE handle;
	void (*fp)(void *);
	void *arg;
} Thread;

static unsigned __stdcall ThreadWrapper(void *arg)
{
	Thread *thr = arg;
	if(thr == NULL)
		return -1;

	thr->fp(thr->arg);
	return 0;
}

int THR_Create(Thread **thr, void (*fp)(void *), void *arg)
{
	(*thr) = (Thread*)MEM_Alloc(sizeof(Thread));
	if(!(*thr))
		return -1;

	(*thr)->fp = fp;
	(*thr)->arg = arg;
	(*thr)->handle = (HANDLE)_beginthreadex(NULL, 0, ThreadWrapper, (*thr), 0, NULL);
	if((*thr)->handle == NULL){
		LOG_ERROR("THR_Create: Failed to create thread! (%d)", errno);
		return -1;
	}

	return 0;
}

int THR_Destroy(Thread *thr)
{
	// check if thread has completed
	if(WaitForSingleObject(thr->handle, 0) != WAIT_OBJECT_0){
		LOG_ERROR("THR_Destroy: Trying to destroy thread still running! (%X)", GetLastError());
		return -1;
	}

	CloseHandle(thr->handle);
	MEM_Free(thr);
	return 0;
}

int THR_Join(Thread *thr)
{
	if(WaitForSingleObject(thr->handle, INFINITE) == WAIT_FAILED){
		LOG_ERROR("THR_Join: Failed to join thread! (%X)", GetLastError());
		return -1;
	}

	return 0;
}


// Mutex
// ==================
typedef struct Mutex {
	CRITICAL_SECTION handle;
} Mutex;

void MTX_Create(Mutex **mtx)
{
	*mtx = (Mutex*) MEM_Alloc(sizeof(Mutex));
	InitializeCriticalSection(&(*mtx)->handle);
}

void MTX_Destroy(Mutex *mtx)
{
	DeleteCriticalSection(&mtx->handle);
	MEM_Free(mtx);
}

void MTX_Lock(Mutex *mtx)
{
	EnterCriticalSection(&mtx->handle);
}

void MTX_Unlock(Mutex *mtx)
{
	LeaveCriticalSection(&mtx->handle);
}


// Condition Variable
// ==================
typedef struct CondVar{
	CONDITION_VARIABLE handle;
} CondVar;

void COND_Create(CondVar **cond)
{
	*cond = MEM_Alloc(sizeof(CondVar));
	InitializeConditionVariable(&(*cond)->handle);
}

void COND_Destroy(CondVar *cond)
{
	MEM_Free(cond);
}

void COND_Wait(CondVar *cond, Mutex *mtx)
{
	SleepConditionVariableCS(&cond->handle, &mtx->handle, INFINITE);
}

void COND_TimedWait(CondVar *cond, Mutex *mtx, uint32_t msec)
{
	SleepConditionVariableCS(&cond->handle, &mtx->handle, msec);
}

void COND_Signal(CondVar *cond)
{
	WakeConditionVariable(&cond->handle);
}

void COND_Broadcast(CondVar *cond)
{
	WakeAllConditionVariable(&cond->handle);
}