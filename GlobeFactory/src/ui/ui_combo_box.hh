////////////////////////////////////////////////////////////////////////////////
// Filename  : ui_combo_box.hh
// Authors   : Creteur Clement
// Last edit : 15/03/10 - 21h19
// Comment   :
////////////////////////////////////////////////////////////////////////////////
#ifndef UI_COMBO_BOX_HH
#define UI_COMBO_BOX_HH

#include "ui_component.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class UIComboBox : public UIComponent
{
  public:
    UIComboBox(const Vector2f& parPosition, const Vector2f& parSize = Vector2f(15.f,15.f), bool parState = false);
    ~UIComboBox();

    UIComboBox* Clone() const;
    void Draw(const UIDrawingContext& parContext);
    bool OnMouseDown();

    inline bool GetState() const {return MState;}

  private:
    bool MState;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
