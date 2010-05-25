////////////////////////////////////////////////////////////////////////////////
// Filename  : game_mng.hh
// Authors   : Creteur Clement
// Last edit : 26/11/09 - 21h54
// Comment   :
////////////////////////////////////////////////////////////////////////////////
#ifndef GAME_MNG_HH
#define GAME_MNG_HH

#include "../useful/all.hh"
#include "../ui/interface_mng.hh"

#include "in_game_mng.hh"
#include "out_game_mng.hh"
#include "game_context.hh"
#include "state_handler.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
class GameMng : public Singleton<GameMng>,
                public Updatable,
                public InputListener /* FIXME (TEST) */
{
  friend class Singleton<GameMng>;

  public:
    virtual void Update();

    inline const InGameMng&   GetInGameMng()   const {return *MInGameMng;}
    inline const OutGameMng&  GetOutGameMng()  const {return *MOutGameMng;}
    inline const GameContext& GetGameContext() const {return *MGameContext;}

    /* FIXME (TEST) */
    virtual bool OnKeyboardEvent(const KeyboardEvent& parEvt);
    virtual void OnQuit() {exit(0);}

  private:
    GameMng();
    ~GameMng();

    InGameMng*        MInGameMng;
    OutGameMng*       MOutGameMng;
    GameContext*      MGameContext;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
