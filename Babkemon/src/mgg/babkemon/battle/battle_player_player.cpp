// battle_player_player.cpp
#include "battle\battle_player_player.h"

namespace mgg {

namespace babkemon {

namespace battle {

BattlePlayerPlayer::BattlePlayerPlayer(Battle* const battle, Player* const player) :
  BattlePlayer(battle, BattlePlayerType::PLAYER),
  player_(player) {

}

Player* const BattlePlayerPlayer::player() {
  return player_;
}

PlayerID BattlePlayerPlayer::id() const {
  return player_->id();
}

}

}

}