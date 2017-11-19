// battle_player.cpp
#include "battle\battle_player.h"

#include "battle\battle.h"
#include "pidl\battle_pidl.h"

#include "logger\logger.h"

namespace mgg {

namespace babkemon {

namespace battle {

BattlePlayer::BattlePlayer(Battle* const battle, BattlePlayerType type) :
  battle_(battle),
  type_(type) {

}

BattlePlayerType BattlePlayer::type() const {
  return type_;
}

void BattlePlayer::SpawnBabkemon(Babkemon* const babkemon) {
  Entity* entity = new Entity(battle_, this, babkemon);
  entities_.emplace_back(entity);
  battle_->AddEntity(entity);
  ::mgg::babkemon::pidl::BattlePIDL::instance().ProxySpawnEntity(battle_, id(), EntitySpawnPacket(entity));
  L_DEBUG << "[BattlePlayer " << id() << "] Entity spawned. " << entity->babkemon()->id();
}

Entity* const BattlePlayer::entity(int id) {
  for (auto entity : entities_)
    if (entity->babkemon()->id() == id) return entity;
  return nullptr;
}

}

}

}