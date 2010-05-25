////////////////////////////////////////////////////////////////////////////////
// Filename  : shader_mng.hh
// Authors   : Creteur Clement
// Last edit : 15/04/10 - 23h30
// Comment   :
////////////////////////////////////////////////////////////////////////////////
#ifndef GFX_SHADER_MNG_HH
#define GFX_SHADER_MNG_HH

#include "../useful/all.hh"
#include "extensions.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class ShaderMng
{
  public:
    ShaderMng();
    ~ShaderMng();

    unsigned LoadVertexShader(const std::string& parFilename);
    unsigned LoadPixelShader(const std::string& parFilename);

  private:
    unsigned LoadShader(GLenum type, const char* filename);
    char*    LoadSource(const char *filename);

    std::map<std::string, unsigned> MShaders;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
