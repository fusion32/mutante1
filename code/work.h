#ifndef __WORK_H__
#define __WORK_H__

#include "types.h"

typedef struct Work Work;

void WRK_Init();
void WRK_Cleanup();

uint32_t *WRK_Dispatch(void (*fp)(void *), void *arg);

#endif //__WORK_H__