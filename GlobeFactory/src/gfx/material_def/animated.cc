#include "animated.hh"
#include "../material_mng.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

AnimatedMaterial::AnimatedMaterial(const std::string& parFilename,
                                   unsigned parFrameCount,
                                   float parFrameTime,
                                   const Timer* parTimer)
  : MultiMaterial(parFilename, MaterialEnum::ANIMATED, parFrameCount),
    MFrameTime(parFrameTime),
    MLastTime(0.0f),
    MCur(0),
    MTimer(parTimer)
{
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

AnimatedMaterial::~AnimatedMaterial()
{
  for (unsigned i = 0; i < MSize; ++i)
    MaterialMng::get()->UnloadMaterial(MChilds[i]);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void AnimatedMaterial::PreRender()
{
  if (MTimer->ElapsSince(MLastTime) >= MFrameTime)
  {
    MCur = (MCur + 1) % MSize;
    MLastTime = MTimer->GetTimeFromCreation();
  }

  MaterialMng& matMng = *MaterialMng::get();
  matMng.PreRenderForMaterialType(matMng.GetMaterialType(MChilds[MCur]));
  matMng.PreRenderForMaterial(MChilds[MCur]);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void AnimatedMaterial::PostRender()
{
  MaterialMng& matMng = *MaterialMng::get();
  matMng.PostRenderForMaterial(MChilds[MCur]);
  matMng.PostRenderForMaterialType(matMng.GetMaterialType(MChilds[MCur]));
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

AnimatedMaterialDescriptor::AnimatedMaterialDescriptor()
  : MTimer(Clock::get()->CreateTimer())
{
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

AnimatedMaterialDescriptor::~AnimatedMaterialDescriptor()
{
  Clock::get()->DeleteTimer(MTimer);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

AnimatedMaterial* AnimatedMaterialDescriptor::Load(unsigned parCfgFileId) const
{
  ConfigMng* cfgMng = ConfigMng::get();

  const int*   frameCount = cfgMng->GetOptionInt(parCfgFileId, "frameCount");
  const float* frameTime  = cfgMng->GetOptionFloat(parCfgFileId, "frameTime");

  if (frameCount == NULL || *frameCount <= 0)
  {
    LOG_ERROR("AnimMaterial", cfgMng->GetFilename(parCfgFileId) + " : bad frameCount variable");
    return NULL;
  }

  if (frameTime == NULL)
  {
    LOG_ERROR("AnimMaterial", cfgMng->GetFilename(parCfgFileId) + " : no frameTime variable");
    return NULL;
  }

  AnimatedMaterial* mat = new AnimatedMaterial(cfgMng->GetFilename(parCfgFileId),
                                               *frameCount, *frameTime, MTimer);

  for (int i = 0; i < *frameCount; ++i)
  {
    const std::string* cur = cfgMng->GetOptionStr(parCfgFileId, misc::ToString(i));
    if (cur == NULL)
    {
      LOG_ERROR("AnimMaterial", cfgMng->GetFilename(parCfgFileId) + " : frame("
                                + misc::ToString(i) + ") badly defined");
      return NULL;
    }
    mat->SetFrame(static_cast<unsigned>(i), MaterialMng::get()->LoadMaterial(*cur));
  }

  return mat;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
