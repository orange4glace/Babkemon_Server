// battle_player_player.cpp
#include "battle\battle_player_player.h"

namespace mgg {

namespace babkemon {

namespace battle {

BattlePlayerPlayer::BattlePlayerPlayer(Battle* const battle, Player* const player) :
  BattlePlayer(battle),
  player_(player) {

}

PlayerID BattlePlayerPlayer::id() const {
  return player_->id();
}

}

}

}