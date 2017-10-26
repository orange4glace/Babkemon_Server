// battle_player.cpp
#include "battle\battle_player.h"

#include "battle\battle.h"

namespace mgg {

namespace babkemon {

namespace battle {

BattlePlayer::BattlePlayer(Battle* const battle) :
  battle_(battle) {

}

void BattlePlayer::SpawnBabkemon(Entity* const entity) {
  battle_->AddEntity(entity);
}

}

}

}