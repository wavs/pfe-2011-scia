////////////////////////////////////////////////////////////////////////////////
// Filename  : updatable.hh
// Authors   : Creteur Clement
// Last edit : 08/11/09 - 20h27
// Comment   : Can be used by the updators
////////////////////////////////////////////////////////////////////////////////
#ifndef USEFUL_UPDATABLE_HH
#define USEFUL_UPDATABLE_HH

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class Updatable
{
  public:
    Updatable() {}
    virtual ~Updatable() {}

    virtual void Update() = 0;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif