////////////////////////////////////////////////////////////////////////////////
// Filename  : material_type_descriptor.hh
// Authors   : Creteur Clement
// Last edit : 27/01/10 - 15h40
// Comment   :
////////////////////////////////////////////////////////////////////////////////
#ifndef GFX_MATERIAL_TYPE_DESCRIPTOR_HH
#define GFX_MATERIAL_TYPE_DESCRIPTOR_HH

#include "../useful/all.hh"
#include "material.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class MaterialTypeDescriptor
{
  public:
    MaterialTypeDescriptor() {}
    virtual ~MaterialTypeDescriptor() {}

    inline virtual Material* Load(XmlTree& parXmlFile)   const {return NULL;}
    inline virtual Material* Load(unsigned parCfgFileId) const {return NULL;}
    inline virtual void PreRender() const {}
    inline virtual void PostRender() const {}

  protected:
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
