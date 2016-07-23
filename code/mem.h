#ifndef __MEM_H__
#define __MEM_H__

#include "types.h"

void *MEM_Alloc(size_t size);
void MEM_Free(void *ptr);

#endif //__MEM_H__