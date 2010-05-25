////////////////////////////////////////////////////////////////////////////////
// Filename  : xml_loader.hh
// Authors   : Bellanger David
// Last edit :
// Comment   :
////////////////////////////////////////////////////////////////////////////////
#ifndef USEFUL_XML_LOADER_HH
#define USEFUL_XML_LOADER_HH

#include "singleton.hh"
#include <string>
#include <boost/thread/mutex.hpp>
#include "log.hh"
#include <map>

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class XmlTree;

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class XmlLoader : public Singleton<XmlLoader>
{
  friend class Singleton<XmlLoader>;

  public:
    XmlTree* Open(const std::string& parFilename);
    XmlTree* Create(const std::string& parFilename);
    void     Close(XmlTree* parXmlTree);

  private:
    XmlLoader()  {}
    ~XmlLoader() {LOG_ASSERT(MXmlTrees.empty());}

    std::map<std::string, XmlTree*> MXmlTrees;
    boost::mutex                    MOpenMutex;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
