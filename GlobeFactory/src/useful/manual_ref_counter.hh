////////////////////////////////////////////////////////////////////////////////
// Filename  : manual_ref_counter.hh
// Authors   : Creteur Clement
// Last edit : 08/11/09 - 20h24
// Comment   : useful to simply count the reference on an object
////////////////////////////////////////////////////////////////////////////////
#ifndef USEFUL_MANUAL_REF_COUNTER_HH
#define USEFUL_MANUAL_REF_COUNTER_HH

#include "log.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class ManualRefCounter
{
  public:
    ManualRefCounter() : MRefCount(1) {}
    virtual ~ManualRefCounter()       {}

    inline void IncRefCount()       {++MRefCount;}
    inline void DecRefCount()       {LOG_ASSERT(MRefCount); --MRefCount;}
    inline int  GetRefCount() const {return MRefCount;}

  private:
    int MRefCount;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
