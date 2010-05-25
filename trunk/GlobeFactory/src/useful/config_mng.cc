#include "config_mng.hh"
#include "macro.hh"
#include "config_file.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

ConfigMng::ConfigMng()
{
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

ConfigMng::~ConfigMng()
{
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

CfgFile* ConfigMng::NewObject(const std::string& parFilename) const
{
  return new CfgFile(parFilename);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void ConfigMng::SaveCfgFile(unsigned parFileId)
{
  LOG_ASSERT_WITH_DESC(parFileId < MObjects.size() && MObjects[parFileId],
                       "Mauvais index de fichier de config.");

  MObjects[parFileId]->Save();
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

template<class T>
void ConfigMng::SetOption(unsigned parFileId, const std::string& parName, T parVal)
{
  LOG_ASSERT_WITH_DESC(parFileId < MObjects.size() && MObjects[parFileId],
                       "Mauvais index de fichier de config.");

  MObjects[parFileId]->SetOption(parName, parVal);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

const bool* ConfigMng::GetOptionBool(unsigned parFileId, const std::string& parName)
{
  LOG_ASSERT_WITH_DESC(parFileId < MObjects.size() && MObjects[parFileId],
                       "Mauvais index de fichier de config.");

  return MObjects[parFileId]->GetOptionBool(parName);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

const int* ConfigMng::GetOptionInt(unsigned parFileId, const std::string& parName)
{
  LOG_ASSERT_WITH_DESC(parFileId < MObjects.size() && MObjects[parFileId],
                       "Mauvais index de fichier de config.");

  return MObjects[parFileId]->GetOptionInt(parName);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

const float* ConfigMng::GetOptionFloat(unsigned parFileId, const std::string& parName)
{
  LOG_ASSERT_WITH_DESC(parFileId < MObjects.size() && MObjects[parFileId],
                       "Mauvais index de fichier de config.");

  return MObjects[parFileId]->GetOptionFloat(parName);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

const std::string* ConfigMng::GetOptionStr(unsigned parFileId, const std::string& parName)
{
  LOG_ASSERT_WITH_DESC(parFileId < MObjects.size() && MObjects[parFileId],
                       "Mauvais index de fichier de config.");

  return MObjects[parFileId]->GetOptionStr(parName);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void ConfigMng::RemoveOption(unsigned parFileId, const std::string& parName)
{
  LOG_ASSERT_WITH_DESC(parFileId < MObjects.size() && MObjects[parFileId],
                       "Mauvais index de fichier de config.");

  MObjects[parFileId]->RemoveOption(parName);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
