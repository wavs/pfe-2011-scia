////////////////////////////////////////////////////////////////////////////////
// Filename  : config_mng.hh
// Authors   : Creteur Clement
// Last edit : 08/11/09 - 19h55
// Comment   : Class to manage the different files of configuration.
////////////////////////////////////////////////////////////////////////////////
#ifndef USEFUL_CONFIG_MNG_HH
#define USEFUL_CONFIG_MNG_HH

#include <map>
#include <vector>
#include "log.hh"
#include "manager_loader.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class CfgFile;

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class ConfigMng : public ManagerLoader<CfgFile>, public Singleton<ConfigMng>
{
  friend class Singleton<ConfigMng>;

  public:
    void SaveCfgFile(unsigned parFileId);

    template<class T>
    void SetOption(unsigned parFileId, const std::string& parName, T);

    const bool*        GetOptionBool(unsigned parFileId, const std::string& parName);
    const int*         GetOptionInt(unsigned parFileId, const std::string& parName);
    const float*       GetOptionFloat(unsigned parFileId, const std::string& parName);
    const std::string* GetOptionStr(unsigned parFileId, const std::string& parName);

    void RemoveOption(unsigned parFileId, const std::string& parName);

  protected:
    CfgFile* NewObject(const std::string& parFilename) const;

  private:
    ConfigMng();
    ~ConfigMng();
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
