#define VK_USE_PLATFORM_WIN32_KHR
#include "../win32/win32.h"
#include "../log.h"

#include "vulkan/vk_loader.h"
#include "gl/gl_loader.h"

// /!\/!\/!\/!\/!\/!\/!\/!\
//
// NOTE: maybe transfer these to vk_loader and gl_loader respectively
//
// /!\/!\/!\/!\/!\/!\/!\/!\



// Vulkan Surface
// ==============
const char *VK_SYS_SURFACE_EXTENSION_NAME = VK_KHR_WIN32_SURFACE_EXTENSION_NAME;

static PFN_vkCreateWin32SurfaceKHR fpCreateWin32SurfaceKHR = NULL;

VkBool32 VK_GetCreateSurfaceProcAddr(VkInstance instance)
{
	fpCreateWin32SurfaceKHR = (PFN_vkCreateWin32SurfaceKHR) vkGetInstanceProcAddr(instance, "vkCreateWin32SurfaceKHR");
	if(fpCreateWin32SurfaceKHR == NULL){
		LOG_ERROR("VK_GetCreateSurfaceProcAddr: Failed to load vkCreateWin32SurfaceKHR from dll!");
		return VK_FALSE;
	}

	return VK_TRUE;
}

VkResult VK_CreateSurface(VkInstance instance, VkSurfaceKHR *pSurface)
{
	HWND hwnd;
	HINSTANCE hinstance;
	VkResult res;

	if(fpCreateWin32SurfaceKHR == NULL)
		return VK_NOT_READY;

	hwnd = WIN32_GetWindowHandle();
	hinstance = GetModuleHandle(NULL);
	VkWin32SurfaceCreateInfoKHR createInfo = {
		.sType = VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR,
		.pNext = NULL,
		.flags = 0,
		.hinstance = hinstance,
		.hwnd = hwnd
	};

	res = fpCreateWin32SurfaceKHR(instance, &createInfo, NULL, pSurface);
	return res;
}


// OpenGL Context
// ==============
static HWND		l_window;
static HDC		l_dc;
static HGLRC	l_glContext;

static GLboolean l_ctxCreated = GL_FALSE;

GLboolean GL_CreateContext()
{
	PIXELFORMATDESCRIPTOR pfd;
	int format;

	if(l_ctxCreated == GL_TRUE)
		return GL_TRUE;

	memset(&pfd, 0, sizeof(PIXELFORMATDESCRIPTOR));
	pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 24;
	pfd.cDepthBits = 16;
	pfd.iLayerType = PFD_MAIN_PLANE;

	l_window = WIN32_GetWindowHandle();
	l_dc = GetDC(l_window);
	if(l_dc == NULL){
		LOG_ERROR("GL_CreateContext: Failed to retrieve device context! (%X)", GetLastError());
		return GL_FALSE;
	}

	format = ChoosePixelFormat(l_dc, &pfd);
	SetPixelFormat(l_dc, format, &pfd);
	l_glContext = wglCreateContext(l_dc);
	if(l_glContext == NULL){
		ReleaseDC(l_window, l_dc);
		LOG_ERROR("GL_CreateContext: Failed to create OpenGL context! (%X)", GetLastError());
		return GL_FALSE;
	}

	if(wglMakeCurrent(l_dc, l_glContext) == FALSE){
		wglDeleteContext(l_glContext);
		ReleaseDC(l_window, l_dc);
		LOG_ERROR("GL_CreateContext: Failed to make OpenGL context current! (%X)", GetLastError());
		return GL_FALSE;
	}

	l_ctxCreated = GL_TRUE;
	return GL_TRUE;
}

void GL_DestroyContext()
{
	if(l_ctxCreated == GL_TRUE){
		wglMakeCurrent(NULL, NULL);
		wglDeleteContext(l_glContext);
		ReleaseDC(l_window, l_dc);
	}
}