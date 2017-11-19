// battle_manager.cpp
#include "battle\battle_manager.h"

#include "battle\battle_player_ai.h"
#include "server.h"

#include "common\babkemon_factory.h"

namespace mgg {

namespace babkemon {

namespace battle {

BattleManager* BattleManager::instance_ = nullptr;

BattleManager* BattleManager::instance() {
  if (instance_ == nullptr)
    instance_ = new BattleManager();
  return instance_;
}

std::pair<Battle* const, std::unique_lock<std::mutex>> BattleManager::CreateBattle(Player* const player) {
  auto lock = unique_lock();
  auto battle = new Battle();

  assert(!battles_.count(battle->id()));
  battles_[battle->id()] = battle;
  battle->AddBattlePlayer(player);

  assert(!player_battle_map_.count(player->id()));
  player_battle_map_[player->id()] = battle;

  auto battle_ai = battle->AddBattleAI();

  battle->Start();

  auto babkemon = BabkemonFactory::Create(BabkemonType::SLIME);
  battle_ai->SpawnBabkemon(babkemon);
  return{ battle, battle->unique_lock() };
}

void BattleManager::_TerminateBattle(int battle_id) {
  // battle is already locked
  auto lock = unique_lock();
  assert(battles_.count(battle_id));
  auto battle = battles_[battle_id];
  for (auto it = battle->battle_players_begin(); it != battle->battle_players_end(); it++) {
    auto player_id = it->first;
    assert(!player_battle_map_.count(player_id));
    player_battle_map_.erase(player_id);
    cout << "[BattleManager] Player (" << player_id << ", " << battle_id << ") unmapped";
  }
  battles_.erase(battle_id);
  cout << "[BattleManager] Battle " << battle_id << " unmapped";
}

std::pair<Battle* const, std::unique_lock<std::mutex>> BattleManager::GetLockedBattle(int battle_id) {
  auto lock = unique_lock();
  auto battle = battles_[battle_id];
  if (battle == nullptr ||
      battle->destroied()) return{ nullptr, std::unique_lock<std::mutex>() };
  return{ battle, battle->unique_lock() };
}

std::pair<Battle* const, std::unique_lock<std::mutex>> BattleManager::GetLockedBattleByPlayer(Player* const player) {
  auto lock = unique_lock();
  auto battle = player_battle_map_[player->id()];
  if (battle == nullptr ||
    battle->destroied()) return{ nullptr, std::unique_lock<std::mutex>() };
  return{ battle, battle->unique_lock() };
}

}

}

}