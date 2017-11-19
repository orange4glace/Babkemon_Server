// battle_player_ai.cpp
#include "battle\battle_player_ai.h"

#include "battle\battle.h"

#include "pidl\battle_pidl.h"

namespace mgg {

namespace babkemon {

namespace battle {

BattlePlayerAI::BattlePlayerAI(Battle* const battle) :
  BattlePlayer(battle, BattlePlayerType::AI) {
}

PlayerID BattlePlayerAI::id() const {
  return AI_PLAYER_ID;
}

void BattlePlayerAI::Act() {
  /*
  L_DEBUG << "[BattlePlayerAI] Act " << this << " " << entities_.size();
  for (auto entity : entities_) {
    L_DEBUG << "AI act " << entity->id();
    Entity* target_entity = nullptr;
    auto battle = entity->battle();
    for (auto it = battle->entities_begin(); it != battle->entities_end(); it++) {
      auto entity = *it;
      if (entity->battle_player()->id() != id())
        target_entity = entity;
    }
    L_DEBUG << "Target = " << target_entity;
    if (target_entity == nullptr) continue;
    auto skill = new skill::BodySlam(entity, target_entity->id());
    entity->set_reserved_skill(skill);
  }
  */
}

}

}

}