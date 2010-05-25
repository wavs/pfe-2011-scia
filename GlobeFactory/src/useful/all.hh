////////////////////////////////////////////////////////////////////////////////
// Filename  : all.hh
// Authors   : Clement Creteur
// Last edit :
// Comment   : include shortcut
////////////////////////////////////////////////////////////////////////////////
#ifndef USEFUL_ALL_HH
#define USEFUL_ALL_HH

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#include "auto_listener.hh"
#include "clock.hh"
#include "color.hh"
#include "command.hh"
#include "config_file.hh"
#include "config_mng.hh"
#include "executor.hh"
#include "input_listener.hh"
#include "input_mng.hh"
#include "launch_options_loader.hh"
#include "log.hh"
#include "macro.hh"
#include "manual_ref_counter.hh"
#include "notifier.hh"
#include "singleton.hh"
#include "templated_function.hh"
#include "timed_updater.hh"
#include "timer.hh"
#include "updatable.hh"
#include "user_input.hh"
#include "vector.hh"
#include "bounding_box.hh"
#include "xml_tree.hh"
#include "xml_node.hh"
#include "xml_loader.hh"
#include "xml_helper.hh"
#include "manager_loader.hh"
#include "animator.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

namespace useful
{
  inline void Initialize(int argc, char* argv[])
  {
    Log::get()->SetOutput("log.txt");
    Log::get()->SetVerboseLevel(Log::VERBOSE_ALL);

    LaunchOptionsLoader::get()->Initialize(argc, argv);

    Clock::get()->Initialize();
  }

  //----------------------------------------------------------------------------

  inline void Kill()
  {
    InputMng::kill();
    ConfigMng::kill();
    Executor::kill();
    XmlLoader::kill();
    LaunchOptionsLoader::kill();
    Clock::kill();
    Log::kill();
  }
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
