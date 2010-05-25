////////////////////////////////////////////////////////////////////////////////
// Filename  : none.hh
// Authors   : Creteur Clement
// Last edit : 11/03/10 - 23h06
// Comment   :
////////////////////////////////////////////////////////////////////////////////
#ifndef MATERIAL_DEF_NONE_HH
#define MATERIAL_DEF_NONE_HH

#include "../../useful/all.hh"
#include "../material.hh"
#include "../material_type_descriptor.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class NoneMaterial : public Material
{
  public:
    NoneMaterial() : Material("", MaterialEnum::NONE) {}
    ~NoneMaterial() {}

    inline virtual bool HasAlpha() const {return true;}
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class NoneMaterialDescriptor : public MaterialTypeDescriptor
{
  public:
    NoneMaterialDescriptor() {}
    virtual ~NoneMaterialDescriptor() {}

    void PreRender() const
    {
      glEnable(GL_BLEND);
      glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    }

    void PostRender() const
    {
      glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
      glDisable(GL_BLEND);
    }
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
