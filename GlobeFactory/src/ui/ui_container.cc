#include "ui_container.hh"
#include "../useful/macro.hh"
#include "../useful/bounding_box.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

UIContainer::UIContainer(const Vector2f& parPosition, const Vector2f& parSize)
  : UIComponent(parPosition, parSize),
    MLastMousePosition(-1.0f, 0.0f)
{
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

UIContainer::~UIContainer()
{
  ClearAndDelete();
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

UIContainer* UIContainer::Clone() const
{
  UIContainer* uic = new UIContainer(MPosition, MSize);

  const_foreach(child, MChilds)
    uic->MChilds.push_back((*child)->Clone());

  return uic;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void UIContainer::Draw(const UIDrawingContext& parContext)
{
  UIDrawingContext context = parContext;
  context.position += MPosition;

  reverse_foreach(child, MChilds)
    if ((*child)->GetVisibility())
      (*child)->Draw(context);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void UIContainer::OnMouseMove(const Vector2f& parPosition)
{
  UIComponent* lastChild = GetFirstChildUnderPosition(MLastMousePosition);
  UIComponent* currChild = GetFirstChildUnderPosition(parPosition);
  MLastMousePosition = parPosition;

  if (lastChild == currChild)
  {
    if (lastChild != NULL)
      lastChild->OnMouseMove(parPosition - lastChild->MPosition);
  }
  else
  {
    if (lastChild != NULL)
      lastChild->OnMouseOut();
    if (currChild != NULL)
      currChild->OnMouseOn(parPosition - currChild->MPosition);
  }
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void UIContainer::OnMouseOut()
{
  UIComponent* lastChild = GetFirstChildUnderPosition(MLastMousePosition);

  if (NULL != lastChild)
    lastChild->OnMouseOut();
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void UIContainer::OnMouseOn(const Vector2f& parPosition)
{
  UIComponent* currChild = GetFirstChildUnderPosition(parPosition);
  MLastMousePosition = parPosition;

  if (NULL != currChild)
    currChild->OnMouseOn(parPosition - currChild->MPosition);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

bool UIContainer::OnMouseDown()
{
  std::vector<UIComponent*> childs;
  GetChildsUnderPosition(MLastMousePosition, childs);
  unsigned size = childs.size();

  for (unsigned i = 0; i < size; ++i)
    if (childs[i]->OnMouseDown())
      return true;

  return false;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

bool UIContainer::OnMouseUp()
{
  std::vector<UIComponent*> childs;
  GetChildsUnderPosition(MLastMousePosition, childs);
  unsigned size = childs.size();

  for (unsigned i = 0; i < size; ++i)
    if (childs[i]->OnMouseUp())
      return true;

  return false;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void UIContainer::OnEnter()
{
  if (MFocus != NULL && MFocus->GetVisibility())
    MFocus->OnEnter();
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void UIContainer::OnScroll(float parDelta)
{
  if (MFocus != NULL && MFocus->GetVisibility())
    MFocus->OnScroll(parDelta);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void UIContainer::AddComponent(UIComponent* parChild)
{
  LOG_ASSERT(parChild != NULL);
  LOG_ASSERT(!misc::find(parChild, MChilds));

  parChild->MParent = this;
  MChilds.push_back(parChild);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void UIContainer::RemoveComponent(UIComponent* parChild)
{
  LOG_ASSERT(parChild != NULL);
  LOG_ASSERT(misc::find(parChild, MChilds));

  if (parChild == MFocus)
  {
    MFocus = NULL;

    UIContainer* older = MParent;
    while (older != NULL)
    {
      older->SetFocus(NULL);
      older = older->MParent;
    }
  }

  MChilds.remove(parChild);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void UIContainer::PutFront(UIComponent* parChild)
{
  LOG_ASSERT(parChild != NULL);
  LOG_ASSERT(misc::find(parChild, MChilds));

  MChilds.remove(parChild);
  MChilds.push_front(parChild);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void UIContainer::PutBack(UIComponent* parChild)
{
  LOG_ASSERT(parChild != NULL);
  LOG_ASSERT(misc::find(parChild, MChilds));

  MChilds.remove(parChild);
  MChilds.push_back(parChild);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void UIContainer::Clear()
{
  foreach(child, MChilds)
    (*child)->MParent = NULL;

  MChilds.clear();
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void UIContainer::ClearAndDelete()
{
  foreach(child, MChilds)
  {
    (*child)->MParent = NULL;
    delete *child;
  }

  MChilds.clear();
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

UIComponent* UIContainer::GetFirstChildUnderPosition(const Vector2f& parPosition)
{
  foreach(child, MChilds)
    if ((*child)->GetVisibility())
    {
      BB2f bb((*child)->MPosition, (*child)->MPosition + (*child)->MSize);
      if (bb.IsPosIn(parPosition))
        return *child;
    }

  return NULL;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void UIContainer::GetChildsUnderPosition(const Vector2f& parPosition, std::vector<UIComponent*>& parChilds)
{
  foreach(child, MChilds)
    if ((*child)->GetVisibility())
    {
      BB2f bb((*child)->MPosition, (*child)->MPosition + (*child)->MSize);
      if (bb.IsPosIn(parPosition))
        parChilds.push_back(*child);
    }
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
