////////////////////////////////////////////////////////////////////////////////
// Filename  : command.hh
// Authors   : Creteur Clement
// Last edit : 11/11/09 - 16h00
// Comment   :
////////////////////////////////////////////////////////////////////////////////
#ifndef USEFUL_COMMAND_HH
#define USEFUL_COMMAND_HH

#include <string>

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class Command
{
  public:
    inline const std::string& GetName() const {return MName;}

    virtual void Execute();
    virtual void Execute(bool parArg);
    virtual void Execute(float parArg);
    virtual void Execute(const std::string& parArg);

  protected:
    Command(const std::string& parName);
    virtual ~Command();

  private:
    std::string MName;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
