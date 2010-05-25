////////////////////////////////////////////////////////////////////////////////
// Filename  : material_mng.hh
// Authors   : Creteur Clement
// Last edit : 08/01/10 - 18h46
// Comment   :
////////////////////////////////////////////////////////////////////////////////
#ifndef GFX_MATERIAL_MNG_HH
#define GFX_MATERIAL_MNG_HH

#include "../useful/singleton.hh"
#include "material.hh"
#include "material_type_descriptor.hh"
#include "font_mng.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class MaterialMng : public Singleton<MaterialMng>
{
  friend class Singleton<MaterialMng>;

  public:
    unsigned LoadMaterial(const std::string& parFilename);
    void     UnloadMaterial(unsigned parId);
    void     AddUserOnMaterial(unsigned parId);

    unsigned LoadTextMaterial(Font* parFont, const std::string& parText, Vector2i& parSize, int parStyle = FontStyle::NORMAL);

    void PreRenderForMaterial(unsigned parId);
    void PostRenderForMaterial(unsigned parId);
    inline void PreRenderForMaterialType(MaterialEnum::Type parMaterialType)
    {
      MMaterialLoaders[parMaterialType]->PreRender();
    }
    void PostRenderForMaterialType(MaterialEnum::Type parMaterialType)
    {
      MMaterialLoaders[parMaterialType]->PostRender();
    }


    MaterialEnum::Type GetMaterialType(unsigned parId) const;

    inline bool HasAlpha(unsigned parId) const {return MMaterials[parId]->HasAlpha();};

    static const unsigned ERROR_ID = 0;
    static const unsigned NONE_ID  = 1;

  private:
    MaterialMng();
    ~MaterialMng();

    std::vector<Material*>  MMaterials;
    MaterialTypeDescriptor* MMaterialLoaders[MaterialEnum::COUNT];
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
