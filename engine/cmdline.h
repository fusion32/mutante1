#ifndef __CMDLINE_H__
#define __CMDLINE_H__

#include "types.h"

typedef enum CommandID{
	CMD_HELP		= 0,
	CMD_NOLOG,
	CMD_FULLSCREEN,
	CMD_WIDTH,
	CMD_HEIGHT,

	CMD_VULKAN,
	CMD_OPENGL,
	CMD_D3D9,
} CommandID;

void		CMD_Parse(int argc, char **argv);
void		CMD_Usage();

int32_t		CMD_GetValue(CommandID cmd);

#endif //__CMDLINE_H__