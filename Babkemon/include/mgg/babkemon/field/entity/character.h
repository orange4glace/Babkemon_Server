// character.h
#ifndef MGG_BABKEMON_FIELD_CHARACTER_H_
#define MGG_BABKEMON_FIELD_CHARACTER_H_

#include "field_entity.h"

#include "..\component\movable.h"

#include "..\..\utility\time.h"

namespace mgg {

namespace babkemon {

namespace field {

namespace entity {

class Character : public Entity {

  game_time last_moved_time_;

  Movable movable_;

public:
  Character(Player* const player);

  void Move(int dir);

};

}

}

}

}

#endif