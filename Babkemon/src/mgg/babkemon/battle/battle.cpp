// battle.cpp
#include "battle\battle.h"

#include "battle\battle_entity.h"
#include "battle\battle_player_player.h"
#include "battle\battle_player_ai.h"
#include "battle\packet\battle_info_packet.h"

#include "battle\battle_manager.h"

#include "pidl\common_pidl.h"
#include "pidl\battle_pidl.h"

#include "logger\logger.h"

namespace mgg {

namespace babkemon {

namespace battle {

int Battle::next_battle_id_ = 0;

Battle::Battle() :
id_(Battle::next_battle_id_++) {
  L_DEBUG << "[Battle " << id_ << "] Created.";
}

Battle::~Battle() {
  L_DEBUG << "[Battle " << id_ << "] Destroied";
}

void Battle::destroy() {
  L_DEBUG << "[Battle " << id_ << "] Terminate..";
  BattleManager::instance()->_TerminateBattle(id_);
  entities_.clear();
  L_DEBUG << "[Battle " << id_ << "] Unleash all entities..";
}

void Battle::Start() {
  BattleInfoPacket info_packet;
  info_packet.type = BattleType::PVE;
  for (auto battle_player : battle_players_) {
    L_DEBUG << battle_player.second->id();
    info_packet.battle_players.emplace_back(battle_player.second);
  }
  pidl::BattlePIDL::instance().ProxyBattleInfo(this, info_packet);
}

bool Battle::CheckStep() {
  for (auto entity : entities_) {
    if (entity->battle_player()->id() == AI_PLAYER_ID) {
      continue;
    }
    auto command = entity->command();
    if (command == nullptr) return false;
  }
  return true;
}

void Battle::DoStep() {
  L_DEBUG << "[Battle] " << id_ << " Step";
  for (auto pp : battle_players_) {
    auto p = pp.second;
    if (p->id() != AI_PLAYER_ID) continue;
    auto bp = static_cast<BattlePlayerAI*>(p);
    bp->Act();
  }
  for (auto entity : entities_) {
    auto skill = entity->command();
    if (skill == nullptr) continue;
    L_DEBUG << entity->id() << " casts skill";
    auto& cpacket = skill->Cast();
    pidl::BattlePIDL::instance().ProxyCastSkill(this, entity, cpacket);
    entity->clear_reserved_skill();
  }

  // Check battle done
  int ai_hp_sum = 0;
  int player_hp_sum = 0;
  for (auto entity : entities_) {
    if (entity->battle_player()->type() == BattlePlayerType::AI) ai_hp_sum += entity->hp();
    else player_hp_sum += entity->hp();
  }
  
  if (ai_hp_sum == 0) {
    for (auto bp_kv : battle_players_) {
      auto bp = bp_kv.second;
      if (bp->type() == BattlePlayerType::PLAYER) {
        auto player = static_cast<BattlePlayerPlayer*>(bp)->player();

        pidl::BattlePIDL::instance().ProxyBattleEnd(player);
        auto booty = item::ItemFactory::CreateItem(item::ItemType::SMALL_POSION);
        player->inventory()->AddItem(booty);
        pidl::BattlePIDL::instance().ProxyBattleWin(player);
      }
    }
  }
  pidl::BattlePIDL::instance().ProxyTurn(this);
  */
}

void Battle::AddBattlePlayer(Player* const player) {
  auto battle_player = new BattlePlayerPlayer(this, player);
  assert(!battle_players_.count(battle_player->id()));
  //assert(player->state() != PlayerState::BATTLE);
  player->set_state(PlayerState::BATTLE);
  battle_players_[battle_player->id()] = battle_player;
  pidl::CommonPIDL::instance().ProxyEnterBattle(player, this);
  L_DEBUG << "[Battle " << id_ << "] Player " << battle_player->id() << " added.";
}

BattlePlayerAI* const Battle::AddBattleAI() {
  auto battle_ai = new BattlePlayerAI(this);
  assert(!battle_players_.count(battle_ai->id()));
  battle_players_[battle_ai->id()] = battle_ai;
  return battle_ai;
}

void Battle::AddEntity(Entity* const entity) {
  entities_.emplace_back(entity);
  entity->Start();
  L_DEBUG << "[Battle " << id_ << "] Entity " << entity->babkemon()->id() << "(Type = " << entity->babkemon()->type() << ") added.";
}

Entity* const Battle::GetEntity(EntityID id) {
  for (auto entity : entities_)
    if (entity->babkemon()->id() == id) return entity;
  assert(false);
  return nullptr;
}

int Battle::id() const {
  return id_;
}

BattlePlayer* const Battle::battle_player(PlayerID player_id) {
  if (battle_players_.count(player_id)) return battle_players_[player_id];
  return nullptr;
}

}

}

}