#include "parent_entity.hh"
#include "../useful/macro.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

EntParent::EntParent(EntityEnum parType, Entity* parParent, const std::string& parName)
  : Entity(parType, parParent, parName)
{
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

EntParent::~EntParent()
{
  foreach(it, FChilds)
    delete *it;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

Entity* EntParent::GetOneEntityByType(EntityEnum parType)
{
  Entity* res = Entity::GetOneEntityByType(parType);
  if (res != NULL)
    return res;

  foreach(it, FChilds)
  {
    Entity* res = (*it)->GetOneEntityByType(parType);
    if (res != NULL)
      return res;
  }

  return NULL;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

Entity* EntParent::GetOneEntityByName(const std::string& parName)
{
  Entity* res = Entity::GetOneEntityByName(parName);
  if (res != NULL)
    return res;

  foreach(it, FChilds)
  {
    Entity* res = (*it)->GetOneEntityByName(parName);
    if (res != NULL)
      return res;
  }

  return NULL;

}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void EntParent::GetAllEntitiesByType(EntityEnum parType, std::vector<Entity*>& parAll)
{
  Entity::GetAllEntitiesByType(parType, parAll);

  foreach(it, FChilds)
    (*it)->GetAllEntitiesByType(parType, parAll);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void EntParent::GetAllEntitiesByName(const std::string& parName, std::vector<Entity*>& parAll)
{
  Entity::GetAllEntitiesByName(parName, parAll);

  foreach(it, FChilds)
    (*it)->GetAllEntitiesByName(parName, parAll);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

Entity* EntParent::TestFirstCollision(Entity* parMover)
{
  foreach(it, FChilds)
  {
    Entity* entity = (*it)->TestFirstCollision(parMover);
    if (entity != NULL)
      return entity;
  }

  return NULL;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void EntParent::TestAllCollisions(Entity* parMover, std::vector<Entity*>& parEntities)
{
  foreach(it, FChilds)
    (*it)->TestAllCollisions(parMover, parEntities);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void EntParent::Update()
{
  foreach(it, FChilds)
    (*it)->Update();
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

void EntParent::PreDraw()
{
  foreach(it, FChilds)
    (*it)->PreDraw();
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

bool EntParent::InsertInside(Entity* parEntity)
{
  foreach(it, FChilds)
    if ((*it)->InsertInside(parEntity))
      return true;

  return false;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

