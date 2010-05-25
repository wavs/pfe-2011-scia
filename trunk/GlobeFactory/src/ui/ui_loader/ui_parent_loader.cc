#include "ui_parent_loader.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

UIParentLoader::UIParentLoader(const std::string& parName)
  : UILoader(parName)
{
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

UIParentLoader::~UIParentLoader()
{
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void UIParentLoader::ExtractChilds(XmlNode* parNode,
                                   std::vector<UIComponent*>& parChilds,
                                   bool parExtractNode)
{
  LOG_ASSERT(parNode != NULL);

  std::vector<XmlNode*> nodes;

  if (parExtractNode)
    parNode->GetNodes("childs", nodes);
  else
    nodes.push_back(parNode);

  foreach(it, nodes)
  {
    std::map<std::string, UILoader*>& uils = MLoaders;
    foreach(loader, uils)
    {
      std::vector<XmlNode*> childs;
      (*it)->GetNodes(loader->first, childs);

      foreach(child, childs)
      {
        UIComponent* c = (loader->second)->LoadComponent(*child);
        if (c != NULL)
          parChilds.push_back(c);
      }
    }
  }
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
