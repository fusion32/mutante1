#include "cmdline.h"

#include "util.h"

#include <stdio.h>
#include <string.h>
#include <assert.h>

typedef struct CommandDesc {
	const char *str;
	CommandID cmd;
} CommandDesc;

// usage string
static const char l_usageStr[] =
	"Options\n"
	"\t-help\t\t\tDisplay this help message\n"
	"\t-nolog\t\t\tDisable log saving\n"
	"\t-width=<value>\t\tOverride the width in the config file with <value>\n"
	"\t-height=<value>\t\tOverride the height in the config file with <value>\n"
	"\n"
	"\t<Renderer> NOTE: these are mutually exclusive. Priority from top to bottom\n"
	"\t-vulkan\t\t\tUse the Vulkan renderer\n"
	"\t-opengl\t\t\tUse the OpenGL renderer\n"
	"\t-d3d9\t\t\tUse the Direct3D 9 renderer\n";

// command list
static CommandDesc l_cmdList[] = {
	{"help",		CMD_HELP},
	{"nolog",		CMD_NOLOG},
	{"fullscreen",	CMD_FULLSCREEN},
	{"width",		CMD_WIDTH},
	{"height",		CMD_HEIGHT},

	// these are mutually exclusive
	{"vulkan",		CMD_VULKAN},
	{"opengl",		CMD_OPENGL},
	{"d3d9",		CMD_D3D9},
};

#define CMD_MAX 32

static int32_t l_cmdValues[CMD_MAX];

void CMD_Parse(int argc, char **argv)
{
	uint32_t i, j;
	uint32_t valid;
	size_t len, arglen;
	const char *arg;
	const char *str;
	CommandID cmd;
	int32_t value;

	// set all values to zero
	for(i = 0; i < CMD_MAX; ++i)
		l_cmdValues[i] = 0;

	// skip first argument
	for(i = 1; i < argc; ++i){
		valid = 0;
		arg = argv[i];

		if(*arg == '-'){
			++arg;

			for(j = 0; j < ARRAYSIZE(l_cmdList) && !valid; ++j){
				str = l_cmdList[j].str;
				cmd = l_cmdList[j].cmd;

				len = strlen(str);
				arglen = strlen(arg);
				if(len > arglen || strncmp(str, arg, len) != 0)
					continue;

				if(len == arglen){
					l_cmdValues[cmd] = 1;
					valid = 1;
				}

				// assert there is actually something after the '=' sign
				else if(arg[len] == '=' && (arglen - len - 1) > 0){

					if(sscanf(&arg[len + 1], "%d", &value) == 1){
						l_cmdValues[cmd] = value;
						valid = 1;
					}
				}
			}
		}

		if(!valid)
			printf("<WARNING> Invalid command line option '%s'. Use -help for options.\n", argv[i]);
	}

	// check if width and height were set
	if(l_cmdValues[CMD_WIDTH] || l_cmdValues[CMD_HEIGHT]){
		if(!l_cmdValues[CMD_WIDTH]){
			printf("<WARNING> -height: Height being set without a width! Ignoring command.\n");
			l_cmdValues[CMD_HEIGHT] = 0;
		}

		if(!l_cmdValues[CMD_HEIGHT]){
			printf("<WARNING> -width: Width being set without a height! Ignoring command.\n");
			l_cmdValues[CMD_WIDTH] = 0;
		}
	}

	// check if more than one renderer was selected
	if(l_cmdValues[CMD_VULKAN]){
		if(l_cmdValues[CMD_OPENGL])
			printf("<WARNING> -opengl: Vulkan renderer already selected! For renderer priority use -help.\n");

		if(l_cmdValues[CMD_D3D9])
			printf("<WARNING> -d3d9: Vulkan renderer already selected! For renderer priority use -help.\n");

		//l_cmdValues[CMD_OPENGL] = 0;
		//l_cmdValues[CMD_D3D9] = 0;
	}
	else if(l_cmdValues[CMD_OPENGL]){
		if(l_cmdValues[CMD_D3D9])
			printf("<WARNING> -d3d9: OpenGL renderer already selected! For renderer priority use -help.\n");

		//l_cmdValues[CMD_D3D9] = 0;
	}
}

void CMD_Usage()
{
	printf(l_usageStr);
}

int32_t CMD_GetValue(CommandID cmd)
{
#ifdef _DEBUG
	assert(cmd >= 0 && cmd < CMD_MAX);
#endif
	return l_cmdValues[cmd];
}