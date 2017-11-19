// placeable.h
#ifndef MGG_BABKEMON_FIELD_PLACEABLE_H_
#define MGG_BABKEMON_FIELD_PLACEABLE_H_

#include "component_base.h"

#include "../../utility/ivector2.h"

namespace mgg {

namespace babkemon {

namespace field {

class Placeable : public ComponentBase<Placeable> {

  IVector2 position_;

public:
  inline static int type() {
    return 1;
  }

  Placeable(Entity* const entity);

  const IVector2& position() const;
  void set_position(const IVector2& val);

};

}

}

}

#endif