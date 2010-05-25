////////////////////////////////////////////////////////////////////////////////
// Filename  : material.hh
// Authors   : Creteur Clement
// Last edit : 08/01/10 - 18h46
// Comment   :
////////////////////////////////////////////////////////////////////////////////
#ifndef GFX_MATERIAL_HH
#define GFX_MATERIAL_HH

#include "vertex.hh"
#include "../useful/all.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

namespace MaterialEnum
{
  enum Type
  {
    NONE            = 0,
    INTERFACE2D     = 1,
    WATER           = 2,
    SIMPLE_COLOR    = 3,
    SIMPLE_TEXTURE  = 4,
    TEXT            = 5,
    ANIMATED        = 6,
    COUNT           = 7
  };

  //----------------------------------------------------------------------------

  const std::string ToString[] =
  {
    "NONE (not loadable from file)",
    "INTERFACE2D",
    "WATER",
    "SIMPLE_COLOR",
    "SIMPLE_TEXTURE",
    "TEXT (not loadable from file)",
    "ANIMATED",
    "COUNT (not loadable from file)",
  };

  //----------------------------------------------------------------------------

  inline Type FromString(const std::string& parStr)
  {
    for (unsigned i = 0; i < COUNT; ++i)
      if (ToString[i] == parStr)
        return static_cast<Type>(i);
    return NONE;
  }

  //----------------------------------------------------------------------------

  const std::string ToVertShader[] =
  {
    "",
    "",
    "water",
    "",
    "",
    "",
    ""
  };

  //----------------------------------------------------------------------------

  const std::string ToFragShader[] =
  {
    "",
    "",
    "water",
    "",
    "",
    "",
    ""
  };
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class  Material : public ManualRefCounter
{
  public:
    Material(const std::string& parFilename, MaterialEnum::Type parType)
     : MFilename(parFilename),
       MType(parType)
    {
    }

    virtual ~Material() {}

    inline virtual void PreRender()  {}
    inline virtual void PostRender() {}
    inline virtual bool HasAlpha() const {return false;}
    inline virtual unsigned GetChildCount()           const {return 0;}
    inline virtual unsigned GetChild(unsigned parIth) const {return 0;}

    inline const std::string& GetFilename() const {return MFilename;}
    inline MaterialEnum::Type GetType()     const {return MType;}

  private:
    const std::string        MFilename;
    const MaterialEnum::Type MType;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
