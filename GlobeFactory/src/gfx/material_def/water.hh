////////////////////////////////////////////////////////////////////////////////
// Filename  : water.hh
// Authors   : Creteur Clement
// Last edit : 17/01/10 - 21h46
// Comment   :
////////////////////////////////////////////////////////////////////////////////
#ifndef MATERIAL_DEF_WATER_HH
#define MATERIAL_DEF_WATER_HH

#include "../../useful/all.hh"
#include "../material.hh"
#include "../material_type_descriptor.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class WaterMaterial : public Material
{
  public:
    WaterMaterial(const std::string& parFilename);
    ~WaterMaterial();

    void PreRender();
    void PostRender();
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class WaterMaterialDescriptor : public MaterialTypeDescriptor
{
  public:
    WaterMaterialDescriptor();
    virtual ~WaterMaterialDescriptor();

    virtual WaterMaterial* Load(XmlTree& parXmlFile) const;
    virtual void PreRender() const;
    virtual void PostRender() const;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
