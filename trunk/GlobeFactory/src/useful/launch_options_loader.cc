#include "launch_options_loader.hh"
#include "templated_function.hh"
#include "log.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

LaunchOptionsLoader::LaunchOptionsLoader()
{
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

LaunchOptionsLoader::~LaunchOptionsLoader()
{
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void LaunchOptionsLoader::Initialize(int argc, char* argv[])
{
  MOptions.clear();

  for (int i = 1; i < argc; ++i)
    MArgs.push_back(std::string(argv[i]));

  MCurArg = 0;

  while (MCurArg < int(MArgs.size()))
    Parse();

  MArgs.clear();
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

ELaunchOption LaunchOptionsLoader::StrToEnum(const std::string& parOpt)
{
  for (int i = 0; i < LOPT_COUNT; ++i)
    if (LaunchOptionStr[i].compare(parOpt) == 0)
      return (ELaunchOption) i;

  return LOPT_COUNT;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void LaunchOptionsLoader::Parse()
{
  ELaunchOption curOpt = StrToEnum(MArgs[MCurArg++]);

  if (curOpt == LOPT_COUNT)
  {
    LOG_WARNING("Argv       ", "Option inconnue : " + MArgs[MCurArg]);
    return;
  }

  MOptions[curOpt] = std::vector<TParam>();

  while (MCurArg < int(MArgs.size()))
  {
    ELaunchOption curParam = StrToEnum(MArgs[MCurArg]);
    if (curParam != LOPT_COUNT)
      return;

    TParam param(MArgs[MCurArg]);
    param.isInteger = misc::FromString(param.integer, param.string);

    MOptions[curOpt].push_back(param);
    ++MCurArg;
  }
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

bool LaunchOptionsLoader::HasOption(ELaunchOption parOpt) const
{
  return (MOptions.count(parOpt) != 0);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

bool LaunchOptionsLoader::HasOptionParam(ELaunchOption parOpt, unsigned parIth) const
{
  if (!HasOption(parOpt))
    return false;

  std::map<ELaunchOption, std::vector<TParam> >::const_iterator it = MOptions.find(parOpt);

  return (parIth < it->second.size());
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

bool LaunchOptionsLoader::HasOptionParamInteger(ELaunchOption parOpt, unsigned parIth) const
{
  if (!HasOptionParam(parOpt, parIth))
    return false;

  return MOptions.find(parOpt)->second[parIth].isInteger;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

const std::string& LaunchOptionsLoader::GetParam(ELaunchOption parOpt, unsigned parIth) const
{
  assert(HasOptionParam(parOpt, parIth));
  return MOptions.find(parOpt)->second[parIth].string;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

int LaunchOptionsLoader::GetParamInteger(ELaunchOption parOpt, unsigned parIth) const
{
  assert(HasOptionParamInteger(parOpt, parIth));
  return MOptions.find(parOpt)->second[parIth].integer;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
