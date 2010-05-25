////////////////////////////////////////////////////////////////////////////////
// Filename  : main.cc
// Authors   : Creteur Clement
// Last edit : 15/11/09 - 20h06
// Comment   : Main function (with macro to launch the tests or the engine)
////////////////////////////////////////////////////////////////////////////////
#define TEST 0

#if TEST
  #include "test.hh"
#else
  #include "globe_engine.hh"
#endif

int main(int argc, char* argv[])
{
  int returnValue = 0;

#if TEST
  returnValue = main_test(argc, argv);
#else
  GlobeEngine* globeEngine = GlobeEngine::get();

  globeEngine->Initialize(argc, argv);
  returnValue = globeEngine->Launch();

  GlobeEngine::kill();
#endif

  return returnValue;
}
