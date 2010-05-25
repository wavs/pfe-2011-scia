////////////////////////////////////////////////////////////////////////////////
// Filename  : texture_loader.hh
// Authors   : Creteur Clement
// Last edit : 02/01/10 - 15h46
// Comment   :
////////////////////////////////////////////////////////////////////////////////
#ifndef GFX_TEXTURE_LOADER_HH
#define GFX_TEXTURE_LOADER_HH

#include "../useful/vector.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class SDL_Surface;

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class TextureLoader
{
  public:
    TextureLoader();
    TextureLoader(const std::string parFilename);
    ~TextureLoader();

    void Reload(const std::string parFilename);

    inline const std::string& GetFilename() const {return MFilename;}
    inline const Vector2i&    GetSize()     const {return MSize;}
    inline unsigned           GetGLId()     const {return MGLId;}
    inline bool               HasAlpha()    const {return MHasAlpha;}
    inline bool               Loaded()      const {return MLoaded;}

   static unsigned SDLToGL(SDL_Surface* parSurface, Vector2i& parSize);

  private:
    static SDL_Surface* FlipSurface(SDL_Surface* parSurface);
    unsigned LoadTexture(const std::string& filename, Vector2i& parSize,
                         bool& parHasAlpha) const;

    std::string MFilename;
    Vector2i    MSize;
    unsigned    MGLId;
    bool        MHasAlpha;
    bool        MLoaded;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
