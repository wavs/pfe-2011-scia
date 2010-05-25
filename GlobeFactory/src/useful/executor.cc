#include "executor.hh"
#include "command.hh"
#include "templated_function.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

Executor::Executor()
{
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

Executor::~Executor()
{
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void Executor::Execute(const std::string& parCommand)
{
  if (MCommands.count(parCommand) != 0)
    MCommands[parCommand]->Execute();
  else
    LOG_ERROR("Execute", parCommand + " : Unknow command with no argument");
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void Executor::Execute(const std::string& parCommand, bool parArg)
{
  if (MCommands.count(parCommand) != 0)
    MCommands[parCommand]->Execute(parArg);
  else
    LOG_ERROR("Execute", parCommand + " : Unknow command with arg : " + misc::ToString(parArg));
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void Executor::Execute(const std::string& parCommand, float parArg)
{
  if (MCommands.count(parCommand) != 0)
    MCommands[parCommand]->Execute();
  else
    LOG_ERROR("Execute", parCommand + " : Unknow command with arg : " + misc::ToString(parArg));
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void Executor::Execute(const std::string& parCommand, const std::string& parArg)
{
  if (MCommands.count(parCommand) != 0)
    MCommands[parCommand]->Execute(parArg);
  else
    LOG_ERROR("Execute", parCommand + " : Unknow command with arg : " + parArg);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void Executor::RegisterCommand(Command* parCommand)
{
  LOG_ASSERT(parCommand != NULL);
  LOG_ASSERT(MCommands.count(parCommand->GetName()) == 0);

  MCommands[parCommand->GetName()] = parCommand;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void Executor::UnregisterCommand(Command* parCommand)
{
  LOG_ASSERT(parCommand != NULL);
  LOG_ASSERT(MCommands.count(parCommand->GetName()) != 0);

  MCommands.erase(parCommand->GetName());
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
