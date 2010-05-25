////////////////////////////////////////////////////////////////////////////////
// Filename  : xml_node.hh
// Authors   : Bellanger David && Clement Creteur
// Last edit :
// Comment   : This class represents a node in the xml tree
////////////////////////////////////////////////////////////////////////////////
#ifndef XML_NODE_HH
#define XML_NODE_HH

#include <string>
#include <iostream>
#include <list>
#include <map>
#include <vector>
#include "tinyxml/tinyxml.h"
#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/bind.hpp>
#include "log.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class XmlTree;

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class XmlNode
{
  friend class XmlTree;

  public:
    XmlNode(const std::string& parName = "", const std::string& parText = "");
    virtual ~XmlNode();

    void SetName(const std::string& parName);
    const std::string& GetName();

    void SetText(const std::string& parName);
    const std::string& GetText();

    XmlNode* AddNode(const std::string&  parName);
    XmlNode* GetNode(const std::string&  parName);
    void     GetNodes(const std::string& parName, std::vector<XmlNode*>&);

    bool DeleteNode(const std::string&  parName);
    bool DeleteNodes(const std::string& parName);

    template<typename T>
    void SetAttribute(const std::string& parName, const T& parValue);
    template<typename T>
    bool GetAttribute(const std::string& parName, T& parValue);

  protected:
    TiXmlNode*            MRoot;
    std::vector<XmlNode*> MChilds;
    boost::mutex          MXmlMutex;

    void FillTree();

  private:
    XmlNode(const XmlNode&);
    XmlNode(TiXmlNode* parXmlNode);
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

template<typename T>
void XmlNode::SetAttribute(const std::string& parName, const T& parValue)
{
  boost::mutex::scoped_lock lock(MXmlMutex);
  MRoot->ToElement()->SetAttribute(parName, parValue);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

template<typename T>
bool XmlNode::GetAttribute(const std::string& parName, T& parValue)
{
  boost::mutex::scoped_lock lock(MXmlMutex);
  return (MRoot->ToElement()->QueryValueAttribute(parName, &parValue) == TIXML_SUCCESS);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
