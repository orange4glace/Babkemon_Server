// battle_pidl.cpp
#include "pidl\battle_pidl.h"

#include "..\..\..\pidl\battle_s2c_common.cpp"
#include "..\..\..\pidl\battle_s2c_proxy.cpp"
#include "..\..\..\pidl\battle_c2s_common.cpp"
#include "..\..\..\pidl\battle_c2s_stub.cpp"

#include "server.h"
#include "inventory.h"
#include "battle\battle_manager.h"
#include "battle\battle_player_player.h"

#include "logger\logger.h"

namespace mgg {

namespace babkemon {

namespace pidl {

void BattlePIDL::_SetStubs() {
  stub_.SpawnEntity_Function = [&]PARAM_battle_c2s_SpawnEntity{
    return StubSpawnEntity(remote, rmiContext, entity_id);
  };
  stub_.SkillCommand_Function = [&]PARAM_battle_c2s_SkillCommand{
    return StubSkillCommand(remote, rmiContext, entity_id, packet);
  };
}

void BattlePIDL::ProxyBattleInfo(
  ::mgg::babkemon::battle::Battle* const battle,
  ::mgg::babkemon::battle::BattleInfoPacket& const packet) {
  for (auto it = battle->battle_players_begin(); it != battle->battle_players_end(); it++) {
    auto battle_player = it->second;
    if (battle_player->type() == ::mgg::babkemon::battle::BattlePlayerType::PLAYER) {
      auto bpp = static_cast<::mgg::babkemon::battle::BattlePlayerPlayer*>(battle_player);
      proxy_.BattleInfo(bpp->player()->host_id(), Proud::RmiContext::ReliableSend, packet);
    }
  }
}

void BattlePIDL::ProxySetCooldown(
  ::mgg::babkemon::battle::Battle* const battle,
  ::mgg::babkemon::battle::Entity* const entity,
  int cooldown) {
  for (auto it = battle->battle_players_begin(); it != battle->battle_players_end(); it++) {
    auto battle_player = it->second;
    if (battle_player->type() == ::mgg::babkemon::battle::BattlePlayerType::PLAYER) {
      auto bpp = static_cast<::mgg::babkemon::battle::BattlePlayerPlayer*>(battle_player);
      proxy_.SetCooldown(bpp->player()->host_id(), Proud::RmiContext::ReliableSend, entity->babkemon()->id(), cooldown);
    }
  }
}

void BattlePIDL::ProxySpawnEntity(
  ::mgg::babkemon::battle::Battle* const battle,
  PlayerID battle_player_id,
  const ::mgg::babkemon::battle::EntitySpawnPacket& packet) {
  for (auto it = battle->battle_players_begin(); it != battle->battle_players_end(); it++) {
    auto battle_player = it->second;
    if (battle_player->type() == ::mgg::babkemon::battle::BattlePlayerType::PLAYER) {
      auto bpp = static_cast<::mgg::babkemon::battle::BattlePlayerPlayer*>(battle_player);
      proxy_.SpawnEntity(bpp->player()->host_id(), Proud::RmiContext::ReliableSend, battle_player_id, packet);
    }
  }
}

void BattlePIDL::ProxyCastSkill(
  ::mgg::babkemon::battle::Battle* const battle,
  ::mgg::babkemon::battle::Entity* const entity,
  ::mgg::babkemon::packet::SkillBattleCastPacket& const packet) {
  for (auto it = battle->battle_players_begin(); it != battle->battle_players_end(); it++) {
    auto battle_player = it->second;
    if (battle_player->type() == ::mgg::babkemon::battle::BattlePlayerType::PLAYER) {
      auto bpp = static_cast<::mgg::babkemon::battle::BattlePlayerPlayer*>(battle_player);
      proxy_.CastSkill(bpp->player()->host_id(), Proud::RmiContext::ReliableSend, entity->babkemon()->id(), packet);
    }
  }
}

void BattlePIDL::ProxyBattleEnd(
  ::mgg::babkemon::Player* const player) {
  proxy_.BattleEnd(player->host_id(), Proud::RmiContext::ReliableSend);
}

void BattlePIDL::ProxyBattleWin(
  ::mgg::babkemon::Player* const player) {
  proxy_.BattleWin(player->host_id(), Proud::RmiContext::ReliableSend);
}

void BattlePIDL::ProxyBattleLose(
  ::mgg::babkemon::Player* const player) {
  proxy_.BattleLose(player->host_id(), Proud::RmiContext::ReliableSend);
}

void BattlePIDL::ProxyTurn(
  ::mgg::babkemon::battle::Battle* const battle) {
  for (auto it = battle->battle_players_begin(); it != battle->battle_players_end(); it++) {
    auto battle_player = it->second;
    if (battle_player->type() == ::mgg::babkemon::battle::BattlePlayerType::PLAYER) {
      auto bpp = static_cast<::mgg::babkemon::battle::BattlePlayerPlayer*>(battle_player);
      proxy_.Turn(bpp->player()->host_id(), Proud::RmiContext::ReliableSend);
    }
  }
}

bool BattlePIDL::StubSpawnEntity(::Proud::HostID remote, ::Proud::RmiContext& rmiContext, const int& entity_id) {
  L_DEBUG << "[BattlePIDL Stub] Spawn Entity " << entity_id;

  // Get Player
  auto locked_player = ::mgg::babkemon::Server::instance()->GetLockedPlayer(remote);
  auto player = locked_player.first;
  if (player == nullptr) return true;
  // Get Battle
  auto locked_battle = ::mgg::babkemon::battle::BattleManager::instance()->GetLockedBattleByPlayer(player);
  auto battle = locked_battle.first;
  if (battle == nullptr) return true;
  // Get BattlePlayer
  auto battle_player = battle->battle_player(player->id());
  if (battle_player == nullptr) return true;
  // Get Babkemon
  auto babkemon = player->GetBabkemon(entity_id);
  if (babkemon == nullptr) return true;

  battle_player->SpawnBabkemon(babkemon);
  return true;
}

bool BattlePIDL::StubSkillCommand(::Proud::HostID remote, ::Proud::RmiContext& rmiContext,
  const int& entity_id,
  const ::mgg::babkemon::battle::SkillCommandPacket& packet) {
  L_DEBUG << "[BattlePIDL Stub] SkillCommand " << entity_id;
  auto locked_player = ::mgg::babkemon::Server::instance()->GetLockedPlayer(remote);
  auto player = locked_player.first;
  if (player == nullptr) return true;
  auto locked_battle = ::mgg::babkemon::battle::BattleManager::instance()->GetLockedBattleByPlayer(player);
  auto battle = locked_battle.first;
  auto battle_player = battle->battle_player(player->id());
  auto entity = battle_player->entity(entity_id);
  if (entity == nullptr) return true;
  
  entity->set_command(packet.raw);
  if (battle->CheckStep()) battle->DoStep();
  
  return true;
}

bool BattlePIDL::StubItemCommand(::Proud::HostID remote, ::Proud::RmiContext& rmiContext,
  const int& entity_id,
  const ::mgg::babkemon::battle::ItemCommandPacket& packet) {
  L_DEBUG << "[BattlePIDL Stub] ItemCommand " << entity_id;
  auto& raw = *packet.raw;
  auto locked_player = ::mgg::babkemon::Server::instance()->GetLockedPlayer(remote);
  auto player = locked_player.first;
  if (player == nullptr) return true;
  auto item = player->inventory()->GetItem(raw.item_id);
  if (item == nullptr) return true;
  auto locked_battle = ::mgg::babkemon::battle::BattleManager::instance()->GetLockedBattleByPlayer(player);
  auto battle = locked_battle.first;
  auto battle_player = battle->battle_player(player->id());
  auto entity = battle_player->entity(entity_id);
  if (entity == nullptr) return true;
}

}

}

}