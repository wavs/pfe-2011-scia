#include "xml_tree.hh"
#include "macro.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

XmlTree::XmlTree()
{
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

XmlTree::~XmlTree()
{
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void XmlTree::Save(const std::string& parFilename)
{
  boost::mutex::scoped_lock lock(MXmlMutex);
  LOG_ASSERT(MRoot != NULL);

  MRoot->ToDocument()->SaveFile(parFilename);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

bool XmlTree::Load(const std::string& parFilename)
{
  boost::mutex::scoped_lock lock(MXmlMutex);

  delete MRoot;
  foreach(it, MChilds)
    delete *it;

  MFilename = parFilename;
  MRoot = new TiXmlDocument(parFilename);

  if (MRoot->ToDocument()->LoadFile())
  {
    FillTree();
    return true;
  }
  return false;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void XmlTree::Clear()
{
  boost::mutex::scoped_lock lock(MXmlMutex);

  foreach(it, MChilds)
  {
    (*it)->MRoot = NULL;
    delete *it;
  }
  MChilds.clear();

  delete MRoot;
  MRoot = NULL;

}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
