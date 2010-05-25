#include "interface_loader.hh"
#include "../user_interface.hh"
#include "all.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

InterfaceLoader::InterfaceLoader()
  : UIParentLoader("interface")
{
  if (!MLoaders.empty())
  {
    LOG_WARNING("InterfaceLoader", "The interface loader has already been created.");
    return;
  }

  MLoaders["button"] = new UIButtonLoader();
  MLoaders["combo_box"] = new UIComboBoxLoader();
  MLoaders["window"] = new UIWindowLoader();
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

InterfaceLoader::~InterfaceLoader()
{
  LOG_ASSERT(!MLoaders.empty());

  foreach(it, MLoaders)
    delete it->second;

  MLoaders.clear();
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

UserInterface* InterfaceLoader::LoadComponent(XmlNode* parNode)
{
  LOG_ASSERT(parNode != NULL);
  LOG_ASSERT(parNode->GetName() == MName);

  UserInterface* ui = new UserInterface();

  std::vector<UIComponent*> childs;
  ExtractChilds(parNode, childs, false);
  foreach(child, childs)
    ui->AddComponent(*child);

  return ui;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
