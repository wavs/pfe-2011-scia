////////////////////////////////////////////////////////////////////////////////
// Filename  : ui_button.hh
// Authors   : Creteur Clement
// Last edit : 13/02/10 - 18h54
// Comment   :
////////////////////////////////////////////////////////////////////////////////
#ifndef UI_BUTTON_HH
#define UI_BUTTON_HH

#include "ui_component.hh"
#include "../gfx/render_string.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class UIButton : public UIComponent
{
  public:
    UIButton(const Vector2f& parPosition, const Vector2f& parSize,
             const std::string& parMat = "",
             const std::string& parMatOn = "",
             const std::string& parMatClick = "");
    ~UIButton();

    UIButton* Clone() const;
    void Draw(const UIDrawingContext& parContext);
    void OnMouseMove(const Vector2f& parPosition);
    void OnMouseOn(const Vector2f& parPosition);
    void OnMouseOut();
    void OnEnter();
    bool OnMouseDown();
    bool OnMouseUp();

    virtual void Action() {LOG_RESUME("UIButton", "Abstract action");}

    inline void  SetColor(const Color& parColor)      {MColor = parColor;}
    inline void  SetColorOn(const Color& parColor)    {MColorOn = parColor;}
    inline void  SetColorClick(const Color& parColor) {MColorClick = parColor;}
    inline const Color& GetColor()      const {return MColor;}
    inline const Color& GetColorOn()    const {return MColorOn;}
    inline const Color& GetColorClick() const {return MColorClick;}

    inline void SetTextColor(const Color& parColor)      {MTextColor = parColor; if (!MOn) MText.SetColor(parColor);}
    inline void SetTextColorOn(const Color& parColor)    {MTextColorOn = parColor;}
    inline void SetTextColorClick(const Color& parColor) {MTextColorClick = parColor;}
    inline const Color& GetTextColor()      const {return MTextColor;}
    inline const Color& GetTextColorOn()    const {return MTextColorOn;}
    inline const Color& GetTextColorClick() const {return MTextColorClick;}

    inline void               SetText(const std::string& parText) {MText.SetText(parText);}
    inline const std::string& GetText() const                     {return MText.GetText();}

  private:
    Color        MColor;
    Color        MColorOn;
    Color        MColorClick;
    unsigned     MMat;
    unsigned     MMatOn;
    unsigned     MMatClick;

    Color        MTextColor;
    Color        MTextColorOn;
    Color        MTextColorClick;
    RenderString MText;

    bool         MDown;
    bool         MOn;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
