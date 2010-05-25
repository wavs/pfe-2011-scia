#include "input_mng.hh"
#include "templated_function.hh"
#include "input_listener.hh"
#include "macro.hh"
#include "timer.hh"
#include "log.hh"
#include "../gfx/gfx_engine.hh"
#include "../gfx/render_window.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

InputMng::InputMng()
  : MDClickDelay(0.4f),
    MShiftState(false),
    MControlState(false),
    MAltState(false),
    MLastButtonTime(0.0f),
    MMousePosition(0.0f, 0.0f)
{
  MTimer = Clock::get()->CreateTimer();
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

InputMng::~InputMng()
{
  Clock::get()->DeleteTimer(MTimer);
  LOG_ASSERT(MLayers.empty());
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------


void InputMng::Register(InputListener* parListener)
{
  LOG_ASSERT(parListener != NULL);
#ifdef DEBUG
  foreach(it, MLayers)
    LOG_ASSERT(*it != parListener);
#endif
  LOG_RESUME("InputMng ", "New listener (" + parListener->GetName() +
                          ") with priority " +
                          misc::ToString(parListener->GetPriority()));

  unsigned size = MLayers.size();

  if (size == 0)
  {
    MLayers.push_back(parListener);
    return;
  }

  MLayers.push_back(NULL);
  for (unsigned cur = 0; cur < size; ++cur)
    if (MLayers[cur]->GetPriority() <= parListener->GetPriority())
    {
      if (MLayers[cur]->GetPriority() == parListener->GetPriority())
        LOG_WARNING("InputMng ", "Two listener with the same priority : '" +
                                 parListener->GetName() + "' and '" +
                                 MLayers[cur]->GetName() + "'");

      for (unsigned i = size; i > cur; --i)
        MLayers[i] = MLayers[i - 1];
      MLayers[cur] = parListener;
      return;
    }

  MLayers[size] = parListener;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void InputMng::Unregister(InputListener* parListener)
{
  foreach(it, MLayers)
    if (*it == parListener)
    {
      MLayers.erase(it);
      LOG_RESUME("InputMng ", "Unregister listener (" + parListener->GetName() +
                          ") with priority " +
                          misc::ToString(parListener->GetPriority()));
      return;
    }

  LOG_WARNING("InputMng ", "Try to unregister a listener that is not register.");
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void InputMng::Update()
{
  while(SDL_PollEvent(&MSDLEvent))
  {
    bool isUp = false;

    switch(MSDLEvent.type)
    {
      ///////////////////////
      // Evenement de quit //
      ///////////////////////
      case SDL_QUIT:
      {
        foreach(it, MLayers)
          (*it)->OnQuit();
      }
      break;
      ///////////////////////
      // Evenement clavier //
      ///////////////////////
      case SDL_KEYUP:
      {
        isUp = true;
      }
      case SDL_KEYDOWN:
      {
        SDLKey key = MSDLEvent.key.keysym.sym;
        if (key == SDLK_RSHIFT || key == SDLK_LSHIFT)
          MShiftState = !isUp;
        else if (key == SDLK_RCTRL || key == SDLK_LCTRL)
          MControlState = !isUp;
        else if (key == SDLK_RALT || key == SDLK_LALT)
          MAltState = !isUp;

        KeyboardEvent keyboardEvent(isUp,
                                    key,
                                    (Uint8) MSDLEvent.key.keysym.scancode,
                                    (Uint16) MSDLEvent.key.keysym.unicode);

        keyboardEvent.SetKeyStates(MShiftState, MControlState, MAltState);

        foreach(it, MLayers)
          if ((*it)->OnKeyboardEvent(keyboardEvent))
            keyboardEvent.SetMasked();
      }
      break;
      //////////////////////////////////
      // Evenement Deplacement Souris //
      //////////////////////////////////
      case SDL_MOUSEMOTION:
      {
        MMousePosition.Set(MSDLEvent.motion.x, GfxEngine::get()->GetWindow()->GetResolution().y() - MSDLEvent.motion.y);
        MouseEvent mouseEvent(MSDLEvent.motion.x,
                              GfxEngine::get()->GetWindow()->GetResolution().y() - MSDLEvent.motion.y,
                              MSDLEvent.motion.xrel,
                              -MSDLEvent.motion.yrel);

        mouseEvent.SetKeyStates(MShiftState, MControlState, MAltState);

        foreach(it, MLayers)
          if ((*it)->OnMouseEvent(mouseEvent))
            mouseEvent.SetMasked();
      }
      break;
      //////////////////////////////
      // Evenement Clic Up Souris //
      //////////////////////////////
      case SDL_MOUSEBUTTONUP:
      {
        MouseEvent mouseEvent(true, MSDLEvent.button.x, MSDLEvent.button.y,
                              SDLToEvt(MSDLEvent.button.button));

        mouseEvent.SetKeyStates(MShiftState, MControlState, MAltState);

        foreach(it, MLayers)
          if ((*it)->OnMouseEvent(mouseEvent))
            mouseEvent.SetMasked();
      }
      break;
      ////////////////////////////////
      // Evenement Clic Down Souris //
      ////////////////////////////////
      case SDL_MOUSEBUTTONDOWN:
      {
        MouseEvent::Type button = SDLToEvt(MSDLEvent.button.button);

        MouseEvent mouseEvent(false,
                              MSDLEvent.button.x,
                              MSDLEvent.button.y,
                              button);

        mouseEvent.SetKeyStates(MShiftState, MControlState, MAltState);

        if (MLastButtonTime != 0 && button == MLastButton &&
            MTimer->ElapsSince(MLastButtonTime) < MDClickDelay)
        {
          MLastButtonTime = 0;
          mouseEvent.Double();
        }
        else
        {
          MLastButtonTime = MTimer->GetTimeFromCreation();
          MLastButton = button;
        }

        foreach(it, MLayers)
          if ((*it)->OnMouseEvent(mouseEvent))
            mouseEvent.SetMasked();
      }
      break;
    }
  }
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

MouseEvent::Type InputMng::SDLToEvt(int parButton)
{
  if (parButton == SDL_BUTTON_LEFT)
    return MouseEvent::EVT_CLICK_MOUSE1;
  if (parButton == SDL_BUTTON_RIGHT)
    return MouseEvent::EVT_CLICK_MOUSE1;
  if (parButton == SDL_BUTTON_MIDDLE)
    return MouseEvent::EVT_CLICK_MOUSE1;
  return MouseEvent::EVT_MOVE;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
