////////////////////////////////////////////////////////////////////////////////
// Filename  : fps_counter.hh
// Authors   : Creteur Clement
// Last edit : 02/02/10 - 20h46
// Comment   :
////////////////////////////////////////////////////////////////////////////////
#ifndef USEFUL_XML_HELPER
#define USEFUL_XML_HELPER

#include "color.hh"
#include "xml_node.hh"
#include "vector.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

namespace XmlHelper
{
  bool ExtractColor(XmlNode* parNode, Color& parColor, const std::string& = "color");

  bool ExtractPosition3f(XmlNode* parNode, Vector3&  parPos);
  bool ExtractPosition2f(XmlNode* parNode, Vector2f& parPos);
  bool ExtractPosition2i(XmlNode* parNode, Vector2i& parPos);

  bool ExtractSize3f(XmlNode* parNode, Vector3&  parSz);
  bool ExtractSize2f(XmlNode* parNode, Vector2f& parSz);
  bool ExtractSize2i(XmlNode* parNode, Vector2i& parSz);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
