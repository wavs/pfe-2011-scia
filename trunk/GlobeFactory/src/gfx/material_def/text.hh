////////////////////////////////////////////////////////////////////////////////
// Filename  : text.hh
// Authors   : Creteur Clement
// Last edit : 09/03/10 - 20h06
// Comment   :
////////////////////////////////////////////////////////////////////////////////
#ifndef MATERIAL_DEF_TEXT_HH
#define MATERIAL_DEF_TEXT_HH

#include "../../useful/all.hh"
#include "../material.hh"
#include "../material_type_descriptor.hh"
#include "../font_mng.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class TextMaterial : public Material
{
  public:
    TextMaterial(Font* parFont, const std::string& parText, Vector2i& parSize, int parStyle);
    ~TextMaterial();

    void PreRender();
    void PostRender();

    inline virtual bool HasAlpha() const {return true;}

  private:
    unsigned MTextureId;
    Font*    MFont;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class TextMaterialDescriptor : public MaterialTypeDescriptor
{
  public:
    TextMaterialDescriptor();
    virtual ~TextMaterialDescriptor();

    virtual TextMaterial* Load(XmlTree& parXmlFile) const;
    virtual void PreRender() const;
    virtual void PostRender() const;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
