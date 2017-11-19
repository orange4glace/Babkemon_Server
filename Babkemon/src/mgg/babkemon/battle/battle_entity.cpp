// entity.cpp
#include "battle\battle_entity.h"

#include "battle\battle.h"
#include "battle\battle_player.h"
#include "battle\battle_player_ai.h"
#include "pidl\battle_pidl.h"

#include "logger\logger.h"

namespace mgg {

namespace babkemon {

namespace battle {

Entity::Entity(Battle* const battle, BattlePlayer* const battle_player, Babkemon* const babkemon) :
battle_(battle),
battle_player_(battle_player),
babkemon_(babkemon),
command_(nullptr) {
}

Entity::~Entity() {
  L_DEBUG << "[Entity " << babkemon_->id() << "] Destroied.";
}

void Entity::Start() {
}

void Entity::ExecuteCommand() {
  if (command_ == nullptr) return;
}

CommandPacket* const Entity::command() {
  return command_;
}

void Entity::set_command(CommandPacket* const command) {
  command_ = command;
}

Babkemon* const Entity::babkemon() {
  return babkemon_;
}

int Entity::hp() const {
  return babkemon_->hp();
}

void Entity::set_hp(int hp) {
  babkemon_->set_hp(hp);
}

BattlePlayer* Entity::battle_player() {
  return battle_player_;
}

Battle* const Entity::battle() {
  return battle_;
}

}

}

}