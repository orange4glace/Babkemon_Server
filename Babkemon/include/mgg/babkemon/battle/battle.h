// battle_field.h
#ifndef MGG_BABKEMON_BATTLE_BATTL_H_
#define MGG_BABKEMON_BATTLE_BATTL_H_

#include "battle_player.h"
#include "entity/battle_entity.h"

#include <map>
#include <vector>

namespace mgg {

namespace babkemon {

namespace battle {

class Battle {

  static int next_battle_id_;

  int id_;
  std::map<PlayerID, BattlePlayer*> battle_players_;
  std::vector<Entity*> entities_;

public:
  Battle();

  void AddBattlePlayer(Player* const player);
  void Update(int dt);

  void AddEntity(Entity* const entity);
  Entity* const GetEntity(int id);

  int id() const;

};

}

}

}

#endif