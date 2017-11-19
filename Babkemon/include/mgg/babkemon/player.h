// player.h
#ifndef MGG_BABKEMON_PLAYER_H_
#define MGG_BABKEMON_PLAYER_H_

#include <ProudNetServer.h>

#include "utility\lockable.h"
#include "player_state.h"

namespace mgg {

namespace babkemon {

class Inventory;
class Babkemon;

namespace field {
namespace entity {
class Character;
}
}

#define PLAYER_ID_AI (2147483647)

using PlayerID = int;

class Player : public Lockable {

  PlayerID id_;
  Proud::HostID host_id_;
  PlayerState state_;
  field::entity::Character* field_character_;

  std::map<int, Babkemon*> babkemons_;
  Inventory* inventory_;

public:
  Player(PlayerID id, Proud::HostID host_id);

  void AddBabkemon(Babkemon* const babkemon);
  Babkemon* const GetBabkemon(int babkemon_id);

  PlayerState state() const;
  void set_state(PlayerState state);

  field::entity::Character* const field_character();

  PlayerID id() const;
  Proud::HostID host_id() const;

  Inventory* const inventory() const;

};

}

}

#endif