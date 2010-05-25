////////////////////////////////////////////////////////////////////////////////
// Filename  : ui_container.hh
// Authors   : Creteur Clement
// Last edit : 07/02/10 - 18h54
// Comment   :
////////////////////////////////////////////////////////////////////////////////
#ifndef UI_CONTAINER_HH
#define UI_CONTAINER_HH

#include "ui_component.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class UIContainer : public UIComponent
{
  public:
    UIContainer(const Vector2f& parPosition, const Vector2f& parSize);
    ~UIContainer();

    UIContainer* Clone() const;

    void Draw(const UIDrawingContext& parContext);
    void OnMouseMove(const Vector2f& parPosition);
    void OnMouseOn(const Vector2f& parPosition);
    void OnMouseOut();

    void OnEnter();
    void OnScroll(float parDelta);
    bool OnMouseDown();
    bool OnMouseUp();

    void AddComponent(UIComponent* parChild);
    void RemoveComponent(UIComponent* parChild);
    void PutFront(UIComponent* parChild);
    void PutBack(UIComponent* parChild);
    void Clear();
    void ClearAndDelete();

  protected:
    UIComponent* GetFirstChildUnderPosition(const Vector2f& parPosition);
    void GetChildsUnderPosition(const Vector2f& parPosition, std::vector<UIComponent*>& parChilds);

    std::list<UIComponent*> MChilds;
    Vector2f                MLastMousePosition;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
