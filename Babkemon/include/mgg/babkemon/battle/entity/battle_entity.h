// battle_field.h
#ifndef MGG_BABKEMON_BATTLE_ENTITY_ENTITY_H_
#define MGG_BABKEMON_BATTLE_ENTITY_ENTITY_H_

#include "..\..\common\babkemon_type.h"

namespace mgg {

namespace babkemon {

namespace battle {

class Entity {

  static int next_entity_id_;

  int id_;
  BabkemonType type_;
  int hp_;
  int cooldown_;

public:
  Entity(BabkemonType type);

  void UpdateCooldown(int dt);
  void EndTurn();
  
  BabkemonType type() const;
  int hp() const;
  void set_hp(int val);

  int id() const;

};

}

}

}

#endif