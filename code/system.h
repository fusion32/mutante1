#ifndef __SYSTEM_H__
#define __SYSTEM_H__

#include "types.h"

void SYS_Error(const char *fmt, ...);
void SYS_Exit(int code);
uint32_t SYS_GetTickCount();
uint32_t SYS_GetCPUCount();

#endif //__SYSTEM_H__