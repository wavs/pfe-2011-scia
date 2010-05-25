#include "xml_loader.hh"
#include "xml_tree.hh"
#include "macro.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

XmlTree* XmlLoader::Open(const std::string& parFilename)
{
  boost::mutex::scoped_lock lock(MOpenMutex);

  XmlTree* xmlTree = NULL;
  if (MXmlTrees.count(parFilename) != 0)
  {
    xmlTree = MXmlTrees[parFilename];
    xmlTree->IncRefCount();
  }
  else
  {
    xmlTree = new XmlTree();
    xmlTree->Load(parFilename);
    MXmlTrees[parFilename] = xmlTree;
  }

  return xmlTree;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void XmlLoader::Close(XmlTree* parXmlTree)
{
  boost::mutex::scoped_lock lock(MOpenMutex);

  LOG_ASSERT(parXmlTree != NULL);

  foreach(it, MXmlTrees)
  {
    if (it->second == parXmlTree)
    {
      if (parXmlTree->GetRefCount() <= 1)
      {
        delete parXmlTree;
        MXmlTrees.erase(it->first);
      }
      else
        parXmlTree->DecRefCount();

      return;
    }
  }

  LOG_ERROR("XmlLoader", "Try to close an unload XmlTree");
  LOG_ASSERT(false);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

XmlTree* XmlLoader::Create(const std::string& parFilename)
{
  boost::mutex::scoped_lock lock(MOpenMutex);

  if (MXmlTrees.count(parFilename) != 0)
  {
    LOG_ERROR("XmlLoader", "Try to create an opened file.");
    return NULL;
  }

  XmlTree* xmlTree = new XmlTree();
  xmlTree->SetFilename(parFilename);
  MXmlTrees[parFilename] = xmlTree;

  return xmlTree;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
