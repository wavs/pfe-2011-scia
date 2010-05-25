////////////////////////////////////////////////////////////////////////////////
// Filename  : texture_mng.hh
// Authors   : Creteur Clement
// Last edit : 02/01/10 - 15h46
// Comment   :
////////////////////////////////////////////////////////////////////////////////
#ifndef GFX_TEXTURE_MNG_HH
#define GFX_TEXTURE_MNG_HH

#include "../useful/all.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class Texture : public ManagerLoaderClient
{
  public:
    Texture(const std::string& parFilename, const Vector2i parSize, unsigned parGLId, bool parHasHalpha);
    ~Texture();

    inline const Vector2i& GetSize()  const {return MSize;}
    inline unsigned        GetGLId()  const {return MGLId;}
    inline bool            HasAlpha() const {return MHasAlpha;}

  private:
    Vector2i    MSize;
    unsigned    MGLId;
    bool        MHasAlpha;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class TextureMng : public ManagerLoader<Texture, true>, public Singleton<TextureMng>
{
  friend class Singleton<TextureMng>;
  public:
    inline unsigned GetGLId(unsigned parId) {return MObjects[parId]->GetGLId();}

  protected:
    Texture* NewObject(const std::string& parFilename) const;

  private:
    TextureMng();
    ~TextureMng();
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
