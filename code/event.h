#ifndef __EVENT_H__
#define __EVENT_H__

#include "types.h"

typedef enum EventID{
	EVENT_KEY = 0,		// combined keyboard keys and mouse keys
	EVENT_MOUSE,		// mouse motion
	EVENT_TEXT,			// WM_CHAR on windows -> (?) on linux

	EVENT_NETWORK,

	EVENT_SYSTEM,
	EVENT_SYSRESIZE,	// resize and close might be the only relevant messages to the whole
						// program. the others can be handled from within the window proc.
	EVENT_SYSCLOSE
	
} EventID;

/*

EVENT_KEY:
* param1 = state of the key (pressed = 1 or released = 0)
* param2 = key pressed

EVENT_MOUSE:
* param1 = mouse mode (relative = 1 or absolute = 0)
* param2 = x
* param3 = y

EVENT_NETWORK:
* param1 = message index from the incoming message pool

EVENT_SYSTEM:
(maybe split this into the others)
* param1 = system event id

*/

typedef struct Event{
	EventID id;
	uint32_t param1;
	uint32_t param2;
	uint32_t param3;
} Event;

void	EV_Init();
void	EV_Cleanup();

void	EV_Add(EventID id, uint32_t param1, uint32_t param2, uint32_t param3);

void	EV_Dump();

#endif //__EVENT_H__