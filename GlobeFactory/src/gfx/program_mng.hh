////////////////////////////////////////////////////////////////////////////////
// Filename  : program_mng.hh
// Authors   : Creteur Clement
// Last edit : 15/04/10 - 23h30
// Comment   :
////////////////////////////////////////////////////////////////////////////////
#ifndef GFX_PROGRAM_MNG_HH
#define GFX_PROGRAM_MNG_HH

#include "../useful/all.hh"
#include "material.hh"
#include "shader_mng.hh"
#include "extensions.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class ProgramMng : public Singleton<ProgramMng>
{
  friend class Singleton<ProgramMng>;

  public:
    inline void LinkProgram(MaterialEnum::Type parMaterialType)
    {
      glUseProgram(MPrograms[parMaterialType]);
    }

    inline void UnlinkProgram()
    {
      glUseProgram(0);
    }


  private:
    ProgramMng();
    ~ProgramMng();

    ShaderMng MShaderMng;
    unsigned  MPrograms[MaterialEnum::COUNT];
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
