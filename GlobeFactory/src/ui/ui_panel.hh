////////////////////////////////////////////////////////////////////////////////
// Filename  : ui_panel.hh
// Authors   : Creteur Clement
// Last edit : 13/02/10 - 18h54
// Comment   :
////////////////////////////////////////////////////////////////////////////////
#ifndef UI_PANEL_HH
#define UI_PANEL_HH

#include "ui_container.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class UIPanel : public UIContainer
{
  public:
    UIPanel(const Vector2f& parPosition, const Vector2f& parSize);
    ~UIPanel();

    UIPanel* Clone() const;

    void Draw(const UIDrawingContext& parContext);
    void OnMouseMove(const Vector2f& parPosition);
    void OnMouseOn(const Vector2f& parPosition);
    void OnMouseOut();
    bool OnMouseDown();
    bool OnMouseUp();

    void  SetColor(const Color& parColor) {MColor = parColor;}
    const Color& GetColor() const         {return MColor;}

  private:
    Color MColor;
    bool  MMouseOn;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
