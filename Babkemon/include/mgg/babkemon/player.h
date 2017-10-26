// player.h
#ifndef MGG_BABKEMON_PLAYER_H_
#define MGG_BABKEMON_PLAYER_H_

#include <ProudNetServer.h>

#include "player_state.h"
#include "field/entity/character.h"

namespace mgg {

namespace babkemon {

using PlayerID = int;

class Player {

  PlayerID id_;
  Proud::HostID host_id_;
  PlayerState state_;
  field::Character* field_character_;

public:
  Player(PlayerID id, Proud::HostID host_id);

  PlayerState state() const;
  void set_state(PlayerState state);

  PlayerID id() const;
  Proud::HostID host_id() const;


};

}

}

#endif