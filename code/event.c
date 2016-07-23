#include "event.h"

// events to consider:
//	* keyboard/mouse input
//	* network messages
//	* system messages (resolution change, setting change, whatever the fuck)
//	* scheduled events ()

// work:
//	* render work (build command buffers, submit command buffers, ...)
//	* physics work (movement and shit)
//	* gameplay work (logic, AI and shit)
//	* system updates (resolution change, setting change, ...)
//	* I/O dispatch (keyboard, mouse, network, ...)

// worker threads:
//	* check for scheduled events
//	* check for events
//	* check for work


// events from the keyboard/mouse are sent to the i/o parser
//	EV_Dispatch(Event)

#include "thread.h"
#include "scheduler.h"
#include "log.h"
#include "system.h"


#include <string.h>

// The l_eventPool will work as a ring buffer
// 1024 should be enough for reliability
#define MAX_EVENTS 1024

static Event l_eventPool[MAX_EVENTS];
static uint32_t l_readPos;
static uint32_t l_writePos;
static uint32_t l_pendingEvents;

static Thread *l_thr;
static Mutex *l_mtx;
static CondVar *l_cond;
static uint32_t l_exit;

static void EventHandler(void *unused)
{
	Event *ev;
	while(!l_exit){
		MTX_Lock(l_mtx);
		// if the ring buffer is empty, wait
		// indefinitely for a new event
		if(l_pendingEvents == 0){
			COND_Wait(l_cond, l_mtx);

			if(l_pendingEvents == 0){
				MTX_Unlock(l_mtx);
				continue;
			}
		}

		ev = &l_eventPool[l_readPos];
		++l_readPos;
		if(l_readPos >= MAX_EVENTS)
			l_readPos = 0;

		--l_pendingEvents;
		MTX_Unlock(l_mtx);

		// parse which event we are currently handling
		// and call the apropriate interface handler
		// e.g.
		// - InputManager (mouse / keyboard)
		// - NetworkInput (network)
		// - Renderer (resize)
		// - "are you sure you want to quit? bla bla bla" whatever the fuck handler (close)

		// NOTE: these should be lightweight as we have a single dedicated thread to handle
		// all events! the interface handlers should receive the events, parse it as fast as
		// possible and dispatch any work to the worker threads

		// NOTE: while debugging we might as well save the events log to trace the bug.

		LOG_DEBUG("Event -> id: %d, param1: %d, param2: %d, param3: %d", ev->id, ev->param1, ev->param2, ev->param3);
	}
}

void EV_Init()
{
	// init vars
	l_readPos = 0;
	l_writePos = 0;
	l_pendingEvents = 0;
	MTX_Create(&l_mtx);
	COND_Create(&l_cond);

	// spawn handler
	l_exit = 0;
	if(THR_Create(&l_thr, EventHandler, NULL))
		SYS_Error("EV_Init: failed to spawn handler thread!");
}

void EV_Cleanup()
{
	// kill handler
	MTX_Lock(l_mtx);
	l_exit = 1;
	COND_Signal(l_cond);
	MTX_Unlock(l_mtx);

	THR_Join(l_thr);

	// cleanup
	MTX_Destroy(l_mtx);
	COND_Destroy(l_cond);
}

void EV_Add(EventID id, uint32_t param1, uint32_t param2, uint32_t param3)
{
	Event entry = {
		.id = id,
		.param1 = param1,
		.param2 = param2,
		.param3 = param3
	};

	MTX_Lock(l_mtx);
	if(l_pendingEvents >= MAX_EVENTS){
		MTX_Unlock(l_mtx);
		LOG_ERROR("Event ring buffer is at maximum capacity!");
		return;
	}

	memcpy(&l_eventPool[l_writePos], &entry, sizeof(Event));
	++l_writePos;
	if(l_writePos >= MAX_EVENTS)
		l_writePos = 0;
	++l_pendingEvents;
	COND_Signal(l_cond);
	MTX_Unlock(l_mtx);
}

static Event *EV_Next()
{
	Event *ev;
	MTX_Lock(l_mtx);
	if(l_pendingEvents == 0){
		MTX_Unlock(l_mtx);
		return NULL;
	}

	ev = &l_eventPool[l_readPos];
	++l_readPos;
	if(l_readPos >= MAX_EVENTS)
		l_readPos = 0;

	--l_pendingEvents;
	MTX_Unlock(l_mtx);
	return ev;
}

void EV_Dump()
{
	Event *ev;
	while((ev = EV_Next()))
		LOG_DEBUG("Event -> id: %d, param1: %d, param2: %d, param3: %d", ev->id, ev->param1, ev->param2, ev->param3);
}

// EV_Add(EVENT_KEY, 1, key, 0); // KEY_DOWN
// EV_Add(EVENT_KEY, 0, key, 0); // KEY_UP
// EV_Add(EVENT_MOUSE, l_mouseRelative, x, y); // MOUSE
// EV_Add(EVENT_TEXT, ch, 0, 0); // TEXT

// since incoming messages will be already on the incoming
// messages pool, we don't need to do anything else but
// process the message

// EV_Add(EVENT_NETWORK, msg_id, 0, 0); // NETWORK

// EV_Add(EVENT_SYSRESIZE, width, height, 0); // SYSRESIZE
// EV_Add(EVENT_SYSCLOSE, 0, 0, 0); // SYSCLOSE

// EV_Schedule()