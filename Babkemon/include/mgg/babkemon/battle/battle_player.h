// battle_player.h
#ifndef MGG_BABKEMON_BATTLE_BATTLE_PLAYER_H_
#define MGG_BABKEMON_BATTLE_BATTLE_PLAYER_H_

#include "../player.h"

#include "entity\battle_entity.h"

#include <vector>

namespace mgg {

namespace babkemon {

namespace battle {

class Battle;

class BattlePlayer {

  Battle* battle_;

public:
  BattlePlayer(Battle* const battle);

  virtual PlayerID id() const = 0;

  void SpawnBabkemon(Entity* const entity);

};

}

}

}

#endif