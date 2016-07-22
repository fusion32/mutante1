#include "renderer.h"

#include "gl/gl_loader.h"

void GL_CreateContext();
void GL_DestroyContext();

void R_Init()
{
	GL_CreateContext();
	GL_LoadAPI();
}

void R_Cleanup()
{
	GL_DestroyContext();
}