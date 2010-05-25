////////////////////////////////////////////////////////////////////////////////
// Filename  : ui_cmd_button.hh
// Authors   : Creteur Clement
// Last edit : 01/03/10 - 02h07
// Comment   :
////////////////////////////////////////////////////////////////////////////////
#ifndef UI_CMD_BUTTON_HH
#define UI_CMD_BUTTON_HH

#include "ui_button.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class UICmdButton : public UIButton
{
  public:
    UICmdButton(const Vector2f& parPosition, const Vector2f& parSize,
                const std::string& parMat = "", const std::string& parMatOn = "",
                const std::string& parMatClick = "", const std::string& parCmd = "");
    ~UICmdButton();

    UICmdButton* Clone() const;
    void         Action();

    inline void SetCmd(const std::string& parCmd) {MCmd = parCmd;}
    inline void SetArg(const std::string& parArg) {MArg = parArg;}
    inline const std::string& GetCmd() const {return MCmd;}
    inline const std::string& GetArg() const {return MArg;}

  private:
    std::string MCmd;
    std::string MArg;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
