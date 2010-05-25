////////////////////////////////////////////////////////////////////////////////
// Filename  : config_file.hh
// Authors   : Creteur Clement
// Last edit : 08/11/09 - 19h52
// Comment   : Class used by the Config Manager to represent a config file.
//             A config file is a list of variable (one by line) set like this:
//             VariableName = VariableValue (can be string, int, float or bool)
////////////////////////////////////////////////////////////////////////////////
#ifndef USEFUL_CONFIG_FILE_HH
#define USEFUL_CONFIG_FILE_HH

#include <string>
#include <map>
#include "manager_loader.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class CfgFile : public ManagerLoaderClient
{
  public:
    CfgFile(const std::string& parFilename);
    ~CfgFile();

    void Save();
    void RemoveOption(const std::string& parName);

    void SetOption(const std::string& parName, bool);
    void SetOption(const std::string& parName, int);
    void SetOption(const std::string& parName, float);
    void SetOption(const std::string& parName, const std::string&);

    const bool*        GetOptionBool(const std::string& parName);
    const int*         GetOptionInt(const std::string& parName);
    const float*       GetOptionFloat(const std::string& parName);
    const std::string* GetOptionStr(const std::string& parName);

  private:
    void CleanString(std::string& parString) const;

    struct CfgOption
    {
      CfgOption() : v_bool(NULL), v_int(NULL), v_float(NULL) {}

      std::string v_string;
      bool*       v_bool;
      int*        v_int;
      float*      v_float;
    };

    std::map<std::string, CfgOption> MOptions;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
