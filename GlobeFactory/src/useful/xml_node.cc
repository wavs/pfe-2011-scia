#include "xml_node.hh"
#include "macro.hh"
#include "const.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

XmlNode::XmlNode(TiXmlNode* parXmlNode)
{
  MRoot = parXmlNode;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

XmlNode::XmlNode(const std::string& parName, const std::string& parText)
{
  MRoot = new TiXmlElement(parName);
  SetText(parText);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

XmlNode::XmlNode(const XmlNode&)
{
  LOG_ASSERT(false);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

XmlNode::~XmlNode()
{
  foreach(it, MChilds)
  {
    (*it)->MRoot = NULL;
    delete *it;
  }

  delete MRoot;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

const std::string& XmlNode::GetText()
{
  boost::mutex::scoped_lock lock(MXmlMutex);

  if (MRoot->FirstChild() && MRoot->FirstChild()->Type() == TiXmlNode::TEXT)
    return MRoot->FirstChild()->ToText()->ValueStr();

  return constVar::EMPTY_STRING;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void XmlNode::SetName(const std::string& parName)
{
  boost::mutex::scoped_lock lock(MXmlMutex);
  MRoot->SetValue(parName.c_str());
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void XmlNode::SetText(const std::string& parName)
{
  boost::mutex::scoped_lock lock(MXmlMutex);

  TiXmlText xmlTxt(parName.c_str());
  MRoot->InsertEndChild(xmlTxt);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

const std::string& XmlNode::GetName()
{
  LOG_ASSERT(MRoot != NULL);
  return MRoot->ValueStr();
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

XmlNode* XmlNode::AddNode(const std::string& parName)
{
  boost::mutex::scoped_lock lock(MXmlMutex);

  TiXmlNode* txmlN = new TiXmlElement(parName);
  MRoot->LinkEndChild(txmlN);

  XmlNode* xmlN = new XmlNode(txmlN);
  MChilds.push_back(xmlN);

  return xmlN;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

XmlNode* XmlNode::GetNode(const std::string& parName)
{
  boost::mutex::scoped_lock lock(MXmlMutex);

  foreach(it, MChilds)
    if ((*it)->GetName() == parName)
      return *it;
  return NULL;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void XmlNode::GetNodes(const std::string& parName, std::vector<XmlNode*>& parVec)
{
  boost::mutex::scoped_lock lock(MXmlMutex);

  foreach(it, MChilds)
  {
    if ((*it)->GetName() == parName)
      parVec.push_back(*it);
  }
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

bool XmlNode::DeleteNode(const std::string& parName)
{
  boost::mutex::scoped_lock lock(MXmlMutex);

  foreach(it, MChilds)
  {
    if ((*it)->GetName() == parName)
    {
      MRoot->RemoveChild((*it)->MRoot);
      (*it)->MRoot = NULL;
      delete *it;
      MChilds.erase(it);
      return true;
    }
  }

  return false;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

bool XmlNode::DeleteNodes(const std::string& parName)
{
  boost::mutex::scoped_lock lock(MXmlMutex);
  bool deleted = false;

  foreach(it, MChilds)
  {
    if ((*it)->GetName() == parName)
    {
      deleted = true;
      MRoot->RemoveChild((*it)->MRoot);
      (*it)->MRoot = NULL;
      delete *it;
      MChilds.erase(it);
      it = MChilds.begin();
    }
  }

  return deleted;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void XmlNode::FillTree()
{
  TiXmlNode* xmlN = MRoot->FirstChild();

  for (; xmlN != NULL; xmlN = xmlN->NextSiblingElement())
    if (xmlN->Type() == TiXmlNode::ELEMENT)
      MChilds.push_back(new XmlNode(xmlN));

  foreach(it, MChilds)
    (*it)->FillTree();
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
