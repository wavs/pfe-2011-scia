////////////////////////////////////////////////////////////////////////////////
// Filename  : parent_entity.hh
// Authors   : Creteur Clement
// Last edit : 08/11/09 - 20h00
// Comment   :
////////////////////////////////////////////////////////////////////////////////
#ifndef GAME_PARENT_ENTITY_HH
#define GAME_PARENT_ENTITY_HH

#include <string>
#include <list>
#include "entity.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class EntParent : public Entity
{
  public:
    EntParent(EntityEnum parType, Entity* parParent, const std::string& parName);
    ~EntParent();

  Entity* GetOneEntityByType(EntityEnum parType);
  Entity* GetOneEntityByName(const std::string& parName);

  void GetAllEntitiesByType(EntityEnum parType, std::vector<Entity*>& parAll);
  void GetAllEntitiesByName(const std::string& parName, std::vector<Entity*>& parAll);

  Entity* TestFirstCollision(Entity* parMover);

  void TestAllCollisions(Entity* parMover, std::vector<Entity*>& parEntities);
  void Update();
  void PreDraw();
  bool InsertInside(Entity* parEntity);

  private:
    std::list<Entity*> FChilds;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
