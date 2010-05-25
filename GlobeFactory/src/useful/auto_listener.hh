////////////////////////////////////////////////////////////////////////////////
// Filename  : auto_listener.hh
// Authors   : Creteur Clement
// Last edit : 11/11/09 - 16h00
// Comment   :
////////////////////////////////////////////////////////////////////////////////
#ifndef USEFUL_AUTO_LISTENER_HH
#define USEFUL_AUTO_LISTENER_HH

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

template<class TSelf, class TNotifier>
class AutoListener
{
  public:
    AutoListener()
    {
      TNotifier::get()->Register(static_cast<TSelf*>(this));
    }

    virtual ~AutoListener()
    {
      TNotifier::get()->Unregister(static_cast<TSelf*>(this));
    }
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
