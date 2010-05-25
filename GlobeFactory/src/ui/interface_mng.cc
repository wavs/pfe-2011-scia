#include "interface_mng.hh"
#include "user_interface.hh"
#include "ui_loader/interface_loader.hh"
#include "../gfx/gfx_engine.hh"
#include "../gfx/render_window.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

InterfaceMng::InterfaceMng()
  : InputListener(100, "InterfaceMng"),
    MInterfaceLoader(NULL)

{
  MInterfaceLoader = new InterfaceLoader();
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

InterfaceMng::~InterfaceMng()
{
  unsigned size = MInterfaces.size();
  for (unsigned i = 0; i < size; ++i)
  {
    LOG_ASSERT(MInterfaces[i] == NULL);
    delete MInterfaces[i];
  }

  delete MInterfaceLoader;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void InterfaceMng::Update()
{
  Vector2i reso = GfxEngine::get()->GetWindow()->GetResolution();

  UIComponent::UIDrawingContext context;
  context.position = Vector2f(0.0f, 0.0f);
  context.size     = Vector2f(reso.x(), reso.y());

  foreach(ui, MInterfaces)
    if ((*ui != NULL) && (*ui)->GetVisibility())
      (*ui)->Draw(context);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

unsigned InterfaceMng::CreateInterface()
{
  UserInterface* interface = new UserInterface();

  unsigned size = MInterfaces.size();
  for (unsigned i = 0; i < size; ++i)
    if (MInterfaces[i] == NULL)
    {
      MInterfaces[i] = interface;
      return i;
    }

  MInterfaces.push_back(interface);
  return size;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void InterfaceMng::DeleteInterface(unsigned parId)
{
  LOG_ASSERT(parId <= MInterfaces.size());
  LOG_ASSERT(MInterfaces[parId] != NULL);

  delete MInterfaces[parId];
  MInterfaces[parId] = NULL;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void InterfaceMng::ToggleVisibility(unsigned parId)
{
  LOG_ASSERT(parId <= MInterfaces.size());
  LOG_ASSERT(MInterfaces[parId] != NULL);

  MInterfaces[parId]->SetVisibility(!MInterfaces[parId]->GetVisibility());
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void InterfaceMng::SetVisibility(unsigned parId, bool parVisible)
{
  LOG_ASSERT(parId <= MInterfaces.size());
  LOG_ASSERT(MInterfaces[parId] != NULL);

  MInterfaces[parId]->SetVisibility(parVisible);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void InterfaceMng::AddComponent(unsigned parId, UIComponent* parCompo)
{
  LOG_ASSERT(parId <= MInterfaces.size());
  LOG_ASSERT(MInterfaces[parId] != NULL);
  LOG_ASSERT(parCompo != NULL);

  MInterfaces[parId]->AddComponent(parCompo);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

bool InterfaceMng::OnKeyboardEvent(const KeyboardEvent& parEvent)
{
  // Passer les evenement claviers
  return false;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

bool InterfaceMng::OnMouseEvent(const MouseEvent& parEvent)
{
  // FIXME : bien gerer les return
  unsigned size = MInterfaces.size();

  if (parEvent.GetType() == MouseEvent::EVT_CLICK_MOUSE1)
  {
    for (unsigned i = 0; i < size; ++i)
      if (MInterfaces[i] != NULL && MInterfaces[i]->GetVisibility())
      {
        if (parEvent.IsKeyDown())
        {
          if (MInterfaces[i]->OnMouseDown()) break;
        }
        else
        {
          if (MInterfaces[i]->OnMouseUp()) break;
        }
      }
  }
  else if (parEvent.GetDx() != 0 || parEvent.GetDy() != 0)
  {
    Vector2f position(parEvent.GetX(), parEvent.GetY());
    for (unsigned i = 0; i < size; ++i)
      if (MInterfaces[i] != NULL && MInterfaces[i]->GetVisibility())
        MInterfaces[i]->OnMouseMove(position);
  }
  return false;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

unsigned InterfaceMng::LoadFromXML(const std::string& parFilename)
{
  UserInterface* interface = NULL;
  XmlTree* tree = XmlLoader::get()->Open(parFilename);
  XmlNode* node = NULL;

  if (tree != NULL)
  {
    node = tree->GetNode("interface");
    if (node != NULL)
      interface = MInterfaceLoader->LoadComponent(node);
  }

  if (interface == NULL)
  {
    interface = new UserInterface();
    LOG_ERROR("InterfaceMng", "Error during the loading of the interface " + parFilename);
  }

  unsigned size = MInterfaces.size();
  unsigned pos  = size;
  for (unsigned i = 0; i < size; ++i)
    if (MInterfaces[i] == NULL)
    {
      pos = i;
      break;
    }

  if (pos == size)
    MInterfaces.push_back(interface);
  else
    MInterfaces[pos] = interface;

  XmlLoader::get()->Close(tree);

  return size;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
