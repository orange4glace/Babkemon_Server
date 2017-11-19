// player.cpp
#include "player.h"

#include "field\field_manager.h"
#include "field\entity\character.h"

#include "common\babkemon.h"
#include "inventory.h"

#include "pidl\common_pidl.h"

namespace mgg {

namespace babkemon {

Player::Player(PlayerID id, Proud::HostID host_id) :
id_(id), host_id_(host_id),
state_(PlayerState::FIELD) {
  field_character_ = new field::entity::Character(this);
  inventory_ = new Inventory(this);
  // TODO : Create EntityFactory for avoiding to call entity->Init()
  field_character_->Init();
}

void Player::AddBabkemon(Babkemon* const babkemon) {
  assert(!babkemons_.count(babkemon->id()));
  babkemons_[babkemon->id()] = babkemon;
  pidl::CommonPIDL::instance().ProxyAddBabkemon(this, packet::BabkemonPacket(babkemon));
  L_DEBUG << "[Player " << id_ << "] Add Babkemon " << babkemon->id() << ", " << babkemon->type();
}

Babkemon* const Player::GetBabkemon(int babkemon_id) {
  assert(babkemons_.count(babkemon_id));
  return babkemons_[babkemon_id];
}

PlayerID Player::id() const {
  return id_;
}

Proud::HostID Player::host_id() const {
  return Proud::HostID(id_);
}

PlayerState Player::state() const {
  return state_;
}

void Player::set_state(PlayerState state) {
  state_ = state;
}

field::entity::Character* const Player::field_character() {
  return field_character_;
}

Inventory* const Player::inventory() const {
  return inventory_;
}

}

}