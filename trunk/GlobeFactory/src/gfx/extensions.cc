#include "extensions.hh"
#include "../useful/all.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

// VBO
PFNGLGENBUFFERSPROC        glGenBuffers        = NULL;
// SHADERS
PFNGLUSEPROGRAMPROC        glUseProgram        = NULL;
PFNGLCREATEPROGRAMPROC     glCreateProgram     = NULL;
PFNGLATTACHSHADERPROC      glAttachShader      = NULL;
PFNGLLINKPROGRAMPROC       glLinkProgram       = NULL;
PFNGLGETPROGRAMIVPROC      glGetProgramiv      = NULL;
PFNGLGETPROGRAMINFOLOGPROC glGetProgramInfoLog = NULL;
PFNGLDELETESHADERPROC      glDeleteShader      = NULL;
PFNGLDELETEPROGRAMPROC     glDeleteProgram     = NULL;
PFNGLCREATESHADERPROC      glCreateShader      = NULL;
PFNGLSHADERSOURCEPROC      glShaderSource      = NULL;
PFNGLCOMPILESHADERPROC     glCompileShader     = NULL;
PFNGLGETSHADERIVPROC       glGetShaderiv       = NULL;
PFNGLGETSHADERINFOLOGPROC  glGetShaderInfoLog  = NULL;

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

bool IsExtensionSupported(const std::string& parExtension)
{
  const std::string exts((const char*)glGetString(GL_EXTENSIONS));
  return (exts.find(parExtension) != std::string::npos);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void InitExtensions()
{
  // VBO
  glGenBuffers = (PFNGLGENBUFFERSPROC)SDL_GL_GetProcAddress("glGenBuffers");

  // SHADERS
  if (!IsExtensionSupported("GL_ARB_shading_language_100") ||
      !IsExtensionSupported("GL_ARB_shader_objects")       ||
      !IsExtensionSupported("GL_ARB_vertex_shader")        ||
      !IsExtensionSupported("GL_ARB_fragment_shader"))
  {
    LOG_ERROR("Extensions", "Shaders not supported. GlobeFactory will crash.");
    LOG_ASSERT(true);
  }

  glUseProgram        = (PFNGLUSEPROGRAMPROC)SDL_GL_GetProcAddress("glUseProgram");
  glCreateProgram     = (PFNGLCREATEPROGRAMPROC)SDL_GL_GetProcAddress("glCreateProgram");
  glAttachShader      = (PFNGLATTACHSHADERPROC)SDL_GL_GetProcAddress("glAttachShader");
  glLinkProgram       = (PFNGLLINKPROGRAMPROC)SDL_GL_GetProcAddress("glLinkProgram");
  glGetProgramiv      = (PFNGLGETPROGRAMIVPROC)SDL_GL_GetProcAddress("glGetProgramiv");
  glGetProgramInfoLog = (PFNGLGETPROGRAMINFOLOGPROC)SDL_GL_GetProcAddress("glGetProgramInfoLog");
  glDeleteShader      = (PFNGLDELETESHADERPROC)SDL_GL_GetProcAddress("glDeleteShader");
  glDeleteProgram     = (PFNGLDELETEPROGRAMPROC)SDL_GL_GetProcAddress("glDeleteProgram");
  glCreateShader      = (PFNGLCREATESHADERPROC)SDL_GL_GetProcAddress("glCreateShader");
  glShaderSource      = (PFNGLSHADERSOURCEPROC)SDL_GL_GetProcAddress("glShaderSource");
  glCompileShader     = (PFNGLCOMPILESHADERPROC)SDL_GL_GetProcAddress("glCompileShader");
  glGetShaderiv       = (PFNGLGETSHADERIVPROC)SDL_GL_GetProcAddress("glGetShaderiv");
  glGetShaderInfoLog  = (PFNGLGETSHADERINFOLOGPROC)SDL_GL_GetProcAddress("glGetShaderInfoLog");

  if (glUseProgram   && glCreateProgram && glAttachShader      &&
      glLinkProgram  && glGetProgramiv  && glGetProgramInfoLog &&
      glDeleteShader && glDeleteProgram && glCreateShader      &&
      glShaderSource && glCompileShader && glGetShaderiv       && glGetShaderInfoLog)
    LOG_RESUME("Extensions", "Shaders supported and loaded.");
  else
    LOG_ERROR("Extensions", "Shaders supported but not loaded.");
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
