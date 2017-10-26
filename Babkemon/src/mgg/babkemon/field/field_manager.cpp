// field_manager.cpp
#include "field\field_manager.h"

#include "logger\logger.h"

#include "server.h"

namespace mgg {

namespace babkemon {

namespace field {

FieldManager* FieldManager::instance_ = nullptr;

FieldManager::FieldManager() {
  Field* field = new Field(0);
  AddField(field);
}

void FieldManager::AddField(Field* const field) {
  assert(field != nullptr && !fields_.count(field->id()));
  fields_[field->id()] = field;
  L_DEBUG << "[FieldManager] Field added. " << field->id();
}

Field* const FieldManager::GetField(int id) {
  assert(fields_.count(id));
  return fields_[id];
}

void FieldManager::SetPlayerField(const Player* const player, Field* const field) {
  player_field_map_[player] = field;
  Server::instance()->ProxyEnterField(player, field->id());
  L_DEBUG << "[FieldManager] Set Player " << player->id() << " to " << field->id();
}

Field* const FieldManager::GetPlayerField(const Player* const player) {
  return player_field_map_[player];
}

}

}

}