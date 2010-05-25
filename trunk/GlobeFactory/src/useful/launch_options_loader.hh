////////////////////////////////////////////////////////////////////////////////
// Filename  : launch_options_loader.hh
// Authors   : Creteur Clement
// Last edit : 02/10/09 - 19h34
// Comment   : Singleton to help to read the arguments given to the software.
////////////////////////////////////////////////////////////////////////////////
#ifndef USEFUL_LAUNCH_OPTIONS_LOADER_HH
#define USEFUL_LAUNCH_OPTIONS_LOADER_HH

#include <sstream>
#include <string>
#include <map>
#include <vector>
#include "singleton.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

enum ELaunchOption
{
  LOPT_FULLSCREEN = 0,
  LOPT_RESOLUTION = 1,
  LOPT_DEBUG      = 2,
  LOPT_COUNT      = 3
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

const std::string LaunchOptionStr[] =
{
  "-fullscreen",
  "-resolution",
  "-debug",
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class LaunchOptionsLoader : public Singleton<LaunchOptionsLoader>
{
  friend class Singleton<LaunchOptionsLoader>;

  public:
    void Initialize(int argc, char* argv[]);
    bool HasOption(ELaunchOption parOpt) const;

    bool HasOptionParam(ELaunchOption parOpt, unsigned parIth) const;
    bool HasOptionParamInteger(ELaunchOption parOpt, unsigned parIth) const;

    const std::string& GetParam(ELaunchOption parOpt, unsigned parIth) const;
    int GetParamInteger(ELaunchOption parOpt, unsigned parIth) const;

  private:
    LaunchOptionsLoader();
    ~LaunchOptionsLoader();

    void Parse();
    ELaunchOption StrToEnum(const std::string& parStr);

    struct TParam
    {
      TParam(const std::string& parStr)
        : string(parStr),
          integer(0),
          isInteger(false)
      {
      }

      std::string string;
      int         integer;
      bool        isInteger;
    };

    std::vector<std::string> MArgs;
    std::map<ELaunchOption, std::vector<TParam> > MOptions;
    int MCurArg;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
