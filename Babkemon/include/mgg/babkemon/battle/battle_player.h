// battle_player.h
#ifndef MGG_BABKEMON_BATTLE_BATTLE_PLAYER_H_
#define MGG_BABKEMON_BATTLE_BATTLE_PLAYER_H_

#include "../player.h"

#include "battle_entity.h"

#include <vector>

namespace mgg {

namespace babkemon {

namespace battle {

class Battle;

#define AI_PLAYER_ID (PlayerID)2147483647

enum class BattlePlayerType {
  PLAYER, AI
};

class BattlePlayer {
   
protected:
  Battle* battle_;
  BattlePlayerType type_;

  std::vector<Entity*> entities_;

public:
  BattlePlayer(Battle* const battle, BattlePlayerType type);

  void SpawnBabkemon(Babkemon* const babkemon);

  Entity* const entity(int id);

  virtual PlayerID id() const = 0;
  BattlePlayerType type() const;

};

}

}

}

#endif