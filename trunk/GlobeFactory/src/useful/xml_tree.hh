////////////////////////////////////////////////////////////////////////////////
// Filename  : xml_tree.hh
// Authors   : Bellanger David
// Last edit :
// Comment   : This class manages I/Os with xml files
////////////////////////////////////////////////////////////////////////////////
#ifndef XML_TREE_HH
#define XML_TREE_HH

#include "xml_node.hh"
#include "manual_ref_counter.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class XmlTree : public XmlNode, public ManualRefCounter
{
  friend class XmlLoader;

  public:
    void Clear();
    bool Load(const std::string& parFilename);
    void Save(const std::string& parFilename);

    inline void Save() {Save(MFilename);}
    inline const std::string& GetFilename() const {return MFilename;}


  private:
    XmlTree();
    ~XmlTree ();

    inline void SetFilename(const std::string& parFile) {MFilename = parFile;}

    std::string MFilename;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
