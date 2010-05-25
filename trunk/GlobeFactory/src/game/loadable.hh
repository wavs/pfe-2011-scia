////////////////////////////////////////////////////////////////////////////////
// Filename  : loadable.hh
// Authors   : Creteur Clement
// Last edit : 12/12/09 - 17h30
// Comment   :
////////////////////////////////////////////////////////////////////////////////
#ifndef GAME_LOADABLE_HH
#define GAME_LOADABLE_HH

#include "../useful/log.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class Loadable
{
  public:
    Loadable() : MLoaded(true) {}
    virtual ~Loadable() {}

    inline  bool IsLoaded() const {return MLoaded;}

    inline  void operator() ()
    {
      LOG_ASSERT(MLoaded == false);
      Load(MFile);
      MLoaded = true;
    }

    inline void PrepareLoading(const std::string& parFile)
    {
      MLoaded = false;
      MFile = parFile;
    }


  protected:
    virtual void Load(const std::string parFilename) = 0;

  private:
    bool        MLoaded;
    std::string MFile;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
