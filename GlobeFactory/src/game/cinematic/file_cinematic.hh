////////////////////////////////////////////////////////////////////////////////
// Filename  : file_cinematic.hh
// Authors   : Creteur Clement
// Last edit : 09/04/10 - 17h30
// Comment   :
////////////////////////////////////////////////////////////////////////////////
#ifndef GAME_FILE_CINEMATIC_HH
#define GAME_FILE_CINEMATIC_HH

#include "cinematic.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class FileCinematic : public Cinematic
{
  public:
    FileCinematic();
    ~FileCinematic();

    void Update();
    void Start(const std::string& parArg = "");
    void Finish();

  private:

};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
