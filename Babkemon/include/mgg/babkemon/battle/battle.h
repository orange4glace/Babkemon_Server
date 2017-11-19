// battle_field.h
#ifndef MGG_BABKEMON_BATTLE_BATTL_H_
#define MGG_BABKEMON_BATTLE_BATTL_H_

#include "battle_player.h"
#include "battle_player_ai.h"
#include "battle_entity.h"

#include "..\utility\shareable.h"

#include <map>
#include <vector>
#include <memory>
#include <boost/thread/mutex.hpp>

namespace mgg {

namespace babkemon {

namespace battle {

using battle_players_it = std::map<PlayerID, BattlePlayer*>::iterator;

enum class BattleType {
  PVE, PVP
};

class Battle : public Shareable {

  static int next_battle_id_;

  int id_;
  std::map<PlayerID, BattlePlayer*> battle_players_;
  std::vector<Entity*> entities_;
  
  int step_;

  void destroy() override;

public:
  Battle();
  ~Battle();

  void AddBattlePlayer(Player* const player);
  BattlePlayerAI* const AddBattleAI();

  void AddEntity(Entity* const entity);
  Entity* const GetEntity(EntityID id);

  void Start();

  bool CheckStep();
  void DoStep();

  inline std::map<PlayerID, BattlePlayer*>::iterator battle_players_begin() {
    return battle_players_.begin();
  }
  inline std::map<PlayerID, BattlePlayer*>::iterator battle_players_end() {
    return battle_players_.end();
  }

  inline std::vector<Entity*>::iterator entities_begin() {
    return entities_.begin();
  }
  inline std::vector<Entity*>::iterator entities_end() {
    return entities_.end();
  }

  BattlePlayer* const battle_player(PlayerID player_id);
  int id() const;

};

}

}

}

#endif