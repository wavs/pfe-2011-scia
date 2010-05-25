////////////////////////////////////////////////////////////////////////////////
// Filename  : executor.hh
// Authors   : Creteur Clement
// Last edit : 11/11/09 - 16h00
// Comment   :
////////////////////////////////////////////////////////////////////////////////
#ifndef USEFUL_EXECUTOR_HH
#define USEFUL_EXECUTOR_HH

#include <string>
#include <map>
#include "log.hh"
#include "singleton.hh"

class Command;

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class Executor : public Singleton<Executor>
{
  friend class Singleton<Executor>;

  public:
    void Execute(const std::string& parCommand);
    void Execute(const std::string& parCommand, bool parArg);
    void Execute(const std::string& parCommand, float parArg);
    void Execute(const std::string& parCommand, const std::string& parArg);

    void RegisterCommand(Command* parCommand);
    void UnregisterCommand(Command* parCommand);

  private:
    Executor();
    ~Executor();

    std::map<std::string, Command*> MCommands;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
