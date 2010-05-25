#include "ui_component.hh"
#include "ui_container.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

UIComponent::UIComponent(const Vector2f& parPosition, const Vector2f& parSize)
  : MParent(NULL),
    MPosition(parPosition),
    MSize(parSize),
    MVisible(true),
    MFocus(NULL)
{
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

UIComponent::~UIComponent()
{
  if (MParent != NULL)
    MParent->RemoveComponent(this);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

const Vector2f UIComponent::GetAbsPosition() const
{
  return (MParent == NULL) ? MPosition : MPosition + MParent->GetAbsPosition();
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
