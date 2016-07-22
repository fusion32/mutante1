#ifndef __GL_LOADER_H__
#define __GL_LOADER_H__

#include "glcorearb.h"
#include "glext.h"

#ifdef _WIN32
	#include <windows.h>
	#include "wglext.h"
#else
	#include "glxext.h"
#endif

// Loaded OpenGL Status

// IDEA:
// 2 opengl renderers:
// 1 - high end renderer (with opengl 4.5 + extensions)
// 2 - low end renderer (with opengl 2.1 + extensions)

typedef struct GLInfo{
	GLuint majorVersion;
	GLuint minorVersion;

	GLboolean ARB_debug_output;
	GLboolean ARB_explicit_attrib_location;
	GLboolean ARB_explicit_uniform_location;
	GLboolean ARB_shading_language_420pack;

	// low end extensions
	GLboolean ARB_framebuffer_object;
	GLboolean EXT_framebuffer_object;
	GLboolean ARB_uniform_buffer_object;
	GLboolean EXT_texture_array;
	GLboolean ARB_sync;
	GLboolean ARB_texture_storage;
	GLboolean ARB_vertex_attrib_binding;

	// high end extensions
	GLboolean ARB_draw_indirect;
	GLboolean ARB_multi_draw_indirect;
	GLboolean ARB_shader_draw_parameters;
	GLboolean ARB_direct_state_access;
	GLboolean ARB_shader_storage_buffer_object;
} GLInfo;

//
extern GLInfo gl_info;

GLboolean	GL_LoadAPI();

// OpenGL 1.0 and 1.1 functions are available on all platforms as library exports
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

// Beyond version 1.1 we need to check the supported OpenGL version
// and dynamically load the procedures from the library.
// ===================

// OpenGL 1.2
GLAPI PFNGLTEXIMAGE3DPROC				glTexImage3D;
GLAPI PFNGLTEXSUBIMAGE3DPROC			glTexSubImage3D;
GLAPI PFNGLCOPYTEXSUBIMAGE3DPROC		glCopyTexSubImage3D;
//GLAPI PFNGLDRAWRANGEELEMENTSPROC		glDrawRangeElements;

// OpenGL 1.3
GLAPI PFNGLACTIVETEXTUREPROC			glActiveTexture;

// OpenGL 1.4
GLAPI PFNGLBLENDFUNCSEPARATEPROC		glBlendFuncSeparate;
GLAPI PFNGLBLENDEQUATIONPROC			glBlendEquation;
GLAPI PFNGLMULTIDRAWARRAYSPROC			glMultiDrawArrays;
GLAPI PFNGLMULTIDRAWELEMENTSPROC		glMultiDrawElements;

// OpenGL 1.5
GLAPI PFNGLBINDBUFFERPROC				glBindBuffer;
GLAPI PFNGLDELETEBUFFERSPROC			glDeleteBuffers;
GLAPI PFNGLGENBUFFERSPROC				glGenBuffers;
GLAPI PFNGLBUFFERDATAPROC				glBufferData;
GLAPI PFNGLBUFFERSUBDATAPROC			glBufferSubData;
GLAPI PFNGLMAPBUFFERPROC				glMapBuffer;
GLAPI PFNGLUNMAPBUFFERPROC				glUnmapBuffer;

GLAPI PFNGLGENQUERIESPROC				glGenQueries;
GLAPI PFNGLDELETEQUERIESPROC			glDeleteQueries;
GLAPI PFNGLBEGINQUERYPROC				glBeginQuery;
GLAPI PFNGLENDQUERYPROC					glEndQuery;
GLAPI PFNGLGETQUERYIVPROC				glGetQueryiv;
GLAPI PFNGLGETQUERYOBJECTIVPROC			glGetQueryObjectiv;
GLAPI PFNGLGETQUERYOBJECTUIVPROC		glGetQueryObjectuiv;

// OpenGL 2.0
GLAPI PFNGLCREATESHADERPROC				glCreateShader;
GLAPI PFNGLDELETESHADERPROC				glDeleteShader;
GLAPI PFNGLSHADERSOURCEPROC				glShaderSource;
GLAPI PFNGLCOMPILESHADERPROC			glCompileShader;
GLAPI PFNGLGETSHADERIVPROC				glGetShaderiv;
GLAPI PFNGLGETSHADERINFOLOGPROC			glGetShaderInfoLog;

GLAPI PFNGLCREATEPROGRAMPROC			glCreateProgram;
GLAPI PFNGLDELETEPROGRAMPROC			glDeleteProgram;
GLAPI PFNGLATTACHSHADERPROC				glAttachShader;
GLAPI PFNGLDETACHSHADERPROC				glDetachShader;
GLAPI PFNGLLINKPROGRAMPROC				glLinkProgram;
GLAPI PFNGLUSEPROGRAMPROC				glUseProgram;
GLAPI PFNGLGETPROGRAMIVPROC				glGetProgramiv;
GLAPI PFNGLGETPROGRAMINFOLOGPROC		glGetProgramInfoLog;

GLAPI PFNGLENABLEVERTEXATTRIBARRAYPROC	glEnableVertexAttribArray;
GLAPI PFNGLDISABLEVERTEXATTRIBARRAYPROC	glDisableVertexAttribArray;
GLAPI PFNGLVERTEXATTRIBPOINTERPROC		glVertexAttribPointer;
GLAPI PFNGLUNIFORM1IPROC				glUniform1i;

GLAPI PFNGLDRAWBUFFERSPROC				glDrawBuffers;
GLAPI PFNGLBLENDEQUATIONSEPARATEPROC	glBlendEquationSeparate;
GLAPI PFNGLSTENCILOPSEPARATEPROC		glSentcilOpSeparate;
GLAPI PFNGLSTENCILFUNCSEPARATEPROC		glStencilFuncSeparate;
GLAPI PFNGLSTENCILMASKSEPARATEPROC		glStencilMaskSeparate;

// OpenGL 3.0
GLAPI PFNGLENABLEIPROC					glEnablei;
GLAPI PFNGLDISABLEIPROC					glDisablei;
GLAPI PFNGLGETBOOLEANI_VPROC			glGetBooleani_v;
GLAPI PFNGLGETINTEGERI_VPROC			glGetIntegeri_v;
GLAPI PFNGLGETSTRINGIPROC				glGetStringi;
GLAPI PFNGLCOLORMASKIPROC				glColorMaski;
GLAPI PFNGLCLEARBUFFERIVPROC			glClearBufferiv;
GLAPI PFNGLCLEARBUFFERUIVPROC			glClearBufferuiv;
GLAPI PFNGLCLEARBUFFERFVPROC			glClearBufferfv;
GLAPI PFNGLCLEARBUFFERFIPROC			glClearBufferfi;
GLAPI PFNGLVERTEXATTRIBIPOINTERPROC		glVertexAttribIPointer;
GLAPI PFNGLMAPBUFFERRANGEPROC			glMapBufferRange;
GLAPI PFNGLFLUSHMAPPEDBUFFERRANGEPROC	glFlushMappedBufferRange;

GLAPI PFNGLBINDVERTEXARRAYPROC			glBindVertexArray;
GLAPI PFNGLDELETEVERTEXARRAYSPROC		glDeleteVertexArrays;
GLAPI PFNGLGENVERTEXARRAYSPROC			glGenVertexArrays;

GLAPI PFNGLBINDRENDERBUFFERPROC			glBindRenderbuffer;
GLAPI PFNGLDELETERENDERBUFFERSPROC		glDeleteRenderbuffers;
GLAPI PFNGLGENRENDERBUFFERSPROC			glGenRenderbuffers;
GLAPI PFNGLRENDERBUFFERSTORAGEPROC		glRenderbufferStorage;
GLAPI PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC	glRenderbufferStorageMultisample;

GLAPI PFNGLBINDFRAMEBUFFERPROC			glBindFramebuffer;
GLAPI PFNGLDELETEFRAMEBUFFERSPROC		glDeleteFramebuffers;
GLAPI PFNGLGENFRAMEBUFFERSPROC			glGenFramebuffers;
GLAPI PFNGLCHECKFRAMEBUFFERSTATUSPROC	glCheckFramebufferStatus;
GLAPI PFNGLFRAMEBUFFERTEXTURE1DPROC		glFramebufferTexture1D;
GLAPI PFNGLFRAMEBUFFERTEXTURE2DPROC		glFramebufferTexture2D;
GLAPI PFNGLFRAMEBUFFERTEXTURE3DPROC		glFramebufferTexture3D;
GLAPI PFNGLFRAMEBUFFERRENDERBUFFERPROC	glFramebufferRenderbuffer;
GLAPI PFNGLFRAMEBUFFERTEXTURELAYERPROC	glFramebufferTextureLayer;

GLAPI PFNGLBINDBUFFERRANGEPROC			glBindBufferRange;
GLAPI PFNGLBINDBUFFERBASEPROC			glBindBufferBase;

//GLAPI PFNGLBEGINTRANSFORMFEEDBACKPROC	glBeginTransformFeedback;
//GLAPI PFNGLENDTRANSFORMFEEDBACKPROC		glEndTransformFeedback;
//GLAPI PFNGLTRANSFORMFEEDBACKVARYINGSPROC	glTransformFeedbackVaryings;

//GLAPI PFNGLBEGINCONDITIONALRENDERPROC	glBeginConditionalRender;
//GLAPI PFNGLENDCONDITIONALRENDERPROC		glEndConditionalRender;

// OpenGL 3.1
GLAPI PFNGLDRAWARRAYSINSTANCEDPROC		glDrawArraysInstanced;
GLAPI PFNGLDRAWELEMENTSINSTANCEDPROC	glDrawElementsInstanced;
GLAPI PFNGLTEXBUFFERPROC				glTexBuffer;
GLAPI PFNGLCOPYBUFFERSUBDATAPROC		glCopyBufferSubData;

// OpenGL 3.2
GLAPI PFNGLGETINTEGER64VPROC			glGetInteger64v;
GLAPI PFNGLGETINTEGER64I_VPROC			glGetInteger64i_v;
GLAPI PFNGLSAMPLEMASKIPROC				glSampleMaski;
GLAPI PFNGLFRAMEBUFFERTEXTUREPROC		glFramebufferTexture;
GLAPI PFNGLTEXIMAGE2DMULTISAMPLEPROC	glTexImage2DMultisample;
GLAPI PFNGLTEXIMAGE3DMULTISAMPLEPROC	glTexImage3DMultisample;
GLAPI PFNGLGETMULTISAMPLEFVPROC			glGetMultisamplefv;
GLAPI PFNGLPROVOKINGVERTEXPROC			glProvokingVertex;

GLAPI PFNGLDRAWELEMENTSBASEVERTEXPROC	glDrawElementsBaseVertex;
GLAPI PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC	glDrawRangeElementsBaseVertex;
GLAPI PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC	glDrawElementsInstancedBaseVertex;
GLAPI PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC	glMultiDrawElementsBaseVertex;

GLAPI PFNGLFENCESYNCPROC				glFenceSync;
GLAPI PFNGLDELETESYNCPROC				glDeleteSync;
GLAPI PFNGLCLIENTWAITSYNCPROC			glClientWaitSync;
GLAPI PFNGLWAITSYNCPROC					glWaitSync;
GLAPI PFNGLGETSYNCIVPROC				glGetSynciv;

// OpenGL 3.3
GLAPI PFNGLQUERYCOUNTERPROC				glQueryCounter;
GLAPI PFNGLGETQUERYOBJECTI64VPROC		glGetQueryObjecti64v;
GLAPI PFNGLGETQUERYOBJECTUI64VPROC		glGetQueryObjectui64v;
GLAPI PFNGLVERTEXATTRIBDIVISORPROC		glVertexAttribDivisor;

GLAPI PFNGLGENSAMPLERSPROC				glGenSamplers;
GLAPI PFNGLDELETESAMPLERSPROC			glDeleteSamplers;
GLAPI PFNGLBINDSAMPLERPROC				glBindSampler;
GLAPI PFNGLSAMPLERPARAMETERIPROC		glSamplerParameteri;
GLAPI PFNGLSAMPLERPARAMETERIVPROC		glSamplerParameteriv;
GLAPI PFNGLSAMPLERPARAMETERFPROC		glSamplerParameterf;
GLAPI PFNGLSAMPLERPARAMETERFVPROC		glSamplerParameterfv;
GLAPI PFNGLSAMPLERPARAMETERIIVPROC		glSamplerParameterIiv;
GLAPI PFNGLSAMPLERPARAMETERIUIVPROC		glSamplerParameterIuiv;

// OpenGL 4.0
//

// OpenGL 4.1
//

// OpenGL 4.2
//

// OpenGL 4.3
//

// OpenGL 4.4
//

// OpenGL 4.5
//


#endif //__GL_LOADER_H__