#include "ui_cmd_button.hh"
#include "../useful/executor.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

UICmdButton::UICmdButton(const Vector2f& parPosition, const Vector2f& parSize,
                const std::string& parMat, const std::string& parMatOn,
                const std::string& parMatClick, const std::string& parCmd)
  : UIButton(parPosition, parSize, parMat, parMatOn, parMatClick),
    MCmd(parCmd)
{
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

UICmdButton::~UICmdButton()
{
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

UICmdButton* UICmdButton::Clone() const
{
  UICmdButton* newButt = new UICmdButton(GetPosition(), GetSize(), MCmd);
  newButt->SetArg(MArg);
  return newButt;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void UICmdButton::Action()
{
  if (MArg.empty())
    Executor::get()->Execute(MCmd);
  else
    Executor::get()->Execute(MCmd, MArg);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
