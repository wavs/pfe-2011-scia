////////////////////////////////////////////////////////////////////////////////
// Filename  : interface2d.hh
// Authors   : Creteur Clement
// Last edit : 17/01/10 - 21h46
// Comment   :
////////////////////////////////////////////////////////////////////////////////
#ifndef MATERIAL_DEF_INTERFACE2D_HH
#define MATERIAL_DEF_INTERFACE2D_HH

#include "../../useful/all.hh"
#include "../material.hh"
#include "../material_type_descriptor.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class Interface2DMaterial : public Material
{
  public:
    Interface2DMaterial(const std::string& parFilename);
    ~Interface2DMaterial();

    void PreRender();
    void PostRender();
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class Interface2DMaterialDescriptor : public MaterialTypeDescriptor
{
  public:
    Interface2DMaterialDescriptor();
    virtual ~Interface2DMaterialDescriptor();

    virtual Interface2DMaterial* Load(XmlTree& parXmlFile) const;
    virtual void PreRender() const;
    virtual void PostRender() const;
};


//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
