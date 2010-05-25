////////////////////////////////////////////////////////////////////////////////
// Filename  : multi_material.hh
// Authors   : Creteur Clement
// Last edit : 30/04/10 - 22h13
// Comment   :
////////////////////////////////////////////////////////////////////////////////
#ifndef MATERIAL_DEF_MULTI_HH
#define MATERIAL_DEF_MULTI_HH

#include "../../useful/all.hh"
#include "../material.hh"
#include "../material_type_descriptor.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class MultiMaterial : public Material
{
  public:
    MultiMaterial(const std::string& parFilename, MaterialEnum::Type parType, unsigned parSize);
    ~MultiMaterial();

    inline virtual unsigned GetChildCount()           const {return MSize;}
    inline virtual unsigned GetChild(unsigned parIth) const {LOG_ASSERT(parIth < MSize); return MChilds[parIth];}

  protected:
    unsigned  MSize;
    unsigned* MChilds;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
