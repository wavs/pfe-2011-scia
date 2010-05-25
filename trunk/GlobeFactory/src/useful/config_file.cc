#include "config_file.hh"
#include "macro.hh"
#include "templated_function.hh"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

CfgFile::CfgFile(const std::string& parFilename)
  : ManagerLoaderClient(parFilename)
{
  std::ifstream file(parFilename.c_str(), std::ios::in);

  if (!file)
  {
    LOG_RESUME("CfgFile", parFilename + " does not exist : Creation");
    return;
  }

  while (!file.eof())
  {
    char buffer[512];
    file.getline(buffer, 512);
    std::string line(buffer);
    unsigned size = line.size();

    if (size == 0 || line[0] == '#')
      continue;

    unsigned eqPos = line.find('=', 0);
    if (eqPos == line.npos)
    {
      LOG_WARNING("CfgFile", parFilename + " : char '=' is missing");
      continue;
    }

    std::string varName = line.substr(0, eqPos);
    std::string value = line.substr(eqPos + 1, size - eqPos - 1);

    CleanString(varName);
    CleanString(value);

    if (varName.empty() || value.empty())
      LOG_WARNING("CfgFile", parFilename + " : empty before or after '='");
    else
      SetOption(varName, value);
  }

  file.close();
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

CfgFile::~CfgFile()
{
  std::vector<std::string> optionNames(8);

  foreach(it, MOptions)
    optionNames.push_back(it->first);

  foreach(it, optionNames)
    RemoveOption(*it);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void CfgFile::Save()
{
  std::ofstream file(GetFilename().c_str(), std::ios::out | std::ios::trunc);

  foreach(it, MOptions)
    file << it->first << " =" << it->second.v_string;

  file.close();
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void CfgFile::CleanString(std::string& parString) const
{
  int size  = parString.size();
  int begin = 0;
  int end   = size - 1;

  while (begin < size && (parString[begin] == ' ' || parString[begin] == '\t'))
    ++begin;

  if (begin == size)
  {
    parString = "";
    return;
  }

  while (end >= 0 && (parString[end] == ' ' || parString[end] == '\t' || parString[end] == '\r'))
    --end;

  LOG_ASSERT(begin <= end);
  parString = parString.substr(begin, end - begin + 1);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void CfgFile::RemoveOption(const std::string& parName)
{
  if (MOptions.count(parName) != 0)
  {
    CfgOption& var = MOptions[parName];

    if (var.v_bool)
      delete var.v_bool;
    if (var.v_int)
      delete var.v_int;
    if (var.v_float)
      delete var.v_float;

    MOptions.erase(parName);
  }
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void CfgFile::SetOption(const std::string& parName, bool parValue)
{
  RemoveOption(parName);

  CfgOption option;
  option.v_string = (parValue) ? "true" : "false";
  option.v_bool = new bool(parValue);
  MOptions[parName] = option;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void CfgFile::SetOption(const std::string& parName, int parValue)
{
  SetOption(parName, float(parValue));
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void CfgFile::SetOption(const std::string& parName, float parValue)
{
  RemoveOption(parName);

  std::ostringstream stream;
  stream << parValue;

  CfgOption option;
  option.v_string = stream.str();
  option.v_int = new int(static_cast<int> (parValue));
  option.v_float = new float(parValue);
  MOptions[parName] = option;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void CfgFile::SetOption(const std::string& parName, const std::string& parValue)
{
  RemoveOption(parName);

  CfgOption option;
  option.v_string = parValue;

  bool convBool;
  if (misc::FromString(convBool, parValue))
    option.v_bool = new bool(convBool);

  float convFloat;
  if (misc::FromString(convFloat, parValue))
  {
    option.v_float = new float(convFloat);
    option.v_int = new int(static_cast<int> (convFloat));
  }

  MOptions[parName] = option;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

const bool* CfgFile::GetOptionBool(const std::string& parName)
{
  if (MOptions.count(parName) == 0)
    return NULL;

  return MOptions[parName].v_bool;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

const int* CfgFile::GetOptionInt(const std::string& parName)
{
  if (MOptions.count(parName) == 0)
    return NULL;

  return MOptions[parName].v_int;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

const float* CfgFile::GetOptionFloat(const std::string& parName)
{
  if (MOptions.count(parName) == 0)
    return NULL;

  return MOptions[parName].v_float;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

const std::string* CfgFile::GetOptionStr(const std::string& parName)
{
  if (MOptions.count(parName) == 0)
    return NULL;

  return &(MOptions[parName].v_string);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
