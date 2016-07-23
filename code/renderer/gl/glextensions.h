#ifndef __GL_H__
#define __GL_H__

#include "glcorearb.h"

#ifdef _WIN32
	#include "wglext.h"
#else
	#include "glxext.h"
#endif

// These functions are available on all platforms as direct exports from the libraries.
// ===================

// OpenGL 1.0
GLAPI void APIENTRY glCullFace (GLenum mode);
GLAPI void APIENTRY glFrontFace (GLenum mode);
GLAPI void APIENTRY glHint (GLenum target, GLenum mode);
GLAPI void APIENTRY glLineWidth (GLfloat width);
GLAPI void APIENTRY glPointSize (GLfloat size);
GLAPI void APIENTRY glPolygonMode (GLenum face, GLenum mode);
GLAPI void APIENTRY glScissor (GLint x, GLint y, GLsizei width, GLsizei height);
GLAPI void APIENTRY glTexParameterf (GLenum target, GLenum pname, GLfloat param);
GLAPI void APIENTRY glTexParameterfv (GLenum target, GLenum pname, const GLfloat *params);
GLAPI void APIENTRY glTexParameteri (GLenum target, GLenum pname, GLint param);
GLAPI void APIENTRY glTexParameteriv (GLenum target, GLenum pname, const GLint *params);
GLAPI void APIENTRY glTexImage1D (GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void *pixels);
GLAPI void APIENTRY glTexImage2D (GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void *pixels);
GLAPI void APIENTRY glDrawBuffer (GLenum buf);
GLAPI void APIENTRY glClear (GLbitfield mask);
GLAPI void APIENTRY glClearColor (GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha);
GLAPI void APIENTRY glClearStencil (GLint s);
GLAPI void APIENTRY glClearDepth (GLdouble depth);
GLAPI void APIENTRY glStencilMask (GLuint mask);
GLAPI void APIENTRY glColorMask (GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha);
GLAPI void APIENTRY glDepthMask (GLboolean flag);
GLAPI void APIENTRY glDisable (GLenum cap);
GLAPI void APIENTRY glEnable (GLenum cap);
GLAPI void APIENTRY glFinish (void);
GLAPI void APIENTRY glFlush (void);
GLAPI void APIENTRY glBlendFunc (GLenum sfactor, GLenum dfactor);
GLAPI void APIENTRY glLogicOp (GLenum opcode);
GLAPI void APIENTRY glStencilFunc (GLenum func, GLint ref, GLuint mask);
GLAPI void APIENTRY glStencilOp (GLenum fail, GLenum zfail, GLenum zpass);
GLAPI void APIENTRY glDepthFunc (GLenum func);
GLAPI void APIENTRY glPixelStoref (GLenum pname, GLfloat param);
GLAPI void APIENTRY glPixelStorei (GLenum pname, GLint param);
GLAPI void APIENTRY glReadBuffer (GLenum src);
GLAPI void APIENTRY glReadPixels (GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void *pixels);
GLAPI void APIENTRY glGetBooleanv (GLenum pname, GLboolean *data);
GLAPI void APIENTRY glGetDoublev (GLenum pname, GLdouble *data);
GLAPI GLenum APIENTRY glGetError (void);
GLAPI void APIENTRY glGetFloatv (GLenum pname, GLfloat *data);
GLAPI void APIENTRY glGetIntegerv (GLenum pname, GLint *data);
GLAPI const GLubyte *APIENTRY glGetString (GLenum name);
GLAPI void APIENTRY glGetTexImage (GLenum target, GLint level, GLenum format, GLenum type, void *pixels);
GLAPI void APIENTRY glGetTexParameterfv (GLenum target, GLenum pname, GLfloat *params);
GLAPI void APIENTRY glGetTexParameteriv (GLenum target, GLenum pname, GLint *params);
GLAPI void APIENTRY glGetTexLevelParameterfv (GLenum target, GLint level, GLenum pname, GLfloat *params);
GLAPI void APIENTRY glGetTexLevelParameteriv (GLenum target, GLint level, GLenum pname, GLint *params);
GLAPI GLboolean APIENTRY glIsEnabled (GLenum cap);
GLAPI void APIENTRY glDepthRange (GLdouble near, GLdouble far);
GLAPI void APIENTRY glViewport (GLint x, GLint y, GLsizei width, GLsizei height);

// OpenGL 1.1
GLAPI void APIENTRY glDrawArrays (GLenum mode, GLint first, GLsizei count);
GLAPI void APIENTRY glDrawElements (GLenum mode, GLsizei count, GLenum type, const void *indices);
GLAPI void APIENTRY glGetPointerv (GLenum pname, void **params);
GLAPI void APIENTRY glPolygonOffset (GLfloat factor, GLfloat units);
GLAPI void APIENTRY glCopyTexImage1D (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border);
GLAPI void APIENTRY glCopyTexImage2D (GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border);
GLAPI void APIENTRY glCopyTexSubImage1D (GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width);
GLAPI void APIENTRY glCopyTexSubImage2D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height);
GLAPI void APIENTRY glTexSubImage1D (GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void *pixels);
GLAPI void APIENTRY glTexSubImage2D (GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void *pixels);
GLAPI void APIENTRY glBindTexture (GLenum target, GLuint texture);
GLAPI void APIENTRY glDeleteTextures (GLsizei n, const GLuint *textures);
GLAPI void APIENTRY glGenTextures (GLsizei n, GLuint *textures);
GLAPI GLboolean APIENTRY glIsTexture (GLuint texture);

// Essential extensions
// ====================

#ifdef _WIN32
// WGL_EXT_swap_control
GLAPI PFNWGLSWAPINTERVALEXTPROC							wglSwapIntervalEXT;
GLAPI PFNWGLGETSWAPINTERVALEXTPROC						wglGetSwapIntervalEXT;
#else
#endif

#ifdef _DEBUG
// ARB_debug_output
// Requires:	v1.1
// Core:		v4.0
GLAPI PFNGLDEBUGMESSAGECONTROLPROC						glDebugMessageControl;
GLAPI PFNGLDEBUGMESSAGECALLBACKPROC						glDebugMessageCallback;
#endif

// ARB_multitexture
// Requires:	(?)
// Core:		v1.3
GLAPI PFNGLACTIVETEXTUREPROC							glActiveTexture;

// ARB_vertex_array_object
// Requires:	(?)
// Core:		v3.0
GLAPI PFNGLDELETEVERTEXARRAYSPROC						glDeleteVertexArrays;
GLAPI PFNGLGENVERTEXARRAYSPROC							glGenVertexArrays;
GLAPI PFNGLBINDVERTEXARRAYPROC							glBindVertexArray;
GLAPI PFNGLENABLEVERTEXATTRIBARRAYPROC					glEnableVertexAttribArray;
GLAPI PFNGLDISABLEVERTEXATTRIBARRAYPROC					glDisableVertexAttribArray;
GLAPI PFNGLVERTEXATTRIBPOINTERPROC						glVertexAttribPointer;

// ARB_vertex_buffer_object
// Requires:	(?)
// Core:		v1.5
GLAPI PFNGLDELETEBUFFERSPROC							glDeleteBuffers;
GLAPI PFNGLGENBUFFERSPROC								glGenBuffers;
GLAPI PFNGLBINDBUFFERPROC								glBindBuffer;
GLAPI PFNGLBUFFERDATAPROC								glBufferData;
GLAPI PFNGLBUFFERSUBDATAPROC							glBufferSubData;
GLAPI PFNGLMAPBUFFERPROC								glMapBuffer;
GLAPI PFNGLUNMAPBUFFERPROC								glUnmapBuffer;

// ARB_map_buffer_range
// Requires:	v2.1
// Core:		v2.1
GLAPI PFNGLMAPBUFFERRANGEPROC							glMapBufferRange;
GLAPI PFNGLFLUSHMAPPEDBUFFERRANGEPROC					glFlushMappedBufferRange;

// ARB_draw_elements_base_vertex
// Requires:	(?)
// Core:		v3.1
GLAPI PFNGLDRAWELEMENTSBASEVERTEXPROC					glDrawElementsBaseVertex;

// ARB_uniform_buffer_object
// Requires:	v2.0 (or ARB_shader_objects and ARB_vertex_buffer_object)
// Core:		v3.1
GLAPI PFNGLBINDBUFFERBASEPROC							glBindBufferBase;
GLAPI PFNGLBINDBUFFERRANGEPROC							glBindBufferRange;

// ARB_shader_objects
// Requires:	v1.0
// Core:		v2.0
GLAPI PFNGLDELETESHADERPROC								glDeleteShader;
GLAPI PFNGLCREATESHADERPROC								glCreateShader;
GLAPI PFNGLSHADERSOURCEPROC								glShaderSource;
GLAPI PFNGLCOMPILESHADERPROC							glCompileShader;
GLAPI PFNGLGETSHADERINFOLOGPROC							glGetShaderInfoLog;
GLAPI PFNGLGETSHADERIVPROC								glGetShaderiv;

GLAPI PFNGLDELETEPROGRAMPROC							glDeleteProgram;
GLAPI PFNGLCREATEPROGRAMPROC							glCreateProgram;
GLAPI PFNGLATTACHSHADERPROC								glAttachShader;
GLAPI PFNGLDETACHSHADERPROC								glDetachShader;
GLAPI PFNGLLINKPROGRAMPROC								glLinkProgram;
GLAPI PFNGLUSEPROGRAMPROC								glUseProgram;
GLAPI PFNGLGETPROGRAMINFOLOGPROC						glGetProgramInfoLog;
GLAPI PFNGLGETPROGRAMIVPROC								glGetProgramiv;

GLAPI PFNGLUNIFORM1IPROC								glUniform1i;
GLAPI PFNGLUNIFORM1IVPROC								glUniform1iv;

// ARB_sampler_objects
// Requires:	v1.0
// Core:		v3.3
GLAPI PFNGLGENSAMPLERSPROC								glGenSamplers;
GLAPI PFNGLDELETESAMPLERSPROC							glDeleteSamplers;
GLAPI PFNGLBINDSAMPLERPROC								glBindSampler;
GLAPI PFNGLSAMPLERPARAMETERIPROC						glSamplerParameteri;
GLAPI PFNGLSAMPLERPARAMETERFPROC						glSamplerParameterf;
GLAPI PFNGLSAMPLERPARAMETERIVPROC						glSamplerParameteriv;
GLAPI PFNGLSAMPLERPARAMETERFVPROC						glSamplerParameterfv;

// ARB_texture_storage
// Requires:	v1.2
// Core:		NYI
GLAPI PFNGLTEXTURESTORAGE2DPROC							glTexStorage2D;
GLAPI PFNGLTEXTURESTORAGE3DPROC							glTexStorage3D;

// ARB_buffer_storage
// Requires:	(?)
// Core:		v4.3(?)
GLAPI PFNGLBUFFERSTORAGEPROC							glBufferStorage;

// ARB_framebuffer_object
// Requires:	v1.1
// Core:		v3.0
GLAPI PFNGLDELETERENDERBUFFERSPROC						glDeleteRenderbuffers;
GLAPI PFNGLGENRENDERBUFFERSPROC							glGenRenderbuffers;
GLAPI PFNGLBINDRENDERBUFFERPROC							glBindRenderbuffer;
GLAPI PFNGLRENDERBUFFERSTORAGEPROC						glRenderbufferStorage;
GLAPI PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC			glRenderbufferStorageMultisample;
GLAPI PFNGLGETRENDERBUFFERPARAMETERIVPROC				glGetRenderbufferParameteriv;

GLAPI PFNGLDELETEFRAMEBUFFERSPROC						glDeleteFramebuffers;
GLAPI PFNGLGENFRAMEBUFFERSPROC							glGenFramebuffers;
GLAPI PFNGLBINDFRAMEBUFFERPROC							glBindFramebuffer;
GLAPI PFNGLCHECKFRAMEBUFFERSTATUSPROC					glCheckFramebufferStatus;
GLAPI PFNGLFRAMEBUFFERTEXTURE1DPROC						glFramebufferTexture1D;
GLAPI PFNGLFRAMEBUFFERTEXTURE2DPROC						glFramebufferTexture2D;
GLAPI PFNGLFRAMEBUFFERTEXTURE3DPROC						glFramebufferTexture3D;
GLAPI PFNGLFRAMEBUFFERTEXTURELAYERPROC					glFramebufferTextureLayer;
GLAPI PFNGLFRAMEBUFFERRENDERBUFFERPROC					glFramebufferRenderbuffer;
GLAPI PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC		glGetFramebufferAttachmentParameteriv;
GLAPI PFNGLBLITFRAMEBUFFERPROC							glBlitFramebuffer;
GLAPI PFNGLGENERATEMIPMAPPROC							glGenerateMipmap;

// ARB_sync
// Requires:	v3.1
// Core:		v3.2
GLAPI PFNGLFENCESYNCPROC								glFenceSync;
GLAPI PFNGLCLIENTWAITSYNCPROC							glClientWaitSync;
GLAPI PFNGLWAITSYNCPROC									glWaitSync;

// Optional Extensions
// ===================

// ARB_compute_shader
// Requires:	v4.2
// Core:		v4.3
GLAPI PFNGLDISPATCHCOMPUTEPROC							glDispatchCompute;

// ARB_shader_storage_buffer_object
// Requires:	v4.0 (ARB_program_interface_query)
// Core:		v4.3

// ARB_bindless_texture
// Requires:	v4.0
// Core:		NYI
GLAPI PFNGLGETTEXTUREHANDLEARBPROC						glGetTextureHandleARB;
GLAPI PFNGLGETTEXTURESAMPLERHANDLEARBPROC				glGetTextureSamplerHandleARB;
GLAPI PFNGLMAKETEXTUREHANDLERESIDENTARBPROC				glMakeTextureHandleResidentARB;
GLAPI PFNGLMAKETEXTUREHANDLENONRESIDENTARBPROC			glMakeTextureHandleNonResidentARB;
GLAPI PFNGLGETIMAGEHANDLEARBPROC						glGetImageHandleARB;
GLAPI PFNGLMAKEIMAGEHANDLERESIDENTARBPROC				glMakeImageHandleResidentARB;
GLAPI PFNGLMAKEIMAGEHANDLENONRESIDENTARBPROC			glMakeImageHandleNonResidentARB;
GLAPI PFNGLUNIFORMHANDLEUI64ARBPROC						glUniformHandleui64ARB;
GLAPI PFNGLUNIFORMHANDLEUI64VARBPROC					glUniformHandleui64vARB;

// ARB_sparse_texture
// Requires:	v1.1
// Core:		NYI
GLAPI PFNGLTEXPAGECOMMITMENTARBPROC						glTexPageCommitmentARB;

// ARB_sparse_buffer
// Requires:	v4.4
// Core:		NYI
GLAPI PFNGLBUFFERPAGECOMMITMENTARBPROC					glBufferPageCommitmentARB;

// ARB_draw_indirect
// Requires:	3.1
// Core:		4.0

// ARB_multi_draw_indirect
// Requires:	v4.0 (or ARB_draw_indirect)
// Core:		NYI
typedef struct{
	GLuint count;
	GLuint primcount;
	GLuint firstIndex;
	GLint baseVertex;
	GLuint reservedMustBeZero;
} DrawElementsIndirectCommand;
GLAPI PFNGLMULTIDRAWELEMENTSINDIRECTPROC				glMultiDrawElementsIndirect;

// ARB_direct_state_access
// Requires:	v2.0
// Core:		v4.5

// ARB_separate_shader_objects
// Requires:	v2.0 (or ARB_shader_objects)
// Core:		NYI

//
typedef struct {
	GLboolean ARB_compute_shader;
	GLboolean ARB_bindless_texture;
	GLboolean ARB_sparse_texture;
	GLboolean ARB_sparse_buffer;
	GLboolean ARB_shader_storage_buffer_object;
	GLboolean ARB_multi_draw_indirect;

	// GL_ARB_direct_state_access;
	// GL_KHR_vulkan_glsl
} GLEXTState;

extern GLboolean glLoadExtensions(GLEXTState *G);

#endif //__GL_H__