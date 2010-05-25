////////////////////////////////////////////////////////////////////////////////
// Filename  : notifier.hh
// Authors   : Creteur Clement
// Last edit : 11/11/09 - 16h00
// Comment   :
////////////////////////////////////////////////////////////////////////////////
#ifndef USEFUL_NOTIFIER_HH
#define USEFUL_NOTIFIER_HH

#include <list>
#include "log.hh"
#include "templated_function.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

template<class TListener>
class Notifier
{
  public:
    inline virtual void Register(TListener* parClient)
    {
      LOG_ASSERT(parClient != NULL);
      LOG_ASSERT(!misc::find(parClient, MClients));

      MClients.push_back(parClient);
    }

    inline virtual void Unregister(TListener* parClient)
    {
      LOG_ASSERT(misc::find(parClient, MClients));

      MClients.remove(parClient);
    }

  protected:
    Notifier() {}
    virtual ~Notifier() {}

    std::list<TListener*> MClients;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
