////////////////////////////////////////////////////////////////////////////////
// Filename  : animated_material.hh
// Authors   : Creteur Clement
// Last edit : 30/04/10 - 20h06
// Comment   :
////////////////////////////////////////////////////////////////////////////////
#ifndef MATERIAL_DEF_ANIMATED_HH
#define MATERIAL_DEF_ANIMATED_HH

#include "../../useful/all.hh"
#include "../material_type_descriptor.hh"
#include "multi.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class Timer;

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class AnimatedMaterial : public MultiMaterial
{
  public:
    AnimatedMaterial(const std::string& parFilename,
                     unsigned parFrameCount,
                     float parFrameTime,
                     const Timer* parTimer);
    ~AnimatedMaterial();

    inline void SetFrame(unsigned parIth, unsigned parMat) {MChilds[parIth] = parMat;}

  private:

    void PreRender();
    void PostRender();

  private:
    float        MFrameTime;
    float        MLastTime;
    unsigned     MCur;
    const Timer* MTimer;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class AnimatedMaterialDescriptor : public MaterialTypeDescriptor
{
  public:
    AnimatedMaterialDescriptor();
    ~AnimatedMaterialDescriptor();

    virtual AnimatedMaterial* Load(unsigned parCfgFileId) const;

  private:
    Timer* MTimer;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
