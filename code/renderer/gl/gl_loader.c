#include "gl_loader.h"

#include "../../log.h"
#include "../../mem.h"
#include "../../system.h"

#include <string.h>
#include <stdio.h>

#define GL_MAX_EXTENSION_COUNT 1024

//
GLInfo gl_info;

//
static GLboolean l_loaded = GL_FALSE;

static GLuint l_extensionCount;
static const char *l_pExtensions[GL_MAX_EXTENSION_COUNT];


//
// OpenGL function decl here
//

typedef void (*PFNGLVOIDFUNCTION)(void);

#if defined(_WIN32)
static HMODULE l_libgl = NULL;
static GLboolean GL_OpenLib()
{
	l_libgl = LoadLibraryA("opengl32.dll");
	return l_libgl != NULL;
}
static void GL_CloseLib()
{
	FreeLibrary(l_libgl);
}
static GLboolean GL_IsLibOpen()
{
	return (l_libgl != NULL);
}
static PFNGLVOIDFUNCTION GL_GetProcAddr(const char *procName)
{
	PFNGLVOIDFUNCTION proc;

	proc = (PFNGLVOIDFUNCTION) wglGetProcAddress((LPCSTR)procName);
	if(proc == NULL)
		proc = (PFNGLVOIDFUNCTION) GetProcAddress(l_libgl, (LPCSTR)procName);

	return proc;
}
#endif


GLboolean GL_LoadAPI()
{
	const char *version;
	uint32_t i, res;

	if(l_loaded)
		return GL_TRUE;

	// clear gl_info
	memset(&gl_info, 0, sizeof(GLInfo));

	// get version
	version = glGetString(GL_VERSION);
	if(version == NULL){
		LOG_ERROR("GL_LoadAPI: Failed to fetch version string! Maybe the context was not properly created.");
		return GL_FALSE;
	}

	if(sscanf(version, "%d.%d", &gl_info.majorVersion, &gl_info.minorVersion) != 2){
		LOG_ERROR("GL_LoadAPI: Invalid OpenGL version string! Maybe the context was not properly created.");
		return GL_FALSE;
	}

	if(gl_info.majorVersion < 3 || gl_info.majorVersion == 3 && gl_info.minorVersion < 3){
		LOG_ERROR("GL_LoadAPI: OpenGL 3.3 is not supported! Updating your drivers may solve the problem.");
		return GL_FALSE;
	}

	LOG("OpenGL Version: %d.%d", gl_info.majorVersion, gl_info.minorVersion);


	glGetIntegerv(GL_NUM_EXTENSIONS, &l_extensionCount);
	for(i = 0; i < l_extensionCount; ++i)
		l_pExtensions[i] = glGetStringi(GL_EXTENSIONS, i);

	// Load OpenGL Core
	//=================================================================
	#define GL_GET_PROC_ADDR(proc_type, proc_name)									\
		proc_name = (proc_type) GL_GetProcAddr(#proc_name);							\
		if(proc_name == NULL){														\
			LOG_ERROR("GL_LoadAPI: Failed to load core function: %s!", #proc_name);	\
			res = GL_FALSE;															\
		}

	res = GL_TRUE;
	GL_GET_PROC_ADDR(PFNGLTEXIMAGE3DPROC, glTexImage3D);

	#undef GL_GET_PROC_ADDR
	//=================================================================

	// Load OpenGL Extensions
	//=================================================================
	//=================================================================



	l_loaded = GL_TRUE;
	return GL_TRUE;
}
