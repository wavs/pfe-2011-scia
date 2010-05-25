#include "window_loader.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

UIWindowLoader::UIWindowLoader()
  : UIParentLoader("window")
{
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

UIWindowLoader::~UIWindowLoader()
{
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

UIWindow* UIWindowLoader::LoadComponent(XmlNode* parNode)
{
  Vector2f pos, sz;

  if (!ExtractBase(parNode, pos, sz))
    return NULL;

  UIWindow* wnd = NULL;
  float barSize = 0.0f;
  if (parNode->GetAttribute("bar_size", barSize))
    wnd = new UIWindow(pos, sz, barSize);
  else
    wnd = new UIWindow(pos, sz);

  std::vector<UIComponent*> childs;
  ExtractChilds(parNode, childs);
  foreach(child, childs)
    wnd->AddComponent(*child);

  return wnd;


}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
