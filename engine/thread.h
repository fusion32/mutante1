#ifndef __THREAD_H__
#define __THREAD_H__

#include "types.h"

// Thread
// ==================
typedef struct Thread Thread;

int			THR_Create(Thread **thr, void (*fp)(void *), void *arg);
int			THR_Destroy(Thread *thr);

int			THR_Join(Thread *thr);

// Mutex
// ==================
typedef struct Mutex Mutex;

void		MTX_Create(Mutex **mtx);
void		MTX_Destroy(Mutex *mtx);

void		MTX_Lock(Mutex *mtx);
void		MTX_Unlock(Mutex *mtx);

// Condition Variable
// ==================
typedef struct CondVar CondVar;

void		COND_Create(CondVar **cond);
void		COND_Destroy(CondVar *cond);

void		COND_Wait(CondVar *cond, Mutex *mtx);
void		COND_TimedWait(CondVar *cond, Mutex *mtx, uint32_t msec);
void		COND_Signal(CondVar *cond);
void		COND_Broadcast(CondVar *cond);

#endif //__THREAD_H__