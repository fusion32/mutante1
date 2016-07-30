#include "r_local.h"
#include "../system.h"

void R_Init()
{
	if(GL_Init() == false)
		SYS_Error("R_Init: Failed to initialize renderer!");

	// if unable to load any renderer just call SYS_Error
	// and terminate execution
}

void R_Cleanup()
{
	GL_Cleanup();
}