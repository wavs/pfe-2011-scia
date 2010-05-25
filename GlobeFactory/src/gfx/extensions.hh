////////////////////////////////////////////////////////////////////////////////
// Filename  : extensions.hh
// Authors   : Creteur Clement
// Last edit : 15/04/10 - 23h30
// Comment   :
////////////////////////////////////////////////////////////////////////////////
#ifndef GFX_EXTENSIONS_HH
#define GFX_EXTENSIONS_HH

#include <string>
#include "glext.h"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

// VBO
extern PFNGLGENBUFFERSPROC        glGenBuffers;
// SHADERS
extern PFNGLUSEPROGRAMPROC        glUseProgram;
extern PFNGLCREATEPROGRAMPROC     glCreateProgram;
extern PFNGLATTACHSHADERPROC      glAttachShader;
extern PFNGLLINKPROGRAMPROC       glLinkProgram;
extern PFNGLGETPROGRAMIVPROC      glGetProgramiv;
extern PFNGLGETPROGRAMINFOLOGPROC glGetProgramInfoLog;
extern PFNGLDELETESHADERPROC      glDeleteShader;
extern PFNGLDELETEPROGRAMPROC     glDeleteProgram;
extern PFNGLCREATESHADERPROC      glCreateShader;
extern PFNGLSHADERSOURCEPROC      glShaderSource;
extern PFNGLCOMPILESHADERPROC     glCompileShader;
extern PFNGLGETSHADERIVPROC       glGetShaderiv;
extern PFNGLGETSHADERINFOLOGPROC  glGetShaderInfoLog;

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

bool IsExtensionSupported(const std::string& parExtension);
void InitExtensions();

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
