#include "glextensions.h"
#include "../../util.h"

#include <stdio.h>
#include <stdlib.h>

#define CHECK_RESULT(cond, format, ...)		\
	if(!(cond)){							\
		printf((format), __VA_ARGS__);		\
	}

#ifdef _WIN32
#define glGetProcAddress wglGetProcAddress
#define GET_WGL_PROC_ADDR(type, entrypoint)								\
	if(wgl##entrypoint == NULL){										\
		wgl##entrypoint = (type) glGetProcAddress("wgl" #entrypoint);	\
		CHECK_RESULT(wgl##entrypoint != NULL,							\
			"[error] Failed to find addr to wgl" #entrypoint "!\n");	\
	}

#else
#define glGetProcAddress
#define GET_GLX_PROC_ADDR(type, entrypoint)

#endif

#define GET_GL_PROC_ADDR(type, entrypoint)								\
	if(gl##entrypoint == NULL){											\
		gl##entrypoint = (type) glGetProcAddress("gl" #entrypoint);		\
		CHECK_RESULT(gl##entrypoint != NULL,							\
			"[error] Failed to find addr to gl" #entrypoint "!\n");		\
	}

// Essential extensions
// ====================

#ifdef _WIN32
// WGL_EXT_swap_control
PFNWGLSWAPINTERVALEXTPROC							wglSwapIntervalEXT = NULL;
PFNWGLGETSWAPINTERVALEXTPROC						wglGetSwapIntervalEXT = NULL;
#endif

#ifdef _DEBUG
// ARB_debug_output
PFNGLDEBUGMESSAGECONTROLPROC						glDebugMessageControl = NULL;
PFNGLDEBUGMESSAGECALLBACKPROC						glDebugMessageCallback = NULL;
#endif

// ARB_multitexture
PFNGLACTIVETEXTUREPROC								glActiveTexture = NULL;

// ARB_vertex_array_object
PFNGLDELETEVERTEXARRAYSPROC							glDeleteVertexArrays = NULL;
PFNGLGENVERTEXARRAYSPROC							glGenVertexArrays = NULL;
PFNGLBINDVERTEXARRAYPROC							glBindVertexArray = NULL;
PFNGLENABLEVERTEXATTRIBARRAYPROC					glEnableVertexAttribArray = NULL;
PFNGLDISABLEVERTEXATTRIBARRAYPROC					glDisableVertexAttribArray = NULL;
PFNGLVERTEXATTRIBPOINTERPROC						glVertexAttribPointer = NULL;

// ARB_vertex_buffer_object
PFNGLDELETEBUFFERSPROC								glDeleteBuffers = NULL;
PFNGLGENBUFFERSPROC									glGenBuffers = NULL;
PFNGLBINDBUFFERPROC									glBindBuffer = NULL;
PFNGLBUFFERDATAPROC									glBufferData = NULL;
PFNGLBUFFERSUBDATAPROC								glBufferSubData = NULL;
PFNGLMAPBUFFERPROC									glMapBuffer = NULL;
PFNGLUNMAPBUFFERPROC								glUnmapBuffer = NULL;

PFNGLMAPBUFFERRANGEPROC								glMapBufferRange = NULL;
PFNGLDRAWELEMENTSBASEVERTEXPROC						glDrawElementsBaseVertex = NULL;

// ARB_uniform_buffer_object
PFNGLBINDBUFFERBASEPROC								glBindBufferBase = NULL;
PFNGLBINDBUFFERRANGEPROC							glBindBufferRange = NULL;

// ARB_shader_objects
PFNGLDELETESHADERPROC								glDeleteShader = NULL;
PFNGLCREATESHADERPROC								glCreateShader = NULL;
PFNGLSHADERSOURCEPROC								glShaderSource = NULL;
PFNGLCOMPILESHADERPROC								glCompileShader = NULL;
PFNGLGETSHADERINFOLOGPROC							glGetShaderInfoLog = NULL;
PFNGLGETSHADERIVPROC								glGetShaderiv = NULL;

PFNGLDELETEPROGRAMPROC								glDeleteProgram = NULL;
PFNGLCREATEPROGRAMPROC								glCreateProgram = NULL;
PFNGLATTACHSHADERPROC								glAttachShader = NULL;
PFNGLDETACHSHADERPROC								glDetachShader = NULL;
PFNGLLINKPROGRAMPROC								glLinkProgram = NULL;
PFNGLUSEPROGRAMPROC									glUseProgram = NULL;
PFNGLGETPROGRAMINFOLOGPROC							glGetProgramInfoLog = NULL;
PFNGLGETPROGRAMIVPROC								glGetProgramiv = NULL;

PFNGLUNIFORM1IPROC									glUniform1i = NULL;
PFNGLUNIFORM1IVPROC									glUniform1iv = NULL;

// ARB_sampler_objects
PFNGLGENSAMPLERSPROC								glGenSamplers = NULL;
PFNGLDELETESAMPLERSPROC								glDeleteSamplers = NULL;
PFNGLBINDSAMPLERPROC								glBindSampler = NULL;
PFNGLSAMPLERPARAMETERIPROC							glSamplerParameteri = NULL;
PFNGLSAMPLERPARAMETERFPROC							glSamplerParameterf = NULL;
PFNGLSAMPLERPARAMETERIVPROC							glSamplerParameteriv = NULL;
PFNGLSAMPLERPARAMETERFVPROC							glSamplerParameterfv = NULL;

// ARB_texture_storage
PFNGLTEXTURESTORAGE2DPROC							glTexStorage2D = NULL;
PFNGLTEXTURESTORAGE3DPROC							glTexStorage3D = NULL;

// ARB_buffer_Storage
PFNGLBUFFERSTORAGEPROC								glBufferStorage = NULL;

// ARB_framebuffer_object
PFNGLDELETERENDERBUFFERSPROC						glDeleteRenderbuffers = NULL;
PFNGLGENRENDERBUFFERSPROC							glGenRenderbuffers = NULL;
PFNGLBINDRENDERBUFFERPROC							glBindRenderbuffer = NULL;
PFNGLRENDERBUFFERSTORAGEPROC						glRenderbufferStorage = NULL;
PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC				glRenderbufferStorageMultisample = NULL;
PFNGLGETRENDERBUFFERPARAMETERIVPROC					glGetRenderbufferParameteriv = NULL;

PFNGLDELETEFRAMEBUFFERSPROC							glDeleteFramebuffers = NULL;
PFNGLGENFRAMEBUFFERSPROC							glGenFramebuffers = NULL;
PFNGLBINDFRAMEBUFFERPROC							glBindFramebuffer = NULL;
PFNGLCHECKFRAMEBUFFERSTATUSPROC						glCheckFramebufferStatus = NULL;
PFNGLFRAMEBUFFERTEXTURE1DPROC						glFramebufferTexture1D = NULL;
PFNGLFRAMEBUFFERTEXTURE2DPROC						glFramebufferTexture2D = NULL;
PFNGLFRAMEBUFFERTEXTURE3DPROC						glFramebufferTexture3D = NULL;
PFNGLFRAMEBUFFERTEXTURELAYERPROC					glFramebufferTextureLayer = NULL;
PFNGLFRAMEBUFFERRENDERBUFFERPROC					glFramebufferRenderbuffer = NULL;
PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC		glGetFramebufferAttachmentParameteriv = NULL;
PFNGLBLITFRAMEBUFFERPROC							glBlitFramebuffer = NULL;
PFNGLGENERATEMIPMAPPROC								glGenerateMipmap = NULL;

// ARB_sync
PFNGLFENCESYNCPROC									glFenceSync = NULL;
PFNGLCLIENTWAITSYNCPROC								glClientWaitSync = NULL;
PFNGLWAITSYNCPROC									glWaitSync = NULL;

// Optional Extensions
// ===================

// ARB_compute_shader
PFNGLDISPATCHCOMPUTEPROC							glDispatchCompute = NULL;

// ARB_bindless_texture
PFNGLGETTEXTUREHANDLEARBPROC						glGetTextureHandleARB = NULL;
PFNGLGETTEXTURESAMPLERHANDLEARBPROC					glGetTextureSamplerHandleARB = NULL;
PFNGLMAKETEXTUREHANDLERESIDENTARBPROC				glMakeTextureHandleResidentARB = NULL;
PFNGLMAKETEXTUREHANDLENONRESIDENTARBPROC			glMakeTextureHandleNonResidentARB = NULL;
PFNGLGETIMAGEHANDLEARBPROC							glGetImageHandleARB = NULL;
PFNGLMAKEIMAGEHANDLERESIDENTARBPROC					glMakeImageHandleResidentARB = NULL;
PFNGLMAKEIMAGEHANDLENONRESIDENTARBPROC				glMakeImageHandleNonResidentARB = NULL;
PFNGLUNIFORMHANDLEUI64ARBPROC						glUniformHandleui64ARB = NULL;
PFNGLUNIFORMHANDLEUI64VARBPROC						glUniformHandleui64vARB = NULL;

// ARB_sparse_texture
PFNGLTEXPAGECOMMITMENTARBPROC						glTexPageCommitmentARB = NULL;

// ARB_sparse_buffer
PFNGLBUFFERPAGECOMMITMENTARBPROC					glBufferPageCommitmentARB = NULL;

// ARB_multi_draw_indirect
PFNGLMULTIDRAWELEMENTSINDIRECTPROC					glMultiDrawElementsIndirect = NULL;

static GLuint extensionCount;
static size_t bufferLen;
static GLchar *extensionBuffer;
static GLchar **pExtensions;

GLvoid glGetExtensions()
{
	const GLchar *ext;
	GLchar *ptr;
	GLuint i, idx;

	glGetIntegerv(GL_NUM_EXTENSIONS, &extensionCount);
	pExtensions = (GLchar **)malloc(extensionCount * sizeof(void*));

	ext = glGetString(GL_EXTENSIONS);
	bufferLen = strlen(ext) + 1;
	extensionBuffer = (GLchar *)malloc(bufferLen);
	memcpy(extensionBuffer, ext, bufferLen);

	idx = 0;
	ptr = extensionBuffer;
	for(i = 0; i < bufferLen; ++i){
		if(extensionBuffer[i] == 0x20){
			extensionBuffer[i] = 0x00;
			pExtensions[idx] = ptr;
			ptr = &extensionBuffer[i + 1];
			++idx;
		}
	}
}

GLvoid glFreeExtensions()
{
	free(pExtensions);
	free(extensionBuffer);
}

GLboolean glHasExtension(const char *ext){
	GLchar *ptr;
	GLuint i, k;
	for(i = 0; i < extensionCount; ++i){
		ptr = pExtensions[i];

		k = 0;
		while(ptr[k] == ext[k] && ext[k] != 0x00) ++k;
		if(ptr[k] == 0x00)
			return GL_TRUE;
	}
	return GL_FALSE;
}

GLboolean glLoadExtensions(GLEXTState *G){
	glGetExtensions();

	// check essential extensions
	const char *essential[] = {
#ifdef _WIN32
		"WGL_EXT_swap_control",
#endif
#ifdef _DEBUG
		"GL_ARB_debug_output",
#endif

		"GL_ARB_multitexture",
		"GL_ARB_vertex_array_object",
		"GL_ARB_vertex_buffer_object",
		"GL_ARB_uniform_buffer_object",
		"GL_ARB_shader_objects",
		"GL_EXT_texture_array",
		"GL_ARB_sampler_objects",
		"GL_ARB_texture_storage",
		"GL_ARB_buffer_storage",
		"GL_ARB_framebuffer_object",
		"GL_ARB_sync",

		// shader explicit binding
		"GL_ARB_explicit_attrib_location",
		"GL_ARB_explicit_uniform_location",
		"GL_ARB_shading_language_420pack"
	};

	GLboolean checkFailed = GL_FALSE;
	for(GLuint i = 0; i < ARRAYSIZE(essential); ++i){
		if(!glHasExtension(essential[i])){
			printf("[error] Missing essential OpenGL Extension: %s\n", essential[i]);
			checkFailed = GL_TRUE;
		}
	}
	if(checkFailed == GL_TRUE)
		return GL_FALSE;

	// Essential extensions
	// ====================

#ifdef _WIN32
	// WGL_EXT_swap_control
	GET_WGL_PROC_ADDR(PFNWGLSWAPINTERVALEXTPROC, SwapIntervalEXT);
	GET_WGL_PROC_ADDR(PFNWGLGETSWAPINTERVALEXTPROC, GetSwapIntervalEXT);
#endif

#ifdef _DEBUG
	// ARB_debug_output
	GET_GL_PROC_ADDR(PFNGLDEBUGMESSAGECONTROLPROC, DebugMessageControl);
	GET_GL_PROC_ADDR(PFNGLDEBUGMESSAGECALLBACKPROC, DebugMessageCallback);
#endif

	// ARB_multitexture
	GET_GL_PROC_ADDR(PFNGLACTIVETEXTUREPROC, ActiveTexture);

	// ARB_vertex_array_object
	GET_GL_PROC_ADDR(PFNGLDELETEVERTEXARRAYSPROC, DeleteVertexArrays);
	GET_GL_PROC_ADDR(PFNGLGENVERTEXARRAYSPROC, GenVertexArrays);
	GET_GL_PROC_ADDR(PFNGLBINDVERTEXARRAYPROC, BindVertexArray);
	GET_GL_PROC_ADDR(PFNGLENABLEVERTEXATTRIBARRAYPROC, EnableVertexAttribArray);
	GET_GL_PROC_ADDR(PFNGLDISABLEVERTEXATTRIBARRAYPROC, DisableVertexAttribArray);
	GET_GL_PROC_ADDR(PFNGLVERTEXATTRIBPOINTERPROC, VertexAttribPointer);

	// ARB_vertex_buffer_object
	GET_GL_PROC_ADDR(PFNGLDELETEBUFFERSPROC, DeleteBuffers);
	GET_GL_PROC_ADDR(PFNGLGENBUFFERSPROC, GenBuffers);
	GET_GL_PROC_ADDR(PFNGLBINDBUFFERPROC, BindBuffer);
	GET_GL_PROC_ADDR(PFNGLBUFFERDATAPROC, BufferData);
	GET_GL_PROC_ADDR(PFNGLBUFFERSUBDATAPROC, BufferSubData);
	GET_GL_PROC_ADDR(PFNGLMAPBUFFERPROC, MapBuffer);
	GET_GL_PROC_ADDR(PFNGLUNMAPBUFFERPROC, UnmapBuffer);

	GET_GL_PROC_ADDR(PFNGLMAPBUFFERRANGEPROC, MapBufferRange);
	GET_GL_PROC_ADDR(PFNGLDRAWELEMENTSBASEVERTEXPROC, DrawElementsBaseVertex);

	// ARB_uniform_buffer_object
	GET_GL_PROC_ADDR(PFNGLBINDBUFFERBASEPROC, BindBufferBase);
	GET_GL_PROC_ADDR(PFNGLBINDBUFFERRANGEPROC, BindBufferRange);

	// ARB_shader_objects
	GET_GL_PROC_ADDR(PFNGLDELETESHADERPROC, DeleteShader);
	GET_GL_PROC_ADDR(PFNGLCREATESHADERPROC, CreateShader);
	GET_GL_PROC_ADDR(PFNGLSHADERSOURCEPROC, ShaderSource);
	GET_GL_PROC_ADDR(PFNGLCOMPILESHADERPROC, CompileShader);
	GET_GL_PROC_ADDR(PFNGLGETSHADERINFOLOGPROC, GetShaderInfoLog);
	GET_GL_PROC_ADDR(PFNGLGETSHADERIVPROC, GetShaderiv);

	GET_GL_PROC_ADDR(PFNGLDELETEPROGRAMPROC, DeleteProgram);
	GET_GL_PROC_ADDR(PFNGLCREATEPROGRAMPROC, CreateProgram);
	GET_GL_PROC_ADDR(PFNGLATTACHSHADERPROC, AttachShader);
	GET_GL_PROC_ADDR(PFNGLDETACHSHADERPROC, DetachShader);
	GET_GL_PROC_ADDR(PFNGLLINKPROGRAMPROC, LinkProgram);
	GET_GL_PROC_ADDR(PFNGLUSEPROGRAMPROC, UseProgram);
	GET_GL_PROC_ADDR(PFNGLGETPROGRAMINFOLOGPROC, GetProgramInfoLog);
	GET_GL_PROC_ADDR(PFNGLGETPROGRAMIVPROC, GetProgramiv);

	GET_GL_PROC_ADDR(PFNGLUNIFORM1IPROC, Uniform1i);
	GET_GL_PROC_ADDR(PFNGLUNIFORM1IVPROC, Uniform1iv);

	// ARB_sampler_objects
	GET_GL_PROC_ADDR(PFNGLGENSAMPLERSPROC, GenSamplers);
	GET_GL_PROC_ADDR(PFNGLDELETESAMPLERSPROC, DeleteSamplers);
	GET_GL_PROC_ADDR(PFNGLBINDSAMPLERPROC, BindSampler);
	GET_GL_PROC_ADDR(PFNGLSAMPLERPARAMETERIPROC, SamplerParameteri);
	GET_GL_PROC_ADDR(PFNGLSAMPLERPARAMETERFPROC, SamplerParameterf);
	GET_GL_PROC_ADDR(PFNGLSAMPLERPARAMETERIVPROC, SamplerParameteriv);
	GET_GL_PROC_ADDR(PFNGLSAMPLERPARAMETERFVPROC, SamplerParameterfv);

	// ARB_texture_storage
	GET_GL_PROC_ADDR(PFNGLTEXSTORAGE2DPROC, TexStorage2D);
	GET_GL_PROC_ADDR(PFNGLTEXSTORAGE3DPROC, TexStorage3D);

	// ARB_buffer_storage
	GET_GL_PROC_ADDR(PFNGLBUFFERSTORAGEPROC, BufferStorage);

	// ARB_framebuffer_object
	GET_GL_PROC_ADDR(PFNGLDELETERENDERBUFFERSPROC, DeleteRenderbuffers);
	GET_GL_PROC_ADDR(PFNGLGENRENDERBUFFERSPROC, GenRenderbuffers);
	GET_GL_PROC_ADDR(PFNGLBINDRENDERBUFFERPROC, BindRenderbuffer);
	GET_GL_PROC_ADDR(PFNGLRENDERBUFFERSTORAGEPROC, RenderbufferStorage);
	GET_GL_PROC_ADDR(PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC, RenderbufferStorageMultisample);
	GET_GL_PROC_ADDR(PFNGLGETRENDERBUFFERPARAMETERIVPROC, GetRenderbufferParameteriv);

	GET_GL_PROC_ADDR(PFNGLDELETEFRAMEBUFFERSPROC, DeleteFramebuffers);
	GET_GL_PROC_ADDR(PFNGLGENFRAMEBUFFERSPROC, GenFramebuffers);
	GET_GL_PROC_ADDR(PFNGLBINDFRAMEBUFFERPROC, BindFramebuffer);
	GET_GL_PROC_ADDR(PFNGLCHECKFRAMEBUFFERSTATUSPROC, CheckFramebufferStatus);
	GET_GL_PROC_ADDR(PFNGLFRAMEBUFFERTEXTURE1DPROC, FramebufferTexture1D);
	GET_GL_PROC_ADDR(PFNGLFRAMEBUFFERTEXTURE2DPROC, FramebufferTexture2D);
	GET_GL_PROC_ADDR(PFNGLFRAMEBUFFERTEXTURE3DPROC, FramebufferTexture3D);
	GET_GL_PROC_ADDR(PFNGLFRAMEBUFFERTEXTURELAYERPROC, FramebufferTextureLayer);
	GET_GL_PROC_ADDR(PFNGLFRAMEBUFFERRENDERBUFFERPROC, FramebufferRenderbuffer);
	GET_GL_PROC_ADDR(PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC, GetFramebufferAttachmentParameteriv);
	GET_GL_PROC_ADDR(PFNGLBLITFRAMEBUFFERPROC, BlitFramebuffer);
	GET_GL_PROC_ADDR(PFNGLGENERATEMIPMAPPROC, GenerateMipmap);

	// ARB_sync
	GET_GL_PROC_ADDR(PFNGLFENCESYNCPROC, FenceSync);
	GET_GL_PROC_ADDR(PFNGLCLIENTWAITSYNCPROC, ClientWaitSync);
	GET_GL_PROC_ADDR(PFNGLWAITSYNCPROC, WaitSync);

	// Optional Extensions
	// ===================

	// clear extension state
	memset(G, 0, sizeof(GLEXTState));

	if(glHasExtension("GL_ARB_compute_shader")){
		G->ARB_compute_shader = GL_TRUE;

		GET_GL_PROC_ADDR(PFNGLDISPATCHCOMPUTEPROC, DispatchCompute);
	}

	if(glHasExtension("GL_ARB_bindless_texture")){
		G->ARB_bindless_texture = GL_TRUE;

		GET_GL_PROC_ADDR(PFNGLGETTEXTUREHANDLEARBPROC, GetTextureHandleARB);
		GET_GL_PROC_ADDR(PFNGLGETTEXTURESAMPLERHANDLEARBPROC, GetTextureSamplerHandleARB);
		GET_GL_PROC_ADDR(PFNGLMAKETEXTUREHANDLERESIDENTARBPROC, MakeTextureHandleResidentARB);
		GET_GL_PROC_ADDR(PFNGLMAKETEXTUREHANDLENONRESIDENTARBPROC, MakeTextureHandleNonResidentARB);
		GET_GL_PROC_ADDR(PFNGLGETIMAGEHANDLEARBPROC, GetImageHandleARB);
		GET_GL_PROC_ADDR(PFNGLMAKEIMAGEHANDLERESIDENTARBPROC, MakeImageHandleResidentARB);
		GET_GL_PROC_ADDR(PFNGLMAKEIMAGEHANDLENONRESIDENTARBPROC, MakeImageHandleNonResidentARB);
		GET_GL_PROC_ADDR(PFNGLUNIFORMHANDLEUI64ARBPROC, UniformHandleui64ARB);
		GET_GL_PROC_ADDR(PFNGLUNIFORMHANDLEUI64VARBPROC, UniformHandleui64vARB);
	}

	if(glHasExtension("GL_ARB_sparse_texture")){
		G->ARB_sparse_texture = GL_TRUE;

		GET_GL_PROC_ADDR(PFNGLTEXPAGECOMMITMENTARBPROC, TexPageCommitmentARB);
	}

	if(glHasExtension("GL_ARB_sparse_buffer")){
		G->ARB_sparse_buffer = GL_TRUE;

		GET_GL_PROC_ADDR(PFNGLBUFFERPAGECOMMITMENTARBPROC, BufferPageCommitmentARB);
	}

	if(glHasExtension("GL_ARB_shader_storage_buffer_object"))
		G->ARB_shader_storage_buffer_object = GL_TRUE;

	if(glHasExtension("GL_ARB_multi_draw_indirect")
			&& glHasExtension("GL_ARB_shader_draw_parameters")){

		G->ARB_multi_draw_indirect = GL_TRUE;
		GET_GL_PROC_ADDR(PFNGLMULTIDRAWELEMENTSINDIRECTPROC, MultiDrawElementsIndirect);
	}

	glFreeExtensions();
	return GL_TRUE;
}