#ifndef __WIN32_H__
#define __WIN32_H__

#include "../types.h"

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

void		WIN32_Init();
void		WIN32_Cleanup();

void		WIN32_CreateWindow();
void		WIN32_DestroyWindow();

void		WIN32_DispatchEvents();

HINSTANCE	WIN32_GetInstanceHandle();
HWND		WIN32_GetWindowHandle();
void		WIN32_GetWindowExtent(uint32_t *width, uint32_t *height);

#endif //__WIN32_H__