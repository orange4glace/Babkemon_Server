// battle.cpp
#include "battle\battle.h"

#include "battle\battle_player_player.h"
#include "battle\battle_player_ai.h"

#include "logger\logger.h"

namespace mgg {

namespace babkemon {

namespace battle {

int Battle::next_battle_id_ = 0;

Battle::Battle() :
id_(Battle::next_battle_id_++) {
  L_DEBUG << "[Battle " << id_ << "] Created.";
  BattlePlayerAI* battle_ai = new BattlePlayerAI(this);
  assert(!battle_players_.count(battle_ai->id()));
  battle_players_[battle_ai->id()] = battle_ai;
}

void Battle::AddBattlePlayer(Player* const player) {
  BattlePlayerPlayer* battle_player = new BattlePlayerPlayer(this, player);
  assert(!battle_players_.count(battle_player->id()));
  battle_players_[battle_player->id()] = battle_player;
  L_DEBUG << "[Battle " << id_ << "] Player " << battle_player->id() << " added.";
}

void Battle::AddEntity(Entity* const entity) {
  entities_.emplace_back(entity);
  L_DEBUG << "[Battle " << id_ << "] Entity " << entity->id() << "(Type = " << entity->type() << ") added.";
}

void Battle::Update(int dt) {
  for (auto entity : entities_) {
    entity->UpdateCooldown(dt);
  }
}

int Battle::id() const {
  return id_;
}

}

}

}