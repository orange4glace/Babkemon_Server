// field.h
#ifndef MGG_BABKEMON_FIELD_ENTITY_H_
#define MGG_BABKEMON_FIELD_ENTITY_H_

#include "../component/component.h"

#include <map>
#include <iostream>
#include <cassert>

namespace mgg {

namespace babkemon {

namespace field {

class Field;

class Entity {

  static int next_entity_id_;

  std::map<int, Component*> components_;

  int id_;

public:
  Entity();

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

  int id() const;

};

}

}

}

#endif