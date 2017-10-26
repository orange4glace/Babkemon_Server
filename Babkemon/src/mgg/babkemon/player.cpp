// player.cpp
#include "player.h"

#include "field\field_manager.h"

namespace mgg {

namespace babkemon {

Player::Player(PlayerID id, Proud::HostID host_id) :
id_(id), host_id_(host_id) {
  field_character_ = new field::Character();

  field::FieldManager::instance()->SetPlayerField(this, field::FieldManager::instance()->GetField(0));
}

PlayerID Player::id() const {
  return id_;
}

Proud::HostID Player::host_id() const {
  return host_id_;
}

PlayerState Player::state() const {
  return state_;
}

void Player::set_state(PlayerState state) {
  state_ = state;
}

}

}