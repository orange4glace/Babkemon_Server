// field_manager.cpp
#include "field\field_manager.h"

#include "logger\logger.h"

#include "pidl\common_pidl.h"

#include "server.h"

namespace mgg {

namespace babkemon {

namespace field {

FieldManager* FieldManager::instance_ = nullptr;

void FieldManager::Init() {
  instance_ = new FieldManager();
}

FieldManager::FieldManager() {
  Field* field = new Field(0, 20, 20);
  AddField(field);
}

void FieldManager::AddField(Field* const field) {
  assert(field != nullptr && !fields_.count(field->id()));
  fields_[field->id()] = field;
  L_DEBUG << "[FieldManager] Field added. " << field->id();
}

void FieldManager::SetPlayerField(Player* const player, int field_id) {
  unique_lock();
  // assert(player_field_map_.count(player));
  assert(fields_.count(field_id));
  auto prev_field = player_field_map_[player];
  auto this_field = fields_[field_id];
  if (prev_field != nullptr) {
    prev_field->unique_lock();
    prev_field->_RemovePlayer(player);
  }
  this_field->unique_lock();
  pidl::CommonPIDL::instance().ProxyEnterField(player, this_field);
  this_field->_AddPlayer(player);
  player_field_map_[player] = this_field;
  L_DEBUG << "[FieldManager] Set Player " << player->id() << " to " << this_field->id();
}

void FieldManager::ClearPlayerField(Player* const player) {
  unique_lock();
  assert(player_field_map_.count(player));
  auto field = player_field_map_[player];
  field->unique_lock();
  field->_RemovePlayer(player);
  player_field_map_.erase(player);
  L_DEBUG << "[FieldManager] Clear Player " << player->id();
}

locked(Field) FieldManager::GetLockedField(int id) {
  unique_lock();
  assert(fields_.count(id));
  auto field = fields_[id];
  L_DEBUG << "Field = " << field;
  return{ field, std::move(field->unique_lock()) };
}

locked(Field) FieldManager::GetLockedFieldByPlayer(const Player* const player) {
  unique_lock();
  assert(player_field_map_.count(player));
  auto field = player_field_map_[player];
  return{ field, std::move(field->unique_lock()) };
}

}

}

}