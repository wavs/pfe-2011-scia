#include "simple_texture.hh"
#include "../texture_mng.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

SimpleTextureMaterial::SimpleTextureMaterial(const std::string& parFilename)
  : Material(parFilename, MaterialEnum::SIMPLE_TEXTURE),
    MTextureId(0)
{
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

SimpleTextureMaterial::~SimpleTextureMaterial()
{
  TextureMng::get()->Unload(MTextureId);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void SimpleTextureMaterial::PreRender()
{
  glBindTexture(GL_TEXTURE_2D, TextureMng::get()->GetGLId(MTextureId));
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void SimpleTextureMaterial::PostRender()
{
  glBindTexture(GL_TEXTURE_2D, 0);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

SimpleTextureMaterialDescriptor::SimpleTextureMaterialDescriptor()
{
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

SimpleTextureMaterialDescriptor::~SimpleTextureMaterialDescriptor()
{
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

SimpleTextureMaterial* SimpleTextureMaterialDescriptor::Load(XmlTree&) const
{
  return NULL;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

SimpleTextureMaterial* SimpleTextureMaterialDescriptor::Load(unsigned parCfgFileId) const
{
  ConfigMng* cfgMng = ConfigMng::get();
  SimpleTextureMaterial* mat = new SimpleTextureMaterial(cfgMng->GetFilename(parCfgFileId));
  const std::string* texture = ConfigMng::get()->GetOptionStr(parCfgFileId, "texture");
  mat->MTextureId = TextureMng::get()->Load(texture ? *texture : "");

  return mat;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void SimpleTextureMaterialDescriptor::PreRender() const
{
  glColor3f(1.0f, 1.0f, 1.0f);
  glEnable(GL_TEXTURE_2D);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void SimpleTextureMaterialDescriptor::PostRender() const
{
  glDisable(GL_TEXTURE_2D);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
