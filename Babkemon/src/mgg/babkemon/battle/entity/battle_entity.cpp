// entity.cpp
#include "battle/entity/battle_entity.h"

namespace mgg {

namespace babkemon {

namespace battle {

int Entity::next_entity_id_ = 0;

Entity::Entity(BabkemonType type) :
id_(Entity::next_entity_id_++),
type_(type) {

}

void Entity::UpdateCooldown(int dt) {
  cooldown_ -= dt;
  if (cooldown_ < 0) cooldown_ = 0;
}

void Entity::set_hp(int hp) {
  hp_ = hp;
}

int Entity::id() const {
  return id_;
}

BabkemonType Entity::type() const {
  return type_;
}

}

}

}