#include "mem.h"
#include "system.h"

#include <stdlib.h>

void *MEM_Alloc(size_t size)
{
	void *ptr = malloc(size);
	if(!ptr)
		SYS_Error("Allocation failure!");

	return ptr;
}

void MEM_Free(void *ptr)
{
	free(ptr);
}

