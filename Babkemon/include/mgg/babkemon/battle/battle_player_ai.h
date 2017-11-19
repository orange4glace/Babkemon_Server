// battle_player_ai.h
#ifndef MGG_BABKEMON_BATTLE_BATTLE_PLAYER_AI_H_
#define MGG_BABKEMON_BATTLE_BATTLE_PLAYER_AI_H_

#include "battle_player.h"

namespace mgg {

namespace babkemon {

namespace battle {

class BattlePlayerAI : public BattlePlayer {

public:
  BattlePlayerAI(Battle* const battle);

  PlayerID id() const override;
  void Act();

};

}

}

}

#endif