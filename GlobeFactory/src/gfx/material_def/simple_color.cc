#include "simple_color.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

SimpleColorMaterial::SimpleColorMaterial(const std::string& parFilename)
  : Material(parFilename, MaterialEnum::SIMPLE_COLOR)
{
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

SimpleColorMaterial::~SimpleColorMaterial()
{
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void SimpleColorMaterial::PreRender()
{
  glColor4f(MColor.r(), MColor.g(), MColor.b(), MColor.a());
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void SimpleColorMaterial::PostRender()
{
  glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

SimpleColorMaterialDescriptor::SimpleColorMaterialDescriptor()
{
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

SimpleColorMaterialDescriptor::~SimpleColorMaterialDescriptor()
{
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

SimpleColorMaterial* SimpleColorMaterialDescriptor::Load(XmlTree& parXmlFile) const
{
  XmlNode* color_node = parXmlFile.GetNode("Color");
  if (color_node == NULL)
    return NULL;

  SimpleColorMaterial* mat = new SimpleColorMaterial(parXmlFile.GetFilename());

  float r, g, b;
  color_node->GetAttribute("r", r);
  color_node->GetAttribute("g", g);
  color_node->GetAttribute("b", b);

  mat->MColor.Set(r, g, b);

  return mat;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

SimpleColorMaterial* SimpleColorMaterialDescriptor::Load(unsigned parCfgFileId) const
{
  ConfigMng* cfgMng = ConfigMng::get();

  SimpleColorMaterial* mat = new SimpleColorMaterial(cfgMng->GetFilename(parCfgFileId));

  const float* r = cfgMng->GetOptionFloat(parCfgFileId, "r");
  const float* g = cfgMng->GetOptionFloat(parCfgFileId, "g");
  const float* b = cfgMng->GetOptionFloat(parCfgFileId, "b");

  mat->MColor.Set(r ? *r : 1.0f, g ? *g : 1.0f, b ? *b : 1.0f);

  return mat;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void SimpleColorMaterialDescriptor::PreRender() const
{
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void SimpleColorMaterialDescriptor::PostRender() const
{
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
