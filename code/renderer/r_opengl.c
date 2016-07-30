#include "gl/gl_loader.h"

#include "../types.h"
#include "../log.h"

/*
typedef enum RCommandID{
	COMMAND_UNKNOWN = 0,
	COMMAND_COPY_BUFFER,
	COMMAND_BIND_VERTEX_BUFFER,
	COMMAND_BIND_INDEX_BUFFER,
	COMMAND_BIND_PIPELINE,
	COMMAND_DRAW_INDEXED,

	// we might not even need these
	// because opengl doesn't have
	// render passes BUT still we'll
	// have to include the functions
	// for vulkan

	// vulkan = call vulkan api
	// opengl = do nothing
	COMMAND_PIPELINE_BARRIER,
	COMMAND_BEGIN_RENDER_PASS,
	COMMAND_END_RENDER_PASS,
	COMMAND_NEXT_SUBPASS,
} RCommandID;

typedef struct RCommand{
	RCommandID id;
	// command params
} RCommand;

// it might be better to use a linked list
// and alocate command buffers on the fly (?)

#define MAX_COMMANDS 256
typedef struct RCommandBuffer{
	RCommand buffer[MAX_COMMANDS];
} RCommandBuffer;
*/

// OpenGL Context
// =========================================================
static GLboolean l_ctxReady = GL_FALSE;

#if defined(_WIN32)
#include "../win32/win32.h"

static HWND		l_window;
static HDC		l_dc;
static HGLRC	l_glContext;

static GLboolean GL_CreateContext()
{
	PIXELFORMATDESCRIPTOR pfd;
	int format;

	if (l_ctxReady == GL_TRUE)
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
	if (l_dc == NULL) {
		LOG_ERROR("GL_CreateContext: Failed to retrieve device context! (%X)", GetLastError());
		return GL_FALSE;
	}

	format = ChoosePixelFormat(l_dc, &pfd);
	SetPixelFormat(l_dc, format, &pfd);
	l_glContext = wglCreateContext(l_dc);
	if (l_glContext == NULL) {
		ReleaseDC(l_window, l_dc);
		LOG_ERROR("GL_CreateContext: Failed to create OpenGL context! (%X)", GetLastError());
		return GL_FALSE;
	}

	l_ctxReady = GL_TRUE;
	return GL_TRUE;
}

void GL_DestroyContext()
{
	if (l_ctxReady == GL_TRUE) {
		wglDeleteContext(l_glContext);
		ReleaseDC(l_window, l_dc);
	}
}

GLboolean GL_AcquireContext()
{
	if (wglMakeCurrent(l_dc, l_glContext) == FALSE) {
		LOG_ERROR("GL_AcquireContext: Failed to make OpenGL context current! (%X)", GetLastError());
		return GL_FALSE;
	}

	return GL_TRUE;
}

GLboolean GL_ReleaseContext()
{
	if (wglMakeCurrent(NULL, NULL) == FALSE) {
		LOG_ERROR("GL_ReleaseContext: Failed to release OpenGL context! (%X)", GetLastError());
		return GL_FALSE;
	}

	return GL_TRUE;
}
#endif
// =========================================================


bool GL_Init()
{
	if(GL_CreateContext() == GL_FALSE ||
			GL_AcquireContext() == GL_FALSE ||
			GL_LoadAPI() == GL_FALSE ||
			GL_ReleaseContext() == GL_FALSE)
		return false;

	// create render thread
	// render thread needs to acquire context

	return true;
}

void GL_Cleanup()
{
	// signal the render thread to release context and finish
	// join render thread
	GL_DestroyContext();
}