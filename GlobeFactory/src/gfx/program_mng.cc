#include "program_mng.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

ProgramMng::ProgramMng()
{
  for (unsigned i = 0; i < MaterialEnum::COUNT; ++i)
  {
    unsigned program    = 0;
    unsigned vertShader = 0;
    unsigned fragShader = 0;

    if (!MaterialEnum::ToVertShader[i].empty())
      vertShader = MShaderMng.LoadVertexShader("shader/" + MaterialEnum::ToVertShader[i] + ".vert");
    if (!MaterialEnum::ToFragShader[i].empty())
      fragShader = MShaderMng.LoadPixelShader("shader/" + MaterialEnum::ToFragShader[i] + ".frag");

    if (vertShader != 0 || fragShader != 0)
    {
      program = glCreateProgram();

      if (vertShader != 0)
        glAttachShader(program, vertShader);
      if (fragShader != 0)
        glAttachShader(program, fragShader);

      glLinkProgram(program);

      GLint linkStatus;
      glGetProgramiv(program, GL_LINK_STATUS, &linkStatus);
      if(linkStatus != GL_TRUE)
      {
        GLsizei logsize = 0;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logsize);

        char *log = (char*)malloc(logsize + 1);

        memset(log, '\0', logsize + 1);
        glGetProgramInfoLog(program, logsize, &logsize, log);

        LOG_ERROR("ProgramMng", "impossible to link the program of material type " + MaterialEnum::ToString[i]);
        LOG_ERROR("ProgramMng", log);

        free(log);
        if (vertShader != 0)
          glDeleteShader(vertShader);
        if (fragShader != 0)
          glDeleteShader(fragShader);
        program = 0;
      }
      else
        LOG_RESUME("ProgramMng", "Shader Loaded for material type " + MaterialEnum::ToString[i]);
    }

    MPrograms[i] = program;
  }
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

ProgramMng::~ProgramMng()
{
  for (unsigned i = 0; i < MaterialEnum::COUNT; ++i)
    if (MPrograms[i] != 0)
      glDeleteProgram(MPrograms[i]);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
