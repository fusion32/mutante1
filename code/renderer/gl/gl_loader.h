// this file has been automatically generated by gllgen

#ifndef __GL_LOADER_H__
#define __GL_LOADER_H__

#include "glcorearb.h"
#include "glext.h"

#ifdef _WIN32
	#include "wglext.h"
#else
	#include "glxext.h"
#endif

// Loader API
// ==========
GLboolean	GL_LoadAPI();
void		GL_ReleaseAPI();

// Function Exports
// ================

// These are available in every platform as direct exports from the library
// but on Windows, wglGetProcAddress will return NULL for any of these.

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

// Function Pointers
// =================


// OpenGL 1.2
GLAPI PFNGLDRAWRANGEELEMENTSPROC glDrawRangeElements;
GLAPI PFNGLTEXIMAGE3DPROC glTexImage3D;
GLAPI PFNGLTEXSUBIMAGE3DPROC glTexSubImage3D;
GLAPI PFNGLCOPYTEXSUBIMAGE3DPROC glCopyTexSubImage3D;

// OpenGL 1.3
GLAPI PFNGLACTIVETEXTUREPROC glActiveTexture;
GLAPI PFNGLSAMPLECOVERAGEPROC glSampleCoverage;
GLAPI PFNGLCOMPRESSEDTEXIMAGE1DPROC glCompressedTexImage1D;
GLAPI PFNGLCOMPRESSEDTEXIMAGE2DPROC glCompressedTexImage2D;
GLAPI PFNGLCOMPRESSEDTEXIMAGE3DPROC glCompressedTexImage3D;
GLAPI PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC glCompressedTexSubImage1D;
GLAPI PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC glCompressedTexSubImage2D;
GLAPI PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC glCompressedTexSubImage3D;
GLAPI PFNGLGETCOMPRESSEDTEXIMAGEPROC glGetCompressedTexImage;

// OpenGL 1.4
GLAPI PFNGLBLENDFUNCSEPARATEPROC glBlendFuncSeparate;
GLAPI PFNGLMULTIDRAWARRAYSPROC glMultiDrawArrays;
GLAPI PFNGLMULTIDRAWELEMENTSPROC glMultiDrawElements;
GLAPI PFNGLPOINTPARAMETERFPROC glPointParameterf;
GLAPI PFNGLPOINTPARAMETERFVPROC glPointParameterfv;
GLAPI PFNGLPOINTPARAMETERIPROC glPointParameteri;
GLAPI PFNGLPOINTPARAMETERIVPROC glPointParameteriv;
GLAPI PFNGLBLENDCOLORPROC glBlendColor;
GLAPI PFNGLBLENDEQUATIONPROC glBlendEquation;

// OpenGL 1.5
GLAPI PFNGLGENQUERIESPROC glGenQueries;
GLAPI PFNGLDELETEQUERIESPROC glDeleteQueries;
GLAPI PFNGLISQUERYPROC glIsQuery;
GLAPI PFNGLBEGINQUERYPROC glBeginQuery;
GLAPI PFNGLENDQUERYPROC glEndQuery;
GLAPI PFNGLGETQUERYIVPROC glGetQueryiv;
GLAPI PFNGLGETQUERYOBJECTIVPROC glGetQueryObjectiv;
GLAPI PFNGLGETQUERYOBJECTUIVPROC glGetQueryObjectuiv;
GLAPI PFNGLBINDBUFFERPROC glBindBuffer;
GLAPI PFNGLDELETEBUFFERSPROC glDeleteBuffers;
GLAPI PFNGLGENBUFFERSPROC glGenBuffers;
GLAPI PFNGLISBUFFERPROC glIsBuffer;
GLAPI PFNGLBUFFERDATAPROC glBufferData;
GLAPI PFNGLBUFFERSUBDATAPROC glBufferSubData;
GLAPI PFNGLGETBUFFERSUBDATAPROC glGetBufferSubData;
GLAPI PFNGLMAPBUFFERPROC glMapBuffer;
GLAPI PFNGLUNMAPBUFFERPROC glUnmapBuffer;
GLAPI PFNGLGETBUFFERPARAMETERIVPROC glGetBufferParameteriv;
GLAPI PFNGLGETBUFFERPOINTERVPROC glGetBufferPointerv;

// OpenGL 2.0
GLAPI PFNGLBLENDEQUATIONSEPARATEPROC glBlendEquationSeparate;
GLAPI PFNGLDRAWBUFFERSPROC glDrawBuffers;
GLAPI PFNGLSTENCILOPSEPARATEPROC glStencilOpSeparate;
GLAPI PFNGLSTENCILFUNCSEPARATEPROC glStencilFuncSeparate;
GLAPI PFNGLSTENCILMASKSEPARATEPROC glStencilMaskSeparate;
GLAPI PFNGLATTACHSHADERPROC glAttachShader;
GLAPI PFNGLBINDATTRIBLOCATIONPROC glBindAttribLocation;
GLAPI PFNGLCOMPILESHADERPROC glCompileShader;
GLAPI PFNGLCREATEPROGRAMPROC glCreateProgram;
GLAPI PFNGLCREATESHADERPROC glCreateShader;
GLAPI PFNGLDELETEPROGRAMPROC glDeleteProgram;
GLAPI PFNGLDELETESHADERPROC glDeleteShader;
GLAPI PFNGLDETACHSHADERPROC glDetachShader;
GLAPI PFNGLDISABLEVERTEXATTRIBARRAYPROC glDisableVertexAttribArray;
GLAPI PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray;
GLAPI PFNGLGETACTIVEATTRIBPROC glGetActiveAttrib;
GLAPI PFNGLGETACTIVEUNIFORMPROC glGetActiveUniform;
GLAPI PFNGLGETATTACHEDSHADERSPROC glGetAttachedShaders;
GLAPI PFNGLGETATTRIBLOCATIONPROC glGetAttribLocation;
GLAPI PFNGLGETPROGRAMIVPROC glGetProgramiv;
GLAPI PFNGLGETPROGRAMINFOLOGPROC glGetProgramInfoLog;
GLAPI PFNGLGETSHADERIVPROC glGetShaderiv;
GLAPI PFNGLGETSHADERINFOLOGPROC glGetShaderInfoLog;
GLAPI PFNGLGETSHADERSOURCEPROC glGetShaderSource;
GLAPI PFNGLGETUNIFORMLOCATIONPROC glGetUniformLocation;
GLAPI PFNGLGETUNIFORMFVPROC glGetUniformfv;
GLAPI PFNGLGETUNIFORMIVPROC glGetUniformiv;
GLAPI PFNGLGETVERTEXATTRIBDVPROC glGetVertexAttribdv;
GLAPI PFNGLGETVERTEXATTRIBFVPROC glGetVertexAttribfv;
GLAPI PFNGLGETVERTEXATTRIBIVPROC glGetVertexAttribiv;
GLAPI PFNGLGETVERTEXATTRIBPOINTERVPROC glGetVertexAttribPointerv;
GLAPI PFNGLISPROGRAMPROC glIsProgram;
GLAPI PFNGLISSHADERPROC glIsShader;
GLAPI PFNGLLINKPROGRAMPROC glLinkProgram;
GLAPI PFNGLSHADERSOURCEPROC glShaderSource;
GLAPI PFNGLUSEPROGRAMPROC glUseProgram;
GLAPI PFNGLUNIFORM1FPROC glUniform1f;
GLAPI PFNGLUNIFORM2FPROC glUniform2f;
GLAPI PFNGLUNIFORM3FPROC glUniform3f;
GLAPI PFNGLUNIFORM4FPROC glUniform4f;
GLAPI PFNGLUNIFORM1IPROC glUniform1i;
GLAPI PFNGLUNIFORM2IPROC glUniform2i;
GLAPI PFNGLUNIFORM3IPROC glUniform3i;
GLAPI PFNGLUNIFORM4IPROC glUniform4i;
GLAPI PFNGLUNIFORM1FVPROC glUniform1fv;
GLAPI PFNGLUNIFORM2FVPROC glUniform2fv;
GLAPI PFNGLUNIFORM3FVPROC glUniform3fv;
GLAPI PFNGLUNIFORM4FVPROC glUniform4fv;
GLAPI PFNGLUNIFORM1IVPROC glUniform1iv;
GLAPI PFNGLUNIFORM2IVPROC glUniform2iv;
GLAPI PFNGLUNIFORM3IVPROC glUniform3iv;
GLAPI PFNGLUNIFORM4IVPROC glUniform4iv;
GLAPI PFNGLUNIFORMMATRIX2FVPROC glUniformMatrix2fv;
GLAPI PFNGLUNIFORMMATRIX3FVPROC glUniformMatrix3fv;
GLAPI PFNGLUNIFORMMATRIX4FVPROC glUniformMatrix4fv;
GLAPI PFNGLVALIDATEPROGRAMPROC glValidateProgram;
GLAPI PFNGLVERTEXATTRIB1DPROC glVertexAttrib1d;
GLAPI PFNGLVERTEXATTRIB1DVPROC glVertexAttrib1dv;
GLAPI PFNGLVERTEXATTRIB1FPROC glVertexAttrib1f;
GLAPI PFNGLVERTEXATTRIB1FVPROC glVertexAttrib1fv;
GLAPI PFNGLVERTEXATTRIB1SPROC glVertexAttrib1s;
GLAPI PFNGLVERTEXATTRIB1SVPROC glVertexAttrib1sv;
GLAPI PFNGLVERTEXATTRIB2DPROC glVertexAttrib2d;
GLAPI PFNGLVERTEXATTRIB2DVPROC glVertexAttrib2dv;
GLAPI PFNGLVERTEXATTRIB2FPROC glVertexAttrib2f;
GLAPI PFNGLVERTEXATTRIB2FVPROC glVertexAttrib2fv;
GLAPI PFNGLVERTEXATTRIB2SPROC glVertexAttrib2s;
GLAPI PFNGLVERTEXATTRIB2SVPROC glVertexAttrib2sv;
GLAPI PFNGLVERTEXATTRIB3DPROC glVertexAttrib3d;
GLAPI PFNGLVERTEXATTRIB3DVPROC glVertexAttrib3dv;
GLAPI PFNGLVERTEXATTRIB3FPROC glVertexAttrib3f;
GLAPI PFNGLVERTEXATTRIB3FVPROC glVertexAttrib3fv;
GLAPI PFNGLVERTEXATTRIB3SPROC glVertexAttrib3s;
GLAPI PFNGLVERTEXATTRIB3SVPROC glVertexATtrib3sv;
GLAPI PFNGLVERTEXATTRIB4NBVPROC glVertexAttrib4Nbv;
GLAPI PFNGLVERTEXATTRIB4NIVPROC glVertexAttrib4Niv;
GLAPI PFNGLVERTEXATTRIB4NSVPROC glVertexAttrib4Nsv;
GLAPI PFNGLVERTEXATTRIB4NUBPROC glVertexAttrib4Nub;
GLAPI PFNGLVERTEXATTRIB4NUBVPROC glVertexAttrib4Nubv;
GLAPI PFNGLVERTEXATTRIB4NUIVPROC glVertexAttrib4Nuiv;
GLAPI PFNGLVERTEXATTRIB4NUSVPROC glVertexAttrib4Nusv;
GLAPI PFNGLVERTEXATTRIB4BVPROC glVertexAttrib4bv;
GLAPI PFNGLVERTEXATTRIB4DPROC glVertexAttrib4d;
GLAPI PFNGLVERTEXATTRIB4DVPROC glVertexAttrib4dv;
GLAPI PFNGLVERTEXATTRIB4FPROC glVertexAttrib4f;
GLAPI PFNGLVERTEXATTRIB4FVPROC glVertexAttrib4fv;
GLAPI PFNGLVERTEXATTRIB4IVPROC glVertexAttrib4iv;
GLAPI PFNGLVERTEXATTRIB4SPROC glVertexAttrib4s;
GLAPI PFNGLVERTEXATTRIB4SVPROC glVertexAttrib4sv;
GLAPI PFNGLVERTEXATTRIB4UBVPROC glVertexAttrib4ubv;
GLAPI PFNGLVERTEXATTRIB4UIVPROC glVertexAttrib4uiv;
GLAPI PFNGLVERTEXATTRIB4USVPROC glVertexAttrib4usv;
GLAPI PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer;

// OpenGL 2.1
GLAPI PFNGLUNIFORMMATRIX2X3FVPROC glUniformMatrix2x3fv;
GLAPI PFNGLUNIFORMMATRIX3X2FVPROC glUniformMatrix3x2fv;
GLAPI PFNGLUNIFORMMATRIX2X4FVPROC glUniformMatrix2x4fv;
GLAPI PFNGLUNIFORMMATRIX4X2FVPROC glUniformMatrix4x2fv;
GLAPI PFNGLUNIFORMMATRIX3X4FVPROC glUniformMatrix3x4fv;
GLAPI PFNGLUNIFORMMATRIX4X3FVPROC glUniformMatrix4x3fv;

// OpenGL 3.0
GLAPI PFNGLCOLORMASKIPROC glColorMaski;
GLAPI PFNGLGETBOOLEANI_VPROC glGetBooleani_v;
GLAPI PFNGLGETINTEGERI_VPROC glGetIntegeri_v;
GLAPI PFNGLENABLEIPROC glEnablei;
GLAPI PFNGLDISABLEIPROC glDisablei;
GLAPI PFNGLISENABLEDIPROC glIsEnabledi;
GLAPI PFNGLBEGINTRANSFORMFEEDBACKPROC glBeginTransformFeedback;
GLAPI PFNGLENDTRANSFORMFEEDBACKPROC glEndTransformFeedback;
GLAPI PFNGLBINDBUFFERRANGEPROC glBindBufferRange;
GLAPI PFNGLBINDBUFFERBASEPROC glBindBufferBase;
GLAPI PFNGLTRANSFORMFEEDBACKVARYINGSPROC glTransformFeedbackVaryings;
GLAPI PFNGLGETTRANSFORMFEEDBACKVARYINGPROC glGetTransformFeedbackVarying;
GLAPI PFNGLCLAMPCOLORPROC glClampColor;
GLAPI PFNGLBEGINCONDITIONALRENDERPROC glBeginConditionalRender;
GLAPI PFNGLENDCONDITIONALRENDERPROC glEndConditionalRender;
GLAPI PFNGLVERTEXATTRIBIPOINTERPROC glVertexAttribIPointer;
GLAPI PFNGLGETVERTEXATTRIBIIVPROC glGetVertexAttribIiv;
GLAPI PFNGLGETVERTEXATTRIBIUIVPROC glGetVertexAttribIuiv;
GLAPI PFNGLVERTEXATTRIBI1IPROC glVertexAttribI1i;
GLAPI PFNGLVERTEXATTRIBI2IPROC glVertexAttribI2i;
GLAPI PFNGLVERTEXATTRIBI3IPROC glVertexAttribI3i;
GLAPI PFNGLVERTEXATTRIBI4IPROC glVertexAttribI4i;
GLAPI PFNGLVERTEXATTRIBI1UIPROC glVertexAttribI1ui;
GLAPI PFNGLVERTEXATTRIBI2UIPROC glVertexAttribI2ui;
GLAPI PFNGLVERTEXATTRIBI3UIPROC glVertexAttribI3ui;
GLAPI PFNGLVERTEXATTRIBI4UIPROC glVertexAttribI4ui;
GLAPI PFNGLVERTEXATTRIBI1IVPROC glVertexAttribI1iv;
GLAPI PFNGLVERTEXATTRIBI2IVPROC glVertexAttribI2iv;
GLAPI PFNGLVERTEXATTRIBI3IVPROC glVertexAttribI3iv;
GLAPI PFNGLVERTEXATTRIBI4IVPROC glVertexAttribI4iv;
GLAPI PFNGLVERTEXATTRIBI1UIVPROC glVertexAttribI1uiv;
GLAPI PFNGLVERTEXATTRIBI2UIVPROC glVertexAttribI2uiv;
GLAPI PFNGLVERTEXATTRIBI3UIVPROC glVertexAttribI3uiv;
GLAPI PFNGLVERTEXATTRIBI4UIVPROC glVertexAttribI4uiv;
GLAPI PFNGLVERTEXATTRIBI4BVPROC glVertexAttribI4bv;
GLAPI PFNGLVERTEXATTRIBI4SVPROC glVertexAttribI4sv;
GLAPI PFNGLVERTEXATTRIBI4UBVPROC glVertexAttribI4ubv;
GLAPI PFNGLVERTEXATTRIBI4USVPROC glVertexAttribI4usv;
GLAPI PFNGLGETUNIFORMUIVPROC glGetUniformuiv;
GLAPI PFNGLBINDFRAGDATALOCATIONPROC glBindFragDataLocation;
GLAPI PFNGLGETFRAGDATALOCATIONPROC glGetFragDataLocation;
GLAPI PFNGLUNIFORM1UIPROC glUniform1ui;
GLAPI PFNGLUNIFORM2UIPROC glUniform2ui;
GLAPI PFNGLUNIFORM3UIPROC glUniform3ui;
GLAPI PFNGLUNIFORM4UIPROC glUniform4ui;
GLAPI PFNGLUNIFORM1UIVPROC glUniform1uiv;
GLAPI PFNGLUNIFORM2UIVPROC glUniform2uiv;
GLAPI PFNGLUNIFORM3UIVPROC glUniform3uiv;
GLAPI PFNGLUNIFORM4UIVPROC glUniform4uiv;
GLAPI PFNGLTEXPARAMETERIIVPROC glTexParameterIiv;
GLAPI PFNGLTEXPARAMETERIUIVPROC glTexParameterIuiv;
GLAPI PFNGLGETTEXPARAMETERIIVPROC glGetTexParameterIiv;
GLAPI PFNGLGETTEXPARAMETERIUIVPROC glGetTexParameterIuiv;
GLAPI PFNGLCLEARBUFFERIVPROC glClearBufferiv;
GLAPI PFNGLCLEARBUFFERUIVPROC glClearBufferuiv;
GLAPI PFNGLCLEARBUFFERFVPROC glClearBufferfv;
GLAPI PFNGLCLEARBUFFERFIPROC glClearBufferfi;
GLAPI PFNGLGETSTRINGIPROC glGetStringi;
GLAPI PFNGLISRENDERBUFFERPROC glIsRenderbuffer;
GLAPI PFNGLBINDRENDERBUFFERPROC glBindRenderbuffer;
GLAPI PFNGLDELETERENDERBUFFERSPROC glDeleteRenderbuffers;
GLAPI PFNGLGENRENDERBUFFERSPROC glGenRenderbuffers;
GLAPI PFNGLRENDERBUFFERSTORAGEPROC glRenderbufferStorage;
GLAPI PFNGLGETRENDERBUFFERPARAMETERIVPROC glGetRenderbufferParameteriv;
GLAPI PFNGLISFRAMEBUFFERPROC glIsFramebuffer;
GLAPI PFNGLBINDFRAMEBUFFERPROC glBindFramebuffer;
GLAPI PFNGLDELETEFRAMEBUFFERSPROC glDeleteFramebuffers;
GLAPI PFNGLGENFRAMEBUFFERSPROC glGenFramebuffers;
GLAPI PFNGLCHECKFRAMEBUFFERSTATUSPROC glCheckFramebufferStatus;
GLAPI PFNGLFRAMEBUFFERTEXTURE1DPROC glFramebufferTexture1D;
GLAPI PFNGLFRAMEBUFFERTEXTURE2DPROC glFramebufferTexture2D;
GLAPI PFNGLFRAMEBUFFERTEXTURE3DPROC glFramebufferTexture3D;
GLAPI PFNGLFRAMEBUFFERRENDERBUFFERPROC glFramebufferRenderbuffer;
GLAPI PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC glGetFramebufferAttachmentParameteriv;
GLAPI PFNGLGENERATEMIPMAPPROC glGenerateMipmap;
GLAPI PFNGLBLITFRAMEBUFFERPROC glBlitFramebuffer;
GLAPI PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC glRenderbufferStorageMultisample;
GLAPI PFNGLFRAMEBUFFERTEXTURELAYERPROC glFramebufferTextureLayer;
GLAPI PFNGLMAPBUFFERRANGEPROC glMapBufferRange;
GLAPI PFNGLFLUSHMAPPEDBUFFERRANGEPROC glFlushMappedBufferRange;
GLAPI PFNGLBINDVERTEXARRAYPROC glBindVertexArray;
GLAPI PFNGLDELETEVERTEXARRAYSPROC glDeleteVertexArrays;
GLAPI PFNGLGENVERTEXARRAYSPROC glGenVertexArrays;
GLAPI PFNGLISVERTEXARRAYPROC glIsVertexArray;

// OpenGL 3.1
GLAPI PFNGLDRAWARRAYSINSTANCEDPROC glDrawArraysInstanced;
GLAPI PFNGLDRAWELEMENTSINSTANCEDPROC glDrawElementsInstanced;
GLAPI PFNGLTEXBUFFERPROC glTexBuffer;
GLAPI PFNGLPRIMITIVERESTARTINDEXPROC glPrimitiveRestartIndex;
GLAPI PFNGLCOPYBUFFERSUBDATAPROC glCopyBufferSubData;
GLAPI PFNGLGETUNIFORMINDICESPROC glGetUniformIndices;
GLAPI PFNGLGETACTIVEUNIFORMSIVPROC glGetActiveUniformsiv;
GLAPI PFNGLGETACTIVEUNIFORMNAMEPROC glGetActiveUniformName;
GLAPI PFNGLGETUNIFORMBLOCKINDEXPROC glGetUniformBlockIndex;
GLAPI PFNGLGETACTIVEUNIFORMBLOCKIVPROC glGetActiveUniformBlockiv;
GLAPI PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC glGetActiveUniformBlockName;
GLAPI PFNGLUNIFORMBLOCKBINDINGPROC glUniformBlockBinding;

// OpenGL 3.2
GLAPI PFNGLDRAWELEMENTSBASEVERTEXPROC glDrawElementsBaseVertex;
GLAPI PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC glDrawRangeElementsBaseVertex;
GLAPI PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC glDrawElementsInstancedBaseVertex;
GLAPI PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC glMultiDrawElementsBaseVertex;
GLAPI PFNGLPROVOKINGVERTEXPROC glProvokingVertex;
GLAPI PFNGLFENCESYNCPROC glFenceSync;
GLAPI PFNGLISSYNCPROC glIsSync;
GLAPI PFNGLDELETESYNCPROC glDeleteSync;
GLAPI PFNGLCLIENTWAITSYNCPROC glClientWaitSync;
GLAPI PFNGLWAITSYNCPROC glWaitSync;
GLAPI PFNGLGETINTEGER64VPROC glGetInteger64v;
GLAPI PFNGLGETSYNCIVPROC glGetSynciv;
GLAPI PFNGLGETINTEGER64I_VPROC glGetInteger64i_v;
GLAPI PFNGLGETBUFFERPARAMETERI64VPROC glGetBufferParameteri64v;
GLAPI PFNGLFRAMEBUFFERTEXTUREPROC glFramebufferTexture;
GLAPI PFNGLTEXIMAGE2DMULTISAMPLEPROC glTexImage2DMultisample;
GLAPI PFNGLTEXIMAGE3DMULTISAMPLEPROC glTexImage3DMultisample;
GLAPI PFNGLGETMULTISAMPLEFVPROC glGetMultisamplefv;
GLAPI PFNGLSAMPLEMASKIPROC glSampleMaski;

// OpenGL 3.3
GLAPI PFNGLBINDFRAGDATALOCATIONINDEXEDPROC glBindFragDataLocationIndexed;
GLAPI PFNGLGETFRAGDATAINDEXPROC glGetFragDataIndex;
GLAPI PFNGLGENSAMPLERSPROC glGenSamplers;
GLAPI PFNGLDELETESAMPLERSPROC glDeleteSamplers;
GLAPI PFNGLISSAMPLERPROC glIsSampler;
GLAPI PFNGLBINDSAMPLERPROC glBindSampler;
GLAPI PFNGLSAMPLERPARAMETERIPROC glSamplerParameteri;
GLAPI PFNGLSAMPLERPARAMETERIVPROC glSamplerParameteriv;
GLAPI PFNGLSAMPLERPARAMETERFPROC glSamplerParameterf;
GLAPI PFNGLSAMPLERPARAMETERFVPROC glSamplerParameterfv;
GLAPI PFNGLSAMPLERPARAMETERIIVPROC glSamplerParameterIiv;
GLAPI PFNGLSAMPLERPARAMETERIUIVPROC glSamplerParameterIuiv;
GLAPI PFNGLGETSAMPLERPARAMETERIVPROC glGetSamplerParameteriv;
GLAPI PFNGLGETSAMPLERPARAMETERIIVPROC glGetSamplerParameterIiv;
GLAPI PFNGLGETSAMPLERPARAMETERFVPROC glGetSamplerParameterfv;
GLAPI PFNGLGETSAMPLERPARAMETERIUIVPROC glGetSamplerParameterIuiv;
GLAPI PFNGLQUERYCOUNTERPROC glQueryCounter;
GLAPI PFNGLGETQUERYOBJECTI64VPROC glGetQueryObjecti64v;
GLAPI PFNGLGETQUERYOBJECTUI64VPROC glGetQueryObjectui64v;
GLAPI PFNGLVERTEXATTRIBDIVISORPROC glVertexAttribDivisor;
GLAPI PFNGLVERTEXATTRIBP1UIPROC glVertexAttribP1ui;
GLAPI PFNGLVERTEXATTRIBP1UIVPROC glVertexAttribP1uiv;
GLAPI PFNGLVERTEXATTRIBP2UIPROC glVertexAttribP2ui;
GLAPI PFNGLVERTEXATTRIBP2UIVPROC glVertexAttribP2uiv;
GLAPI PFNGLVERTEXATTRIBP3UIPROC glVertexAttribP3ui;
GLAPI PFNGLVERTEXATTRIBP3UIVPROC glVertexAttribP3uiv;
GLAPI PFNGLVERTEXATTRIBP4UIPROC glVertexAttribP4ui;
GLAPI PFNGLVERTEXATTRIBP4UIVPROC glVertexAttribP4uiv;

// OpenGL 4.0
GLAPI PFNGLMINSAMPLESHADINGPROC glMinSampleShading;
GLAPI PFNGLBLENDEQUATIONIPROC glBlendEquationi;
GLAPI PFNGLBLENDEQUATIONSEPARATEIPROC glBlendEquationSeparatei;
GLAPI PFNGLBLENDFUNCIPROC glBlendFunci;
GLAPI PFNGLBLENDFUNCSEPARATEIPROC glBlendFuncSeparatei;
GLAPI PFNGLDRAWARRAYSINDIRECTPROC glDrawArraysIndirect;
GLAPI PFNGLDRAWELEMENTSINDIRECTPROC glDrawElementsIndirect;
GLAPI PFNGLUNIFORM1DPROC glUniform1d;
GLAPI PFNGLUNIFORM2DPROC glUniform2d;
GLAPI PFNGLUNIFORM3DPROC glUniform3d;
GLAPI PFNGLUNIFORM4DPROC glUniform4d;
GLAPI PFNGLUNIFORM1DVPROC glUniform1dv;
GLAPI PFNGLUNIFORM2DVPROC glUniform2dv;
GLAPI PFNGLUNIFORM3DVPROC glUniform3dv;
GLAPI PFNGLUNIFORM4DVPROC glUniform4dv;
GLAPI PFNGLUNIFORMMATRIX2DVPROC glUniformMatrix2dv;
GLAPI PFNGLUNIFORMMATRIX3DVPROC glUniformMatrix3dv;
GLAPI PFNGLUNIFORMMATRIX4DVPROC glUniformMatrix4dv;
GLAPI PFNGLUNIFORMMATRIX2X3DVPROC glUniformMatrix2x3dv;
GLAPI PFNGLUNIFORMMATRIX2X4DVPROC glUniformMatrix2x4dv;
GLAPI PFNGLUNIFORMMATRIX3X2DVPROC glUniformMatrix3x2dv;
GLAPI PFNGLUNIFORMMATRIX3X4DVPROC glUniformMatrix3x4dv;
GLAPI PFNGLUNIFORMMATRIX4X2DVPROC glUniformMatrix4x2dv;
GLAPI PFNGLUNIFORMMATRIX4X3DVPROC glUniformMatrix4x3dv;
GLAPI PFNGLGETUNIFORMDVPROC glGetUniformdv;
GLAPI PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC glGetSubroutineUniformLocation;
GLAPI PFNGLGETSUBROUTINEINDEXPROC glGetSubroutineIndex;
GLAPI PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC glGetActiveSubroutineUniformiv;
GLAPI PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC glGetActiveSubroutineUniformName;
GLAPI PFNGLGETACTIVESUBROUTINENAMEPROC glGetActiveSubroutineName;
GLAPI PFNGLUNIFORMSUBROUTINESUIVPROC glUniformSubroutinesuiv;
GLAPI PFNGLGETUNIFORMSUBROUTINEUIVPROC glGetUniformSubroutineuiv;
GLAPI PFNGLGETPROGRAMSTAGEIVPROC glGetProgramStageiv;
GLAPI PFNGLPATCHPARAMETERIPROC glPatchParameteri;
GLAPI PFNGLPATCHPARAMETERFVPROC glPatchParameterfv;
GLAPI PFNGLBINDTRANSFORMFEEDBACKPROC glBindTransformFeedback;
GLAPI PFNGLDELETETRANSFORMFEEDBACKSPROC glDeleteTransformFeedbacks;
GLAPI PFNGLGENTRANSFORMFEEDBACKSPROC glGenTransformFeedbacks;
GLAPI PFNGLISTRANSFORMFEEDBACKPROC glIsTransformFeedback;
GLAPI PFNGLPAUSETRANSFORMFEEDBACKPROC glPauseTransformFeedback;
GLAPI PFNGLRESUMETRANSFORMFEEDBACKPROC glResumeTransformFeedback;
GLAPI PFNGLDRAWTRANSFORMFEEDBACKPROC glDrawTransformFeedback;
GLAPI PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC glDrawTransformFeedbackStream;
GLAPI PFNGLBEGINQUERYINDEXEDPROC glBeginQueryIndexed;
GLAPI PFNGLENDQUERYINDEXEDPROC glEndQueryIndexed;
GLAPI PFNGLGETQUERYINDEXEDIVPROC glGetQueryIndexediv;

// OpenGL 4.1
GLAPI PFNGLRELEASESHADERCOMPILERPROC glReleaseShaderCompiler;
GLAPI PFNGLSHADERBINARYPROC glShaderBinary;
GLAPI PFNGLGETSHADERPRECISIONFORMATPROC glGetShaderPrecisionFormat;
GLAPI PFNGLDEPTHRANGEFPROC glDepthRangef;
GLAPI PFNGLCLEARDEPTHFPROC glClearDepthf;
GLAPI PFNGLGETPROGRAMBINARYPROC glGetProgramBinary;
GLAPI PFNGLPROGRAMBINARYPROC glProgramBinary;
GLAPI PFNGLPROGRAMPARAMETERIPROC glProgramParameteri;
GLAPI PFNGLUSEPROGRAMSTAGESPROC glUseProgramStages;
GLAPI PFNGLACTIVESHADERPROGRAMPROC glActiveShaderProgram;
GLAPI PFNGLCREATESHADERPROGRAMVPROC glCreateShaderProgramv;
GLAPI PFNGLBINDPROGRAMPIPELINEPROC glBindProgramPipeline;
GLAPI PFNGLDELETEPROGRAMPIPELINESPROC glDeleteProgramPipelines;
GLAPI PFNGLGENPROGRAMPIPELINESPROC glGenProgramPipelines;
GLAPI PFNGLISPROGRAMPIPELINEPROC glIsProgramPipeline;
GLAPI PFNGLGETPROGRAMPIPELINEIVPROC glGetProgramPipelineiv;
GLAPI PFNGLPROGRAMUNIFORM1IPROC glProgramUniform1i;
GLAPI PFNGLPROGRAMUNIFORM1IVPROC glProgramUniform1iv;
GLAPI PFNGLPROGRAMUNIFORM1FPROC glProgramUniform1f;
GLAPI PFNGLPROGRAMUNIFORM1FVPROC glProgramUniform1fv;
GLAPI PFNGLPROGRAMUNIFORM1DPROC glProgramUniform1d;
GLAPI PFNGLPROGRAMUNIFORM1DVPROC glProgramUniform1dv;
GLAPI PFNGLPROGRAMUNIFORM1UIPROC glProgramUniform1ui;
GLAPI PFNGLPROGRAMUNIFORM1UIVPROC glProgramUniform1uiv;
GLAPI PFNGLPROGRAMUNIFORM2IPROC glProgramUniform2i;
GLAPI PFNGLPROGRAMUNIFORM2IVPROC glProgramUniform2iv;
GLAPI PFNGLPROGRAMUNIFORM2FPROC glProgramUniform2f;
GLAPI PFNGLPROGRAMUNIFORM2FVPROC glProgramUniform2fv;
GLAPI PFNGLPROGRAMUNIFORM2DPROC glProgramUniform2d;
GLAPI PFNGLPROGRAMUNIFORM2DVPROC glProgramUniform2dv;
GLAPI PFNGLPROGRAMUNIFORM2UIPROC glProgramUniform2ui;
GLAPI PFNGLPROGRAMUNIFORM2UIVPROC glProgramUniform2uiv;
GLAPI PFNGLPROGRAMUNIFORM3IPROC glProgramUniform3i;
GLAPI PFNGLPROGRAMUNIFORM3IVPROC glProgramUniform3iv;
GLAPI PFNGLPROGRAMUNIFORM3FPROC glProgramUniform3f;
GLAPI PFNGLPROGRAMUNIFORM3FVPROC glProgramUniform3fv;
GLAPI PFNGLPROGRAMUNIFORM3DPROC glProgramUniform3d;
GLAPI PFNGLPROGRAMUNIFORM3DVPROC glProgramUniform3dv;
GLAPI PFNGLPROGRAMUNIFORM3UIPROC glProgramUniform3ui;
GLAPI PFNGLPROGRAMUNIFORM3UIVPROC glProgramUniform3uiv;
GLAPI PFNGLPROGRAMUNIFORM4IPROC glProgramUniform4i;
GLAPI PFNGLPROGRAMUNIFORM4IVPROC glProgramUniform4iv;
GLAPI PFNGLPROGRAMUNIFORM4FPROC glProgramUniform4f;
GLAPI PFNGLPROGRAMUNIFORM4FVPROC glProgramUniform4fv;
GLAPI PFNGLPROGRAMUNIFORM4DPROC glProgramUniform4d;
GLAPI PFNGLPROGRAMUNIFORM4DVPROC glProgramUniform4dv;
GLAPI PFNGLPROGRAMUNIFORM4UIPROC glProgramUniform4ui;
GLAPI PFNGLPROGRAMUNIFORM4UIVPROC glProgramUniform4uiv;
GLAPI PFNGLPROGRAMUNIFORMMATRIX2FVPROC glProgramUniformMatrix2fv;
GLAPI PFNGLPROGRAMUNIFORMMATRIX3FVPROC glProgramUniformMatrix3fv;
GLAPI PFNGLPROGRAMUNIFORMMATRIX4FVPROC glProgramUniformMatrix4fv;
GLAPI PFNGLPROGRAMUNIFORMMATRIX2DVPROC glProgramUniformMatrix2dv;
GLAPI PFNGLPROGRAMUNIFORMMATRIX3DVPROC glProgramUniformMatrix3dv;
GLAPI PFNGLPROGRAMUNIFORMMATRIX4DVPROC glProgramUniformMatrix4dv;
GLAPI PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC glProgramUniformMatrix2x3fv;
GLAPI PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC glProgramUniformMatrix3x2fv;
GLAPI PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC glProgramUniformMatrix2x4fv;
GLAPI PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC glProgramUniformMatrix4x2fv;
GLAPI PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC glProgramUniformMatrix3x4fv;
GLAPI PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC glProgramUniformMatrix4x3fv;
GLAPI PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC glProgramUniformMatrix2x3dv;
GLAPI PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC glProgramUniformMatrix3x2dv;
GLAPI PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC glProgramUniformMatrix2x4dv;
GLAPI PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC glProgramUniformMatrix4x2dv;
GLAPI PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC glProgramUniformMatrix3x4dv;
GLAPI PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC glProgramUniformMatrix4x3dv;
GLAPI PFNGLVALIDATEPROGRAMPIPELINEPROC glValidateProgramPipeline;
GLAPI PFNGLGETPROGRAMPIPELINEINFOLOGPROC glGetProgramPipelineInfoLog;
GLAPI PFNGLVERTEXATTRIBL1DPROC glVertexAttribL1d;
GLAPI PFNGLVERTEXATTRIBL2DPROC glVertexAttribL2d;
GLAPI PFNGLVERTEXATTRIBL3DPROC glVertexAttribL3d;
GLAPI PFNGLVERTEXATTRIBL4DPROC glVertexAttribL4d;
GLAPI PFNGLVERTEXATTRIBL1DVPROC glVertexAttribL1dv;
GLAPI PFNGLVERTEXATTRIBL2DVPROC glVertexAttribL2dv;
GLAPI PFNGLVERTEXATTRIBL3DVPROC glVertexAttribL3dv;
GLAPI PFNGLVERTEXATTRIBL4DVPROC glVertexAttribL4dv;
GLAPI PFNGLVERTEXATTRIBLPOINTERPROC glVertexAttribLPointer;
GLAPI PFNGLGETVERTEXATTRIBLDVPROC glGetVertexAttribLdv;
GLAPI PFNGLVIEWPORTARRAYVPROC glViewportArrayv;
GLAPI PFNGLVIEWPORTINDEXEDFPROC glViewportIndexedf;
GLAPI PFNGLVIEWPORTINDEXEDFVPROC glViewportIndexedfv;
GLAPI PFNGLSCISSORARRAYVPROC glScissorArrayv;
GLAPI PFNGLSCISSORINDEXEDPROC glScissorIndexed;
GLAPI PFNGLSCISSORINDEXEDVPROC glScissorIndexedv;
GLAPI PFNGLDEPTHRANGEARRAYVPROC glDepthRangeArrayv;
GLAPI PFNGLDEPTHRANGEINDEXEDPROC glDepthRangeIndexed;
GLAPI PFNGLGETFLOATI_VPROC glGetFloati_v;
GLAPI PFNGLGETDOUBLEI_VPROC glGetDoublei_v;

// OpenGL 4.2
GLAPI PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC glDrawArraysInstancedBaseInstance;
GLAPI PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC glDrawElementsInstancedBaseInstance;
GLAPI PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC glDrawElementsInstancedBaseVertexBaseInstance;
GLAPI PFNGLGETINTERNALFORMATIVPROC glGetInternalformativ;
GLAPI PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC glGetActiveAtomicCounterBufferiv;
GLAPI PFNGLBINDIMAGETEXTUREPROC glBindImageTexture;
GLAPI PFNGLMEMORYBARRIERPROC glMemoryBarrier;
GLAPI PFNGLTEXSTORAGE1DPROC glTexStorage1D;
GLAPI PFNGLTEXSTORAGE2DPROC glTexStorage2D;
GLAPI PFNGLTEXSTORAGE3DPROC glTexStorage3D;
GLAPI PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC glDrawTransformFeedbackInstanced;
GLAPI PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC glDrawTransformFeedbackStreamInstanced;

// OpenGL 4.3
GLAPI PFNGLCLEARBUFFERDATAPROC glClearBufferData;
GLAPI PFNGLCLEARBUFFERSUBDATAPROC glClearBufferSubData;
GLAPI PFNGLDISPATCHCOMPUTEPROC glDispatchCompute;
GLAPI PFNGLDISPATCHCOMPUTEINDIRECTPROC glDispatchComputeIndirect;
GLAPI PFNGLCOPYIMAGESUBDATAPROC glCopyImageSubData;
GLAPI PFNGLFRAMEBUFFERPARAMETERIPROC glFramebufferParameteri;
GLAPI PFNGLGETFRAMEBUFFERPARAMETERIVPROC glGetFramebufferParameteriv;
GLAPI PFNGLGETINTERNALFORMATI64VPROC glGetInternalFormati64v;
GLAPI PFNGLINVALIDATETEXSUBIMAGEPROC glInvalidateTexSubImage;
GLAPI PFNGLINVALIDATETEXIMAGEPROC glInvalidateTexImage;
GLAPI PFNGLINVALIDATEBUFFERSUBDATAPROC glInvalidateBufferSubData;
GLAPI PFNGLINVALIDATEBUFFERDATAPROC glInvalidateBufferData;
GLAPI PFNGLINVALIDATEFRAMEBUFFERPROC glInvalidateFramebuffer;
GLAPI PFNGLINVALIDATESUBFRAMEBUFFERPROC glInvalidateSubFramebuffer;
GLAPI PFNGLMULTIDRAWARRAYSINDIRECTPROC glMultiDrawArraysIndirect;
GLAPI PFNGLMULTIDRAWELEMENTSINDIRECTPROC glMultiDrawElementsIndirect;
GLAPI PFNGLGETPROGRAMINTERFACEIVPROC glGetProgramInterfaceiv;
GLAPI PFNGLGETPROGRAMRESOURCEINDEXPROC glGetProgramResourceIndex;
GLAPI PFNGLGETPROGRAMRESOURCENAMEPROC glGetProgramResourceName;
GLAPI PFNGLGETPROGRAMRESOURCEIVPROC glGetProgramResourceiv;
GLAPI PFNGLGETPROGRAMRESOURCELOCATIONPROC glGetProgramResourceLocation;
GLAPI PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC glGetProgramResourceLocationIndex;
GLAPI PFNGLSHADERSTORAGEBLOCKBINDINGPROC glShaderStorageBlockBinding;
GLAPI PFNGLTEXBUFFERRANGEPROC glTexBufferRange;
GLAPI PFNGLTEXSTORAGE2DMULTISAMPLEPROC glTexStorage2DMultiSample;
GLAPI PFNGLTEXSTORAGE3DMULTISAMPLEPROC glTexStorage2DMultisample;
GLAPI PFNGLTEXTUREVIEWPROC glTextureView;
GLAPI PFNGLBINDVERTEXBUFFERPROC glBindVertexBuffer;
GLAPI PFNGLVERTEXATTRIBFORMATPROC glVertexAttribFormat;
GLAPI PFNGLVERTEXATTRIBIFORMATPROC glVertexAttribIFormat;
GLAPI PFNGLVERTEXATTRIBLFORMATPROC glVertexAttribLFormat;
GLAPI PFNGLVERTEXATTRIBBINDINGPROC glVertexAttribBinding;
GLAPI PFNGLVERTEXBINDINGDIVISORPROC glVertexBindingDivisor;
GLAPI PFNGLDEBUGMESSAGECONTROLPROC glDebugMessageControl;
GLAPI PFNGLDEBUGMESSAGEINSERTPROC glDebugMessageInsert;
GLAPI PFNGLDEBUGMESSAGECALLBACKPROC glDebugMessageCallback;
GLAPI PFNGLGETDEBUGMESSAGELOGPROC glGetDebugMessageLog;
GLAPI PFNGLPUSHDEBUGGROUPPROC glPushDebugGroup;
GLAPI PFNGLPOPDEBUGGROUPPROC glPopDebugGroup;
GLAPI PFNGLOBJECTLABELPROC glObjectLabel;
GLAPI PFNGLGETOBJECTLABELPROC glGetObjectLabel;
GLAPI PFNGLOBJECTPTRLABELPROC glObjectPtrLabel;
GLAPI PFNGLGETOBJECTPTRLABELPROC glGetObjectPtrLabel;

// OpenGL 4.4
GLAPI PFNGLBUFFERSTORAGEPROC glBufferStorage;
GLAPI PFNGLCLEARTEXIMAGEPROC glClearTexImage;
GLAPI PFNGLCLEARTEXSUBIMAGEPROC glClearTexSubImage;
GLAPI PFNGLBINDBUFFERSBASEPROC glBindBuffersBase;
GLAPI PFNGLBINDBUFFERSRANGEPROC glBindBuffersRange;
GLAPI PFNGLBINDTEXTURESPROC glBindTextures;
GLAPI PFNGLBINDSAMPLERSPROC glBindSamplers;
GLAPI PFNGLBINDIMAGETEXTURESPROC glBindImageTextures;
GLAPI PFNGLBINDVERTEXBUFFERSPROC glBindVertexBuffers;

// OpenGL 4.5
GLAPI PFNGLCLIPCONTROLPROC glClipControl;
GLAPI PFNGLCREATETRANSFORMFEEDBACKSPROC glCreateTransformFeedbacks;
GLAPI PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC glTransformFeedbackBufferBase;
GLAPI PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC glTransformFeedbackBufferRange;
GLAPI PFNGLGETTRANSFORMFEEDBACKIVPROC glGetTransformFeedbackiv;
GLAPI PFNGLGETTRANSFORMFEEDBACKI_VPROC glGetTransformFeedbacki_v;
GLAPI PFNGLGETTRANSFORMFEEDBACKI64_VPROC glGetTransformFeedbacki64_v;
GLAPI PFNGLCREATEBUFFERSPROC glCreateBuffers;
GLAPI PFNGLNAMEDBUFFERSTORAGEPROC glNamedBufferStorage;
GLAPI PFNGLNAMEDBUFFERDATAPROC glNamedBufferData;
GLAPI PFNGLNAMEDBUFFERSUBDATAPROC glNamedBufferSubData;
GLAPI PFNGLCOPYNAMEDBUFFERSUBDATAPROC glCopyNamedBufferSubData;
GLAPI PFNGLCLEARNAMEDBUFFERDATAPROC glClearNamedBufferData;
GLAPI PFNGLCLEARNAMEDBUFFERSUBDATAPROC glClearNamedBufferSubData;
GLAPI PFNGLMAPNAMEDBUFFERPROC glMapNamedBuffer;
GLAPI PFNGLMAPNAMEDBUFFERRANGEPROC glMapNamedBufferRange;
GLAPI PFNGLUNMAPNAMEDBUFFERPROC glUnmapNamedBuffer;
GLAPI PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC glFlushMappedNamedBufferRange;
GLAPI PFNGLGETNAMEDBUFFERPARAMETERIVPROC glGetNamedBufferParameteriv;
GLAPI PFNGLGETNAMEDBUFFERPARAMETERI64VPROC glGetNamedBufferParameteri64v;
GLAPI PFNGLGETNAMEDBUFFERPOINTERVPROC glGetNamedBufferPointerv;
GLAPI PFNGLGETNAMEDBUFFERSUBDATAPROC glGetNamedBufferSubData;
GLAPI PFNGLCREATEFRAMEBUFFERSPROC glCreateFramebuffers;
GLAPI PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC glNamedFramebufferRenderbuffer;
GLAPI PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC glNamedFramebufferParameteri;
GLAPI PFNGLNAMEDFRAMEBUFFERTEXTUREPROC glNamedFramebufferTexture;
GLAPI PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC glNamedFramebufferTextureLayer;
GLAPI PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC glNamedFramebufferDrawBuffer;
GLAPI PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC glNamedFramebufferDrawBuffers;
GLAPI PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC glNamedFramebufferReadBuffer;
GLAPI PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC glInvalidateNamedFramebufferData;
GLAPI PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC glInvalidateNamedFramebufferSubData;
GLAPI PFNGLCLEARNAMEDFRAMEBUFFERIVPROC glClearNamedFramebufferiv;
GLAPI PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC glClearNamedFramebufferuiv;
GLAPI PFNGLCLEARNAMEDFRAMEBUFFERFVPROC glClearNamedFramebufferfv;
GLAPI PFNGLCLEARNAMEDFRAMEBUFFERFIPROC glClearNamedFramebufferfi;
GLAPI PFNGLBLITNAMEDFRAMEBUFFERPROC glBlitNamedFramebuffer;
GLAPI PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC glCheckNamedFramebufferStatus;
GLAPI PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC glGetNamedFramebufferParameteriv;
GLAPI PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC glGetNamedFramebufferAttachmentParameteriv;
GLAPI PFNGLCREATERENDERBUFFERSPROC glCreateRenderbuffers;
GLAPI PFNGLNAMEDRENDERBUFFERSTORAGEPROC glNamedRenderbufferStorage;
GLAPI PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC glNamedRenderbufferStorageMultisample;
GLAPI PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC glGetNamedRenderbufferParameteriv;
GLAPI PFNGLCREATETEXTURESPROC glCreateTextures;
GLAPI PFNGLTEXTUREBUFFERPROC glTextureBuffer;
GLAPI PFNGLTEXTUREBUFFERRANGEPROC glTextureBufferRange;
GLAPI PFNGLTEXTURESTORAGE1DPROC glTextureStorage1D;
GLAPI PFNGLTEXTURESTORAGE2DPROC glTextureStorage2D;
GLAPI PFNGLTEXTURESTORAGE3DPROC glTextureStorage3D;
GLAPI PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC glTextureStorage2DMultisample;
GLAPI PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC glTextureStorage3DMultisample;
GLAPI PFNGLTEXTURESUBIMAGE1DPROC glTextureSubImage1D;
GLAPI PFNGLTEXTURESUBIMAGE2DPROC glTextureSubImage2D;
GLAPI PFNGLTEXTURESUBIMAGE3DPROC glTextureSubImage3D;
GLAPI PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC glCompressedTextureSubImage1D;
GLAPI PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC glCompressedTextureSubImage2D;
GLAPI PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC glCompressedTextureSubImage3D;
GLAPI PFNGLCOPYTEXTURESUBIMAGE1DPROC glCopyTextureSubImage1D;
GLAPI PFNGLCOPYTEXTURESUBIMAGE2DPROC glCopyTextureSubImage2D;
GLAPI PFNGLCOPYTEXTURESUBIMAGE3DPROC glCopyTextureSubImage3D;
GLAPI PFNGLTEXTUREPARAMETERFPROC glTextureParameterf;
GLAPI PFNGLTEXTUREPARAMETERFVPROC glTextureParameterfv;
GLAPI PFNGLTEXTUREPARAMETERIPROC glTextureParameteri;
GLAPI PFNGLTEXTUREPARAMETERIIVPROC glTextureParameterIiv;
GLAPI PFNGLTEXTUREPARAMETERIUIVPROC glTextureParameterIuiv;
GLAPI PFNGLTEXTUREPARAMETERIVPROC glTextureParameteriv;
GLAPI PFNGLGENERATETEXTUREMIPMAPPROC glGenerateTextureMipmap;
GLAPI PFNGLBINDTEXTUREUNITPROC glBindTextureUnit;
GLAPI PFNGLGETTEXTUREIMAGEPROC glGetTextureImage;
GLAPI PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC glGetCompressedTextureImage;
GLAPI PFNGLGETTEXTURELEVELPARAMETERFVPROC glGetTextureLevelParameterfv;
GLAPI PFNGLGETTEXTURELEVELPARAMETERIVPROC glGetTextureLevelParameteriv;
GLAPI PFNGLGETTEXTUREPARAMETERFVPROC glGetTextureParameterfv;
GLAPI PFNGLGETTEXTUREPARAMETERIIVPROC glGetTextureParameterIiv;
GLAPI PFNGLGETTEXTUREPARAMETERIUIVPROC glGetTextureParameterIuiv;
GLAPI PFNGLGETTEXTUREPARAMETERIVPROC glGetTextureParameteriv;
GLAPI PFNGLCREATEVERTEXARRAYSPROC glCreateVertexArrays;
GLAPI PFNGLDISABLEVERTEXARRAYATTRIBPROC glDisableVertexArrayAttrib;
GLAPI PFNGLENABLEVERTEXARRAYATTRIBPROC glEnableVertexArrayAttrib;
GLAPI PFNGLVERTEXARRAYELEMENTBUFFERPROC glVertexArrayElementBuffer;
GLAPI PFNGLVERTEXARRAYVERTEXBUFFERPROC glVertexArrayVertexBuffer;
GLAPI PFNGLVERTEXARRAYVERTEXBUFFERSPROC glVertexArrayVertexBuffers;
GLAPI PFNGLVERTEXARRAYATTRIBBINDINGPROC glVertexArrayAttribBinding;
GLAPI PFNGLVERTEXARRAYATTRIBFORMATPROC glVertexArrayAttribFormat;
GLAPI PFNGLVERTEXARRAYATTRIBIFORMATPROC glVertexArrayAttribIFormat;
GLAPI PFNGLVERTEXARRAYATTRIBLFORMATPROC glVertexArrayAttribLFormat;
GLAPI PFNGLVERTEXARRAYBINDINGDIVISORPROC glVertexArrayBindingDivisor;
GLAPI PFNGLGETVERTEXARRAYIVPROC glGetVertexArrayiv;
GLAPI PFNGLGETVERTEXARRAYINDEXEDIVPROC glGetVertexArrayIndexediv;
GLAPI PFNGLGETVERTEXARRAYINDEXED64IVPROC glGetVertexArrayIndexed64iv;
GLAPI PFNGLCREATESAMPLERSPROC glCreateSamplers;
GLAPI PFNGLCREATEPROGRAMPIPELINESPROC glCreateProgramPipelines;
GLAPI PFNGLCREATEQUERIESPROC glCreateQueries;
GLAPI PFNGLGETQUERYBUFFEROBJECTI64VPROC glGetQueryBufferObjecti64v;
GLAPI PFNGLGETQUERYBUFFEROBJECTIVPROC glGetQueryBufferObjectiv;
GLAPI PFNGLGETQUERYBUFFEROBJECTUI64VPROC glGetQueryBufferObjectui64v;
GLAPI PFNGLGETQUERYBUFFEROBJECTUIVPROC glGetQueryBufferObjectuiv;
GLAPI PFNGLMEMORYBARRIERBYREGIONPROC glMemoryBarrierByRegion;
GLAPI PFNGLGETTEXTURESUBIMAGEPROC glGetTextureSubImage;
GLAPI PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC glGetCompressedTextureSubImage;
GLAPI PFNGLGETGRAPHICSRESETSTATUSPROC glGetGraphicsResetStatus;
GLAPI PFNGLGETNCOMPRESSEDTEXIMAGEPROC glGetnCompressedTexImage;
GLAPI PFNGLGETNTEXIMAGEPROC glGetnTexImage;
GLAPI PFNGLGETNUNIFORMDVPROC glGetnUniformdv;
GLAPI PFNGLGETNUNIFORMFVPROC glGetnUniformfv;
GLAPI PFNGLGETNUNIFORMIVPROC glGetnUniformiv;
GLAPI PFNGLGETUNIFORMUIVPROC glGetnUniformuiv;
GLAPI PFNGLREADNPIXELSPROC glReadnPixels;
GLAPI PFNGLTEXTUREBARRIERPROC glTextureBarrier;

#endif //__GL_LOADER_H__
