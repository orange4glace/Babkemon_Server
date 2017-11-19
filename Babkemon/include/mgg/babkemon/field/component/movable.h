// movable.h
#ifndef MGG_BABKEMON_FIELD_MOVABLE_H_
#define MGG_BABKEMON_FIELD_MOVABLE_H_

#include "component_base.h"
#include "placeable.h"

namespace mgg {

namespace babkemon {

namespace field {

class Field;

extern int dx[5];
extern int dy[5];

class Movable : public ComponentBase<Movable> {

  Placeable* placeable_;

public:
  inline static int type() {
    return 2;
  }

  Movable(Entity* const entity);

  bool Move(int dir, Field* const field);
  void Initialize() override;

};

}

}

}

#endif