// battle_player_player.h
#ifndef MGG_BABKEMON_BATTLE_BATTLE_PLAYER_PLAYER_H_
#define MGG_BABKEMON_BATTLE_BATTLE_PLAYER_PLAYER_H_

#include "battle_player.h"
#include "..\player.h"

namespace mgg {

namespace babkemon {

namespace battle {

class BattlePlayerPlayer : public BattlePlayer {

  Player* player_;

public:
  BattlePlayerPlayer(Battle* const battle, Player* const player);

  Player* const player();
  PlayerID id() const override;

};

}

}

}

#endif