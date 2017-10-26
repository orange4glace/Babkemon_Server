// entity.cpp
#include "field/entity/field_entity.h"

namespace mgg {

namespace babkemon {

namespace field {

int Entity::next_entity_id_ = 0;

Entity::Entity() :
id_(Entity::next_entity_id_++) {
}

int Entity::id() const {
  return id_;
}

}

}

}