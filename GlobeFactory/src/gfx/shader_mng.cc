#include "shader_mng.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

ShaderMng::ShaderMng()
{
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

ShaderMng::~ShaderMng()
{
  foreach(shader, MShaders)
  if (shader->second != 0)
    glDeleteShader(shader->second);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

unsigned ShaderMng::LoadVertexShader(const std::string& parFilename)
{
  if (MShaders.count(parFilename) == 0)
    MShaders[parFilename] = LoadShader(GL_VERTEX_SHADER, parFilename.c_str());
  return MShaders[parFilename];
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

unsigned ShaderMng::LoadPixelShader(const std::string& parFilename)
{
  if (MShaders.count(parFilename) == 0)
    MShaders[parFilename] = LoadShader(GL_FRAGMENT_SHADER, parFilename.c_str());
  return MShaders[parFilename];
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

unsigned ShaderMng::LoadShader(GLenum type, const char* filename)
{
  GLuint shader = 0;
  GLsizei logsize = 0;
  GLint compile_status = GL_TRUE;
  char *log = NULL;
  char *src = NULL;

  shader = glCreateShader(type);
  if(shader == 0)
  {
    LOG_WARNING("ShaderMng", "Impossible de creer le shader " + std::string(filename));
    return 0;
  }

  src = LoadSource(filename);
  if(src == NULL)
  {
    glDeleteShader(shader);
    return 0;
  }

  glShaderSource(shader, 1, (const GLchar**)&src, NULL);
  glCompileShader(shader);
  free(src);

  glGetShaderiv(shader, GL_COMPILE_STATUS, &compile_status);
  if(compile_status != GL_TRUE)
  {
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logsize);
    log = (char*)malloc(logsize + 1);
    memset(log, '\0', logsize + 1);
    glGetShaderInfoLog(shader, logsize, &logsize, log);
    LOG_WARNING("ShaderMng", "impossible de compiler le shader " + std::string(filename));
    LOG_WARNING("ShaderMng", log);
    free(log);
    glDeleteShader(shader);
    return 0;
  }
  return shader;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

char* ShaderMng::LoadSource(const char *filename)
{
  FILE *fp = fopen(filename, "rb");
  if(fp == NULL)
  {
    LOG_ERROR("ShaderMng", "impossible d'ouvrir le fichier " + std::string(filename));
    return NULL;
  }

  fseek(fp, 0, SEEK_END);
  long size = ftell(fp);
  rewind(fp);
  char *src = (char*)malloc(size+1);

  for(long i = 0; i<size; i++)
    src[i] = fgetc(fp);

  src[size] = '\0';
  fclose(fp);

  return src;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
