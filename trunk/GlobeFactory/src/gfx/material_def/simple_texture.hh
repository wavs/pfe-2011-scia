////////////////////////////////////////////////////////////////////////////////
// Filename  : simple_texture.hh
// Authors   : Creteur Clement
// Last edit : 30/01/10 - 03h46
// Comment   :
////////////////////////////////////////////////////////////////////////////////
#ifndef MATERIAL_DEF_SIMPLE_TEXTURE_HH
#define MATERIAL_DEF_SIMPLE_TEXTURE_HH

#include "../../useful/all.hh"
#include "../material.hh"
#include "../material_type_descriptor.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class SimpleTextureMaterialDescriptor;

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class SimpleTextureMaterial : public Material
{
  friend class SimpleTextureMaterialDescriptor;
  public:
    SimpleTextureMaterial(const std::string& parFilename);
    ~SimpleTextureMaterial();

    void PreRender();
    void PostRender();

  private:
    unsigned MTextureId;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class SimpleTextureMaterialDescriptor : public MaterialTypeDescriptor
{
  public:
    SimpleTextureMaterialDescriptor();
    virtual ~SimpleTextureMaterialDescriptor();

    virtual SimpleTextureMaterial* Load(XmlTree& parXmlFile) const;
    virtual SimpleTextureMaterial* Load(unsigned parCfgFileId) const;

    virtual void PreRender() const;
    virtual void PostRender() const;
};


//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
