////////////////////////////////////////////////////////////////////////////////
// Filename  : ui_check_box.hh
// Authors   : Creteur Clement
// Last edit : 18/03/10 - 20h19
// Comment   :
////////////////////////////////////////////////////////////////////////////////
#ifndef UI_CHECK_BOX_HH
#define UI_CHECK_BOX_HH

#include "ui_component.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class UICheckBox : public UIComponent
{
  public:
    UICheckBox(const Vector2f& parPosition, const Vector2f& parSize = Vector2f(15.f,15.f), bool parState = false);
    ~UICheckBox();

    UICheckBox* Clone() const;
    void Draw(const UIDrawingContext& parContext);
    bool OnMouseDown();

    inline bool GetState() const {return MState;}

  private:
    bool MState;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
