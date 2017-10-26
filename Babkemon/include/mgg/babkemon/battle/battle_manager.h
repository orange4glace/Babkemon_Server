// battle_manager.h
#ifndef MGG_BABKEMON_BATTLE_BATTL_MANAGER_H_
#define MGG_BABKEMON_BATTLE_BATTL_MANAGER_H_

#include "battle.h"

#include <map>

namespace mgg {

namespace babkemon {

namespace battle {

class BattleManager {

  static BattleManager* instance_;

  std::map<int, Battle*> battles_;
  std::map<Player*, Battle*> player_battle_map_;

public:
  static BattleManager* instance();

  Battle* const CreateBattle();
  void EnterPlayerBattle(Player* const player, Battle* const battle);
  Battle* const GetPlayerBattle(Player* const player);

};

}

}

}

#endif