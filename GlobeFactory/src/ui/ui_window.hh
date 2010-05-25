////////////////////////////////////////////////////////////////////////////////
// Filename  : ui_window.hh
// Authors   : Creteur Clement
// Last edit : 15/03/10 - 20h54
// Comment   :
////////////////////////////////////////////////////////////////////////////////
#ifndef UI_WINDOW_HH
#define UI_WINDOW_HH

#include "ui_container.hh"
#include "../gfx/render_string.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class UIWindow : public UIContainer
{
  public:
    UIWindow(const Vector2f& parPosition, const Vector2f& parSize, float parBarSize = 20.f);
    ~UIWindow();

    UIWindow* Clone() const;
    void Draw(const UIDrawingContext& parContext);

    void OnMouseMove(const Vector2f& parPosition);
    void OnMouseOn(const Vector2f& parPosition);
    void OnMouseOut();
    bool OnMouseDown();
    bool OnMouseUp();

  private:
    float MBarSize;
    bool  MIsSelected;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
