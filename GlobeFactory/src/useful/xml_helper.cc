#include "xml_helper.hh"

namespace XmlHelper
{
  //----------------------------------------------------------------------------
  //----------------------------------------------------------------------------

  bool ExtractColor(XmlNode* parNode, Color& parColor, const std::string& parName)
  {
    LOG_ASSERT(parNode != NULL);
    XmlNode* node = parNode->GetNode(parName);
    if (node == NULL)
      return false;

    float r, g, b;
    if (!(node->GetAttribute("r", r) &&
          node->GetAttribute("g", g) &&
          node->GetAttribute("b", b)))
      return false;

    float a;
    if (node->GetAttribute("a", a))
      parColor.Set(r, g, b, a);
    else
      parColor.Set(r, g, b);

    return true;
  }

  //----------------------------------------------------------------------------
  //----------------------------------------------------------------------------

  bool ExtractPosition3f(XmlNode* parNode, Vector3&  parPos)
  {
    LOG_ASSERT(parNode != NULL);
    XmlNode* node = parNode->GetNode("position");
    if (node == NULL)
      return false;

    float x, y, z;
    if (!(node->GetAttribute("x", x) &&
          node->GetAttribute("y", y) &&
          node->GetAttribute("z", z)))
      return false;

    parPos.Set(x, y, z);

    return true;
  }

  //----------------------------------------------------------------------------
  //----------------------------------------------------------------------------

  bool ExtractPosition2f(XmlNode* parNode, Vector2f& parPos)
  {
    LOG_ASSERT(parNode != NULL);
    XmlNode* node = parNode->GetNode("position");
    if (node == NULL)
      return false;

    float x, y;
    if (!(node->GetAttribute("x", x) && node->GetAttribute("y", y)))
      return false;

    parPos.Set(x, y);

    return true;
  }

  //----------------------------------------------------------------------------
  //----------------------------------------------------------------------------

  bool ExtractPosition2i(XmlNode* parNode, Vector2i& parPos)
  {
    LOG_ASSERT(parNode != NULL);
    XmlNode* node = parNode->GetNode("position");
    if (node == NULL)
      return false;

    int x, y;
    if (!(node->GetAttribute("x", x) && node->GetAttribute("y", y)))
      return false;

    parPos.Set(x, y);

    return true;
  }

  //----------------------------------------------------------------------------
  //----------------------------------------------------------------------------

  bool ExtractSize3f(XmlNode* parNode, Vector3&  parSz)
  {
    LOG_ASSERT(parNode != NULL);
    XmlNode* node = parNode->GetNode("size");
    if (node == NULL)
      return false;

    float x, y, z;
    if (!(node->GetAttribute("x", x) &&
          node->GetAttribute("y", y) &&
          node->GetAttribute("z", z)))
      return false;

    parSz.Set(x, y, z);

    return true;
  }

  //----------------------------------------------------------------------------
  //----------------------------------------------------------------------------

  bool ExtractSize2f(XmlNode* parNode, Vector2f& parSz)
  {
    LOG_ASSERT(parNode != NULL);
    XmlNode* node = parNode->GetNode("size");
    if (node == NULL)
      return false;

    float x, y;
    if (!(node->GetAttribute("x", x) && node->GetAttribute("y", y)))
      return false;

    parSz.Set(x, y);

    return true;
  }

  //----------------------------------------------------------------------------
  //----------------------------------------------------------------------------

  bool ExtractSize2i(XmlNode* parNode, Vector2i& parSz)
  {
    LOG_ASSERT(parNode != NULL);
    XmlNode* node = parNode->GetNode("size");
    if (node == NULL)
      return false;

    int x, y;
    if (!(node->GetAttribute("x", x) && node->GetAttribute("y", y)))
      return false;

    parSz.Set(x, y);

    return true;
  }

  //----------------------------------------------------------------------------
  //----------------------------------------------------------------------------
}
