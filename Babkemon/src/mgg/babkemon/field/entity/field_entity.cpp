// entity.cpp
#include "field/entity/field_entity.h"

#include "utility\ivector2.h"
#include "field\component\component.h"
#include "field\component\placeable.h"

#include "field\field.h"

namespace mgg {

namespace babkemon {

namespace field {

int Entity::next_entity_id_ = 0;

Entity::Entity(EntityType type, Player* const player) :
id_(Entity::next_entity_id_++),
player_(player),
type_(type),
placeable_(this) {
}

void Entity::Init() {
  for (auto component : components_)
    component.second->Initialize();
}

Field* const Entity::field() {
  return field_;
}

const IVector2& Entity::position() const {
  return placeable_.position();
}

int Entity::id() const {
  return id_;
}

EntityType Entity::type() const {
  return type_;
}

Player* const Entity::player() {
  return player_;
}

}

}

}