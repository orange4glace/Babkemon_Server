// field.h
#ifndef MGG_BABKEMON_FIELD_FIELD_H_
#define MGG_BABKEMON_FIELD_FIELD_H_

/*
#include "..\player.h"
#include "entity\field_entity.h"
*/
#include "field_map.h"

#include "player.h"
#include "..\utility\lockable.h"

#include <map>

namespace mgg {

namespace babkemon {

namespace field {

class Entity;

class Field : public Lockable {

  friend class FieldManager;

  int id_;
  std::map<int, Entity*> entities_;
  std::map<PlayerID, Player*> players_;
  FieldMap field_map_;

  void _SendSnapshot();

  void _AddPlayer(Player* const player);
  void _RemovePlayer(Player* const player);

public:
  Field(int id, int width, int height);

  void AddEntity(Entity* const entity);
  void RemoveEntity(int entity_id);

  int id() const;
  FieldMap* const field_map();

  inline std::map<PlayerID, Player*>::iterator players_begin() {
    return players_.begin();
  }
  inline std::map<PlayerID, Player*>::iterator players_end() {
    return players_.end();
  }

  inline std::map<int, Entity*>::iterator entities_begin() {
    return entities_.begin();
  }
  inline std::map<int, Entity*>::iterator entities_end() {
    return entities_.end();
  }

};

}

}

}

#endif