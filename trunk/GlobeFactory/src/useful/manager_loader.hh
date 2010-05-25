////////////////////////////////////////////////////////////////////////////////
// Filename  : manager_loader.hh
// Authors   : Creteur Clement
// Last edit : 19/01/10 - 23h46
// Comment   :
////////////////////////////////////////////////////////////////////////////////
#ifndef USEFUL_MANAGER_LOADER_HH
#define USEFUL_MANAGER_LOADER_HH

#include <string>
#include <vector>
#include "manual_ref_counter.hh"
#include "macro.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class ManagerLoaderClient : public ManualRefCounter
{
  public:
    ManagerLoaderClient(const std::string& parFilename)
      : MFilename(parFilename)
    {
    }

    virtual ~ManagerLoaderClient()
    {
    }

    inline const std::string& GetFilename() const {return MFilename;}

  private:
    std::string MFilename;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

template<class T, bool OBJECT_ZERO_IS_DEFAULT = false>
class ManagerLoader
{
  public:
    ManagerLoader(unsigned parReservedSize = 16)
      : MObjects(parReservedSize)
    {
      for (unsigned i = 0; i < parReservedSize; ++i)
        MObjects[i] = NULL;
    }

    virtual ~ManagerLoader()
    {
      unsigned size = MObjects.size();
      for (unsigned i = 0; i < size; ++i)
      {
        LOG_ASSERT(MObjects[i] == NULL);
        delete MObjects[i];
      }
    }

    const std::string& GetFilename(unsigned parId) const
    {
      LOG_ASSERT(parId < MObjects.size());
      LOG_ASSERT(MObjects[parId] != NULL);

      return MObjects[parId]->GetFilename();
    }

    virtual unsigned Load(const std::string& parFilename)
    {
      unsigned size = MObjects.size();
      for (unsigned i = 0; i < size; ++i)
      {
        T* obj = MObjects[i];
        if (obj != NULL && parFilename == obj->GetFilename())
        {
          MObjects[i]->IncRefCount();
          return i;
        }
      }

      T* newObj = NewObject(parFilename);
      if (newObj == NULL)
      {
        if (OBJECT_ZERO_IS_DEFAULT)
          LOG_ERROR("Mng Loader", "Return Default object (id = 0) for " + parFilename);
        else
          LOG_ERROR("Mng Loader", "No Default object, but return Id = 0 because of the last error on " + parFilename);

        return 0;
      }

      for (unsigned i = 0; i < size; ++i)
        if (NULL == MObjects[i])
        {
          MObjects[i] = newObj;
          return i;
        }

      MObjects.push_back(newObj);
      return size;
    }

    virtual void Unload(unsigned parId)
    {
      if (OBJECT_ZERO_IS_DEFAULT)
        if (parId == 0)
          return;

      LOG_ASSERT(parId < MObjects.size());
      LOG_ASSERT(MObjects[parId] != NULL);

      MObjects[parId]->DecRefCount();
      if (MObjects[parId]->GetRefCount() == 0)
      {
        delete MObjects[parId];
        MObjects[parId] = NULL;
      }
    }

  protected:
    virtual T* NewObject(const std::string& parFilename) const = 0;

    std::vector<T*> MObjects;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
