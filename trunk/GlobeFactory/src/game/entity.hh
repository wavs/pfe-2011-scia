////////////////////////////////////////////////////////////////////////////////
// Filename  : entity.hh
// Authors   : Creteur Clement
// Last edit : 08/11/09 - 20h00
// Comment   :
////////////////////////////////////////////////////////////////////////////////
#ifndef GAME_ENTITY_HH
#define GAME_ENTITY_HH

#include <string>
#include <vector>
#include "../useful/vector.hh"
#include "../useful/color.hh"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

enum EntityEnum
{
  ENT_LIGHT,
  ENT_MODEL,
  ENT_CLUSTER,
  ENT_COUNT
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

class Entity
{
  public:
    virtual ~Entity() {}

    inline virtual EntityEnum GetType() const {return MType;}
    inline virtual const std::string& GetName() const {return MName;}

    inline virtual const Vector3& GetPosition() const {return MPosition;}
    inline virtual void SetPosition(const Vector3& parPosition) {MPosition = parPosition;}

    inline virtual Entity* GetOneEntityByType(EntityEnum parType) {return (MType == parType) ? this : NULL;}
    inline virtual Entity* GetOneEntityByName(const std::string& parName) {return (MName == parName) ? this : NULL;}

    inline virtual void GetAllEntitiesByType(EntityEnum parType, std::vector<Entity*>& parAll)
    { if (MType == parType) parAll.push_back(this); }

    inline virtual void GetAllEntitiesByName(const std::string& parName, std::vector<Entity*>& parAll)
    { if (MName == parName) parAll.push_back(this);    }

    inline virtual void Enable() {}
    inline virtual void Disable() {}
    inline virtual void Toogle() {}
    inline virtual bool IsEnable() const {return false;}

    inline virtual void SetColor(const Color& parColor) {}
    inline virtual const Color& GetColor() const {return BaseColor::BLACK;}

    inline virtual const Vector3& GetAngle() const {return BaseVector3::ZERO;}
    inline virtual void SetAngle(const Vector3& parAngle) {}

    inline virtual const Vector3& GetTargetPosition() const {return BaseVector3::ZERO;}
    inline virtual void SetTargetPosition(const Vector3& parPosition) {}

    inline virtual Entity* GetTargetEntity() const {return NULL;}
    inline virtual void SetTargetEntity(Entity* parEntity) const {}

    inline virtual float GetSpeed() const {return 0.0f;}
    inline virtual void SetSpeed(float parSpeed) {}

    inline virtual float GetVelocity() const {return 0.0f;}
    inline virtual void SetVelocity(float parVelocity) {}

    inline virtual float GetRadius() const {return 0.0f;}
    inline virtual void SetRadius(float parRadius) {}

    inline virtual float GetLife() const {return 0.0f;}
    inline virtual void SetLife(float parLife) {}
    inline virtual void IncreaseLife(float parLife) {}
    inline virtual void DecreaseLife(float parLife) {}

    inline virtual void Start() {}
    inline virtual void Stop() {}

    inline virtual Entity* TestFirstCollision(Entity* parMover) {return NULL;}
    inline virtual void TestAllCollisions(Entity* parMover, std::vector<Entity*>& parEntities) {}

    inline virtual void Shutdown() {}
    inline virtual void Update() {}
    inline virtual void PreDraw() {}

    inline virtual bool InsertInside(Entity* parEntity) {return false;}

  protected:
      Entity(EntityEnum parType, Entity* parParent = NULL, const std::string& parName = "");

  private:
    EntityEnum MType;
    Entity* MParent;
    std::string MName;
    Vector3 MPosition;
};

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

#endif
