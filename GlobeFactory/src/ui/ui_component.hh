////////////////////////////////////////////////////////////////////////////////
// Filename  : ui_component.hh
// Authors   : Creteur Clement
// Last edit : 29/12/09 - 22h14
// Comment   :
////////////////////////////////////////////////////////////////////////////////
#ifndef UI_COMPONENT_HH
#define UI_COMPONENT_HH

#include "../useful/all.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class UIContainer;

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class UIComponent
{
  friend class UIContainer;

  public:
    //----------------------//
    struct UIDrawingContext //
    {                       //
      Vector2f position;    //
      Vector2f size;        //
    };                      //
    //----------------------//

    UIComponent(const Vector2f& parPosition, const Vector2f& parSize);
    virtual ~UIComponent();

    virtual UIComponent* Clone() const                            = 0;
    virtual void         Draw(const UIDrawingContext& parContext) = 0;

    virtual void OnMouseMove(const Vector2f& parPosition) {}
    virtual void OnMouseOn(const Vector2f& parPosition)   {}
    virtual void OnMouseOut()                             {}
    virtual void OnEnter()                                {}
    virtual void OnScroll(float parDelta)                 {}
    virtual bool OnMouseDown()                            {return true;}
    virtual bool OnMouseUp()                              {return true;}

    inline UIContainer*    GetParent()                     {return MParent;}
    inline const Vector2f& GetPosition()   const           {return MPosition;}
    inline const Vector2f& GetSize()       const           {return MSize;}
    inline bool            GetVisibility() const           {return MVisible;};
    inline void            SetVisibility(bool parVisible)  {MVisible = parVisible;};

    inline UIComponent* GetFocus()                      {return MFocus;}
    inline void         SetFocus(UIComponent* parFocus) {MFocus = parFocus;}

    const Vector2f  GetAbsPosition() const;

  protected:
    UIContainer* MParent;
    Vector2f     MPosition;
    Vector2f     MSize;
    bool         MVisible;
    UIComponent* MFocus;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
