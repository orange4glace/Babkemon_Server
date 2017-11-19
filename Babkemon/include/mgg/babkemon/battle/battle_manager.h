// battle_manager.h
#ifndef MGG_BABKEMON_BATTLE_BATTL_MANAGER_H_
#define MGG_BABKEMON_BATTLE_BATTL_MANAGER_H_

#include "battle.h"
#include "..\utility\lockable.h"

#include "packet\battle_info_packet.h"

#include <map>
#include <memory>

namespace mgg {

namespace babkemon {

namespace battle {

class BattleManager : public Lockable {

  friend class Battle;

  static BattleManager* instance_;

  std::map<int, Battle*> battles_;
  std::map<PlayerID, Battle*> player_battle_map_;

  void _TerminateBattle(int battle_id);

public:
  static BattleManager* instance();

  std::pair<Battle* const, std::unique_lock<std::mutex>> CreateBattle(Player* const player);
  std::pair<Battle* const, std::unique_lock<std::mutex>> GetLockedBattle(int battle_id);
  std::pair<Battle* const, std::unique_lock<std::mutex>> GetLockedBattleByPlayer(Player* const player);

};

}

}

}

#endif