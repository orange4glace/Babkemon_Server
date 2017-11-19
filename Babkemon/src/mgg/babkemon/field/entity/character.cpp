// character.cpp
#include "field/entity/character.h"

#include "battle\battle_manager.h"

#include "logger\logger.h"

#include <iostream>

namespace mgg {

namespace babkemon {

namespace field {

namespace entity {

Character::Character(Player* const player) :
  Entity(EntityType::CHARACTER, player),
  movable_(this) {
}

void Character::Move(int dir) {
  if (player_->state() != PlayerState::FIELD) return;
  L_DEBUG << "[Character " << id() << "] Move " << dir;
  game_time now = Time::current_time();
  auto diff = now - last_moved_time_;
  if (diff > 30) {
    if (diff > 90) last_moved_time_ = now - 60;
    else last_moved_time_ += 30;
    movable_.Move(dir, field());
  }

  battle::BattleManager::instance()->CreateBattle(player_);
}

}

}

}

}