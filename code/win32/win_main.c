#include "../types.h"

// include interfaces
#include "../cmdline.h"
#include "../log.h"
#include "../event.h"
#include "../scheduler.h"
#include "../work.h"
#include "win32.h"

#include "../renderer/renderer.h"

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void SYS_Error(const char *fmt, ...)
{
	char errMessage[256];
	va_list ap;

	va_start(ap, fmt);
	vsnprintf(errMessage, 256, fmt, ap);
	va_end(ap);

	LOG("SYSTEM ERROR");
	LOG_ERROR(errMessage);
	exit(-1);
}

void SYS_Exit(int code)
{
	LOG("SYSTEM EXIT (%d)", code);
	exit(code);
}

uint32_t SYS_GetTickCount()
{
	return GetTickCount();
}

uint32_t SYS_GetCPUCount()
{
	SYSTEM_INFO info;
	GetSystemInfo(&info);
	return info.dwNumberOfProcessors;
}

int main(int argc, char **argv)
{
	// parse command line
	CMD_Parse(argc, argv);

	if(CMD_GetValue(CMD_HELP)){
		CMD_Usage();
		return 0;
	}

	// init state machine
	//

	// init log asap to output errors
	// other interfaces may have
	LOG_Init();

	// init interfaces
	WRK_Init();
	SCH_Init();
	EV_Init();

	// create window
	WIN32_Init();

	// init renderer
	R_Init();

	// program loop
	// while(!EV_QuitEvent())
	while(1){
		WIN32_DispatchEvents();
		// do work
	}

	// stop renderer
	R_Cleanup();

	// destroy window
	WIN32_Cleanup();

	// save any config, state or w/e
	//CFG_Save();

	// cleanup interfaces
	EV_Cleanup();
	SCH_Cleanup();
	WRK_Cleanup();

	// cleanup console last so we can
	// log until we exit
	LOG_Cleanup();
	return 0;
}