// character.h
#ifndef MGG_BABKEMON_FIELD_CHARACTER_H_
#define MGG_BABKEMON_FIELD_CHARACTER_H_

#include "field_entity.h"

#include "../component/placeable.h"

namespace mgg {

namespace babkemon {

namespace field {

class Field;

class Character : public Entity {

  Placeable* placeable_;

public:
  Character();

  void Move(int dir);

};

}

}

}

#endif