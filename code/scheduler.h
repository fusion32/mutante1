#ifndef __SCHEDULER_H__
#define __SCHEDULER_H__

#include "types.h"

typedef struct SchEntry SchEntry;


void		SCH_Init();
void		SCH_Cleanup();

SchEntry	*SCH_Add(uint32_t delay, void (* func)(void *), void *arg);
void		SCH_Remove(SchEntry *entry);

#endif //__SCHEDULER_H__