#include "multi.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

MultiMaterial::MultiMaterial(const std::string& parFilename, MaterialEnum::Type parType, unsigned parSize)
  : Material(parFilename, parType),
    MSize(parSize),
    MChilds(new unsigned[parSize])
{
  LOG_ASSERT(MSize != 0);

  for (unsigned i = 0; i < MSize; ++i)
    MChilds[i] = 0;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

MultiMaterial::~MultiMaterial()
{
  delete[] MChilds;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
