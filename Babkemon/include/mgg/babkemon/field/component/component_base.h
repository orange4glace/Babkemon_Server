// component.h
#ifndef MGG_BABKEMON_FIELD_COMPONENT_BASE_H_
#define MGG_BABKEMON_FIELD_COMPONENT_BASE_H_

namespace mgg {

namespace babkemon {

namespace field {

template<class Derived>
class ComponentBase : public Component {

public:
  inline int get_type() const {
    return Derived::type();
  }

};

}

}

}

#endif