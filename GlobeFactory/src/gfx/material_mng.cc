#include "material_mng.hh"
#include "../useful/xml_loader.hh"
#include "material_def/all.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

const unsigned    MATERIAL_PREPARED_SPACE = 64;
const std::string MATERIAL_ERROR_FILENAME = "error.txt";

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

MaterialMng::MaterialMng()
 : MMaterials(MATERIAL_PREPARED_SPACE)
{
  for (unsigned i = 0; i < MaterialEnum::COUNT; ++i)
    MMaterialLoaders[i] = NULL;

  MMaterialLoaders[MaterialEnum::NONE]           = new NoneMaterialDescriptor();
  MMaterialLoaders[MaterialEnum::INTERFACE2D]    = new Interface2DMaterialDescriptor();
  MMaterialLoaders[MaterialEnum::WATER]          = new WaterMaterialDescriptor();
  MMaterialLoaders[MaterialEnum::SIMPLE_COLOR]   = new SimpleColorMaterialDescriptor();
  MMaterialLoaders[MaterialEnum::SIMPLE_TEXTURE] = new SimpleTextureMaterialDescriptor();
  MMaterialLoaders[MaterialEnum::TEXT]           = new TextMaterialDescriptor();
  MMaterialLoaders[MaterialEnum::ANIMATED]       = new AnimatedMaterialDescriptor();

  for (unsigned i = 1; i < MaterialEnum::COUNT; ++i)
    LOG_ASSERT_WITH_DESC(MMaterialLoaders[i] != NULL, "Material Descriptor not linker in the MaterialMng");

  for (unsigned i = 0; i < MATERIAL_PREPARED_SPACE; ++i)
    MMaterials[i] = NULL;

  LoadMaterial(MATERIAL_ERROR_FILENAME);
  MMaterials[NONE_ID] = new NoneMaterial();
  LOG_ASSERT(MMaterials[ERROR_ID] != NULL);
  LOG_ASSERT(MMaterials[NONE_ID] != NULL);
  LOG_RESUME("MaterialMng", "NoneMaterial(1) loaded");
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

MaterialMng::~MaterialMng()
{
  for (unsigned i = 0; i < MaterialEnum::COUNT; ++i)
    delete MMaterialLoaders[i];

  delete MMaterials[ERROR_ID];
  delete MMaterials[NONE_ID];
  unsigned size = MMaterials.size();
  for (unsigned i = 2; i < size; ++i)
  {
    LOG_ASSERT(MMaterials[i] == NULL);
    delete MMaterials[i];
  }
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

unsigned MaterialMng::LoadMaterial(const std::string& parFilename)
{
  LOG_ASSERT(!parFilename.empty());

  unsigned size = MMaterials.size();
  for (unsigned i = 0; i < size; ++i)
  {
    Material* material = MMaterials[i];
    if (material != NULL && material->GetFilename() == parFilename)
    {
      material->IncRefCount();
      return i;
    }
  }

  ConfigMng* cfgMng = ConfigMng::get();
  unsigned fileId   = cfgMng->Load(std::string("material/") + parFilename);
  const std::string* type = cfgMng->GetOptionStr(fileId, "type");
  if (type == NULL)
  {
    LOG_ERROR("Material Mng", "Unable to open the material " + parFilename);
    cfgMng->Unload(fileId);
    return 0;
  }

  MaterialEnum::Type materialType = MaterialEnum::COUNT;
  for (unsigned i = 0; i < MaterialEnum::COUNT; ++i)
    if (MaterialEnum::ToString[i] == *type)
    {
      materialType = static_cast<MaterialEnum::Type>(i);
      break;
    }

  if (materialType == MaterialEnum::COUNT)
  {
    LOG_ERROR("Material Mng", "The type of the material " + parFilename + " is unknow.");
    return 0;
  }

  Material* material = MMaterialLoaders[materialType]->Load(fileId);
  if (material == NULL)
  {
    LOG_ERROR("Material Mng", "Invalid material " + parFilename);
    cfgMng->Unload(fileId);
    return 0;
  }
  cfgMng->Unload(fileId);

  size = MMaterials.size();
  for (unsigned i = 0; i < size; ++i)
    if (MMaterials[i] == NULL)
    {
      MMaterials[i] = material;
      LOG_RESUME("MaterialMng", "New material(" + misc::ToString(i) + ") loaded : " + parFilename);
      return i;
    }

  MMaterials.push_back(material);
  LOG_RESUME("MaterialMng", "New material(" + misc::ToString(size) + ") loaded : " + parFilename);
  return size;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void MaterialMng::UnloadMaterial(unsigned parId)
{
  LOG_ASSERT(parId < MMaterials.size());

  if (parId <= 1)
    return;

  LOG_ASSERT(MMaterials[parId] != NULL);

  MMaterials[parId]->DecRefCount();
  if (MMaterials[parId]->GetRefCount() == 0)
  {
    delete MMaterials[parId];
    MMaterials[parId] = NULL;
  }
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void MaterialMng::AddUserOnMaterial(unsigned parId)
{
  LOG_ASSERT(parId < MMaterials.size());
  LOG_ASSERT(MMaterials[parId] != NULL);

  if (parId <= 1)
    return;

  MMaterials[parId]->IncRefCount();
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

unsigned MaterialMng::LoadTextMaterial(Font* parFont, const std::string& parText, Vector2i& parSize, int parStyle)
{
  TextMaterial* textMaterial = new TextMaterial(parFont, parText, parSize, parStyle);

  unsigned size = MMaterials.size();
  for (unsigned i = 0; i < size; ++i)
    if (MMaterials[i] == NULL)
    {
      MMaterials[i] = textMaterial;
      return i;
    }

  MMaterials.push_back(textMaterial);
  LOG_RESUME("MaterialMng", "New TextMaterial(" + misc::ToString(size) + ") loaded : " + parText);
  return size;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void MaterialMng::PreRenderForMaterial(unsigned parId)
{
  LOG_ASSERT(parId <= MMaterials.size());

  if (MMaterials[parId] != NULL)
    MMaterials[parId]->PreRender();
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void MaterialMng::PostRenderForMaterial(unsigned parId)
{
  LOG_ASSERT(parId <= MMaterials.size());

  if (MMaterials[parId] != NULL)
    MMaterials[parId]->PostRender();
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

MaterialEnum::Type MaterialMng::GetMaterialType(unsigned parId) const
{
  LOG_ASSERT(parId <= MMaterials.size());
  LOG_ASSERT(MMaterials[parId] != NULL);

  return MMaterials[parId]->GetType();
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
