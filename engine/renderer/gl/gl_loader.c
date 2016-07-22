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
#define GL_CORE_PROC(proc_type, proc_name) proc_type proc_name = NULL;
#define GL_EXT_PROC(proc_type, proc_name) proc_type proc_name = NULL;
#include "gl_loader.inl"

typedef void (*PFNGLVOIDFUNCTION)(void);

#ifdef _WIN32
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

static PFNGLVOIDFUNCTION GL_GetProcAddr(const char *procName)
{
	PFNGLVOIDFUNCTION proc;

	proc = (PFNGLVOIDFUNCTION) wglGetProcAddress((LPCSTR)procName);
	if(proc == NULL)
		proc = (PFNGLVOIDFUNCTION) GetProcAddress(l_libgl, (LPCSTR)procName);

	return proc;
}
#endif

static GLboolean GL_LoadCore()
{
	GLboolean ret = GL_TRUE;

	#define GL_CORE_PROC(proc_type, proc_name)								\
		proc_name = (proc_type) GL_GetProcAddr(#proc_name);					\
		if(proc_name == NULL){												\
			LOG_ERROR("GL_LoadCore: Failed to load " #proc_name "!");		\
			ret = GL_FALSE;													\
		}
	#include "gl_loader.inl"

	if(ret == GL_FALSE){
		#define GL_CORE_PROC(proc_type, proc_name) proc_name = NULL;
		#include "gl_loader.inl"
	}
	return GL_FALSE;
}

GLboolean GL_LoadAPI()
{
	const char *version;
	uint32_t i;

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

	if(GL_LoadCore() == GL_FALSE){
		LOG_ERROR("GL_LoadAPI: Unable to load OpenGL Core!");
		return GL_FALSE;
	}

	glGetIntegerv(GL_NUM_EXTENSIONS, &l_extensionCount);
	for(i = 0; i < l_extensionCount; ++i)
		l_pExtensions[i] = glGetStringi(GL_EXTENSIONS, i);


	l_loaded = GL_TRUE;
	return GL_TRUE;
}

/*

static const char *l_requiredExtensionsHIGH[] = {
	// for debugging (should not be required but should be activable)
	"GL_ARB_debug_output",

	// essential
	"GL_ARB_shader_draw_parameters",
	"GL_ARB_draw_indirect",
	"GL_ARB_multi_draw_indirect",

	"GL_ARB_direct_state_access",
	"GL_ARB_shader_storage_buffer_object",
	"GL_ARB_buffer_storage",
	"GL_ARB_texture_storage",
	"GL_ARB_separate_shader_objects",

	"GL_ARB_explicit_attrib_location",
	"GL_ARB_explicit_uniform_location",
	"GL_ARB_shading_language_420pack",
};

static const char *l_requiredExtensionsLOW[] = {
	// for debugging (should not be required but should be activable)
	"GL_ARB_debug_output",

	// essential
	"GL_ARB_sync",
	"GL_ARB_framebuffer_object",
	"GL_ARB_texture_storage",
	"GL_EXT_texture_array",

	"GL_ARB_explicit_attrib_location",
	"GL_ARB_explicit_uniform_location",
	"GL_ARB_shading_language_420pack",
};

*/