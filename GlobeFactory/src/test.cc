#include "test.hh"

#include <iostream>
#include "useful/timer.hh"
#include "useful/log.hh"
#include "useful/config_mng.hh"
#include "useful/auto_listener.hh"
#include "useful/notifier.hh"
#include "useful/macro.hh"
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

/*
void threaded_function(const std::string& path, int i)
{
  XmlTree& xmlT = XmlLoader::get()->Open(path);

  std::string name = std::string("option");
  XmlNode& xmlN = xmlT.addNode(name).addNode(name);
  xmlN.setAttribute("test", i);
  xmlN.setText("test de texte");
  xmlT.save();
  XmlLoader::get()->Close(xmlT);
}

void threaded_function2(const std::string& path, int i)
{
  XmlTree& xmlT = XmlLoader::get()->Open(path);
  std::vector<XmlNode*> vec;
  xmlT.getNodes("option", vec);
  foreach(it, vec)
    (*it)->setAttribute("YOP", i);

  xmlT.save();
  XmlLoader::get()->Close(xmlT);
}
*/

int main_test(int argc, char* argv[])
{
  Log::get()->SetOutput("log.txt");
  Log::get()->SetVerboseLevel(Log::VERBOSE_ALL);

  XmlTree* openFile = XmlLoader::get()->Open("menu.xml");
  if (openFile == NULL)
    LOG_RESUME("Test    ", "Fichier pas ouvert !");

  XmlTree* createFile = XmlLoader::get()->Create("menu.xml");
  if (createFile == NULL)
    LOG_RESUME("Test    ", "Fichier pas créé");


  XmlNode* node = openFile->GetNode("menu");
  if (node == NULL)
    LOG_RESUME("Test    ", "bug bug bug");
  int a;
  if (!node->GetAttribute("test", a))
    LOG_RESUME("Test    ", "pas de param");
  else
    LOG_RESUME("Test    ", "param : " + misc::ToString(a));

  node->SetAttribute("test", 200);

  openFile->Clear();

  //openFile->Save();

  /*
  Clock::get()->Initialize();

  for(unsigned i = 0; i < 2; ++i)
    std::cin >> i;

  Timer* t1 = Clock::get()->CreateTimer();
  Timer* t2 = Clock::get()->CreateTimer();

  t1->SetScale(2.0f);
  t2->SetScale(0.5f);

    std::cout << "timer1 : " << t1->GetTimeFromCreation() << std::endl;
    std::cout << "timer2 : " << t2->GetTimeFromCreation() << std::endl;
    std::cout << "clock  : " << Clock::get()->GetCurTime() << std::endl;

  for(unsigned i = 0; i < 2; ++i)
  {
    std::cin >> i;
    Clock::get()->Update();

    std::cout << "timer1 : " << t1->GetTimeFromCreation() << std::endl;
    std::cout << "timer2 : " << t2->GetTimeFromCreation() << std::endl;
    std::cout << "clock  : " << Clock::get()->GetCurTime() << std::endl;
  }

  Clock::get()->DeleteTimer(t1);
  Clock::get()->DeleteTimer(t2);

  Clock::kill();
  {
    boost::thread_group group ;
    boost::thread_group group2 ;
    std::string str = std::string("test.xml");

    for (int i = 0; i < 10; ++i)
    {
      group.create_thread(boost::bind(&threaded_function, str, i));
      group.join_all();
      group2.create_thread(boost::bind(&threaded_function2, str, i));
      group2.join_all();
    }

    XmlLoader::kill();
  }
  */

  Log::kill();
  return 0;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
