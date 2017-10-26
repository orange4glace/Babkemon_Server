// battle_player_ai.cpp
#include "battle\battle_player_ai.h"

#include "battle\entity\entity_factory.h"

namespace mgg {

namespace babkemon {

namespace battle {

BattlePlayerAI::BattlePlayerAI(Battle* const battle) :
  BattlePlayer(battle) {
  BabkemonData slime_data;
  slime_data.type = BabkemonType::SLIME;
  slime_data.hp = 10;
  auto slime = entity::EntityFactory::CreateEntity(slime_data);
  entities_.emplace_back(slime);
  SpawnBabkemon(slime);
}

PlayerID BattlePlayerAI::id() const {
  return 255;
}

}

}

}