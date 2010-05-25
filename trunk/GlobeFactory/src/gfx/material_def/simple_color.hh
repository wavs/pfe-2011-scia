////////////////////////////////////////////////////////////////////////////////
// Filename  : simple_color.hh
// Authors   : Creteur Clement
// Last edit : 30/01/10 - 03h46
// Comment   :
////////////////////////////////////////////////////////////////////////////////
#ifndef MATERIAL_DEF_SIMPLE_COLOR_HH
#define MATERIAL_DEF_SIMPLE_COLOR_HH

#include "../../useful/all.hh"
#include "../material.hh"
#include "../material_type_descriptor.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class SimpleColorMaterialDescriptor;

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class SimpleColorMaterial : public Material
{
  friend class SimpleColorMaterialDescriptor;

  public:
    SimpleColorMaterial(const std::string& parFilename);
    ~SimpleColorMaterial();

    void PreRender();
    void PostRender();

  private:
    Color MColor;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class SimpleColorMaterialDescriptor : public MaterialTypeDescriptor
{
  public:
    SimpleColorMaterialDescriptor();
    virtual ~SimpleColorMaterialDescriptor();

    virtual SimpleColorMaterial* Load(XmlTree& parXmlFile) const;
    virtual SimpleColorMaterial* Load(unsigned parCfgFileId) const;

    virtual void PreRender() const;
    virtual void PostRender() const;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
