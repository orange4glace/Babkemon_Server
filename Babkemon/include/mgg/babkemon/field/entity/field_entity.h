// field.h
#ifndef MGG_BABKEMON_FIELD_ENTITY_H_
#define MGG_BABKEMON_FIELD_ENTITY_H_

#include "../component/component.h"
#include "..\component\placeable.h"

#include "field_entity_type.h"
#include "player.h"

#include <map>
#include <iostream>
#include <cassert>

namespace mgg {

namespace babkemon {

namespace field {

class Field;

class Entity {

  friend class Field;

  static int next_entity_id_;

  std::map<int, Component*> components_;

protected:
  int id_;
  EntityType type_;

  Field* field_;
  Placeable placeable_;

  Player* player_;

public:
  Entity(EntityType type, Player* const player);

  template<class ComponentType>
  ComponentType* AddComponent(ComponentType* component) {
    assert(!components_.count(ComponentType::type()));
    components_[ComponentType::type()] = static_cast<Component*>(component);
    return component;
  }

  template<class ComponentType>
  ComponentType* GetComponent() {
    assert(components_.count(ComponentType::type()));
    return static_cast<ComponentType*>(components_.at(ComponentType::type()));
  }

  void Init();

  const IVector2& position() const;

  Field* const field();
  EntityType type() const;
  int id() const;
  Player* const player();

};

}

}

}

#endif