// battle_manager.cpp
#include "battle\battle_manager.h"

#include "server.h"

namespace mgg {

namespace babkemon {

namespace battle {

BattleManager* BattleManager::instance_ = nullptr;

BattleManager* BattleManager::instance() {
  if (instance_ == nullptr)
    instance_ = new BattleManager();
  return instance_;
}

Battle* const BattleManager::CreateBattle() {
  auto* battle = new Battle();
  assert(!battles_.count(battle->id()));
  battles_[battle->id()] = battle;
  return battle;
}
 
void BattleManager::EnterPlayerBattle(Player* const player, Battle* const battle) {
  assert(!player_battle_map_.count(player));
  player->set_state(PlayerState::BATTLE);
  player_battle_map_[player] = battle;
  battle->AddBattlePlayer(player);
  Server::instance()->ProxyEnterBattle(player, battle->id());
}

Battle* const BattleManager::GetPlayerBattle(Player* const player) {
  return player_battle_map_[player];
}

}

}

}