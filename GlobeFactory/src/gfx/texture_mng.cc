#include "texture_mng.hh"
#include <GL/glu.h>
#include <GL/gl.h>
#include "texture_loader.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

const unsigned    TEXMNG_INIT_SIZE     = 64;
const std::string TEXMNG_ERROR_TEXTURE = "error.bmp";

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

Texture::Texture(const std::string& parFilename,
                 const Vector2i parSize,
                 unsigned parGLId,
                 bool parHasHalpha)
  : ManagerLoaderClient(parFilename),
    MSize(parSize),
    MGLId(parGLId),
    MHasAlpha(parHasHalpha)
{
  LOG_ASSERT(parGLId != 0);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

Texture::~Texture()
{
  glDeleteTextures(1, &MGLId);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

TextureMng::TextureMng()
{
  TextureLoader tl(TEXMNG_ERROR_TEXTURE);

  LOG_ASSERT_WITH_DESC(tl.Loaded(), "Impossible de charger la texture d'erreur "
                                    + TEXMNG_ERROR_TEXTURE);

  MObjects[0] = new Texture(TEXMNG_ERROR_TEXTURE, tl.GetSize(),
                            tl.GetGLId(), tl.HasAlpha());

  LOG_RESUME("TextureMng", "TextureMng created (ErrorTexture GLId : "
                           + misc::ToString(tl.GetGLId()) + ")");
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

TextureMng::~TextureMng()
{
  delete MObjects[0];
  MObjects[0] = NULL;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

Texture* TextureMng::NewObject(const std::string& parFilename) const
{
  TextureLoader tl(parFilename);
  if (!tl.Loaded())
  {
    LOG_ERROR("TextureMng", "Unable to load the texture " + parFilename);
    return NULL;
  }

  return new Texture(parFilename, tl.GetSize(), tl.GetGLId(), tl.HasAlpha());
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
