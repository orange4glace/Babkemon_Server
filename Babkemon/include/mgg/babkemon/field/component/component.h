// component.h
#ifndef MGG_BABKEMON_FIELD_COMPONENT_H_
#define MGG_BABKEMON_FIELD_COMPONENT_H_

namespace mgg {

namespace babkemon {

namespace field {

class Entity;

class Component {

protected:
  Entity* entity_;

  Component(Entity* const entity);

public:
  virtual inline int get_type() const = 0;
  virtual void Initialize() {}

};

}

}

}

#endif