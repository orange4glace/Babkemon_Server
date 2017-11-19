// field.cpp
#include "field\field.h"

#include "field\entity\field_entity.h"
#include "field\entity\character.h"
#include "field\packet\field_snapshot_packet.h"
#include "field\packet\entity_spawn_packet.h"

#include "pidl\field_pidl.h"

#include "utility\scheduler.h"

#include "logger\logger.h"

namespace mgg {

namespace babkemon {

namespace field {

Field::Field(int id, int width, int height) :
  id_(id),
  field_map_(width, height) {

  // TODO : This should be handled when destroying this field
  Scheduler::instance()->interval(MS(1000), [&]() {
    unique_lock();
    _SendSnapshot();
    return true;
  });
}

void Field::_SendSnapshot() {
  FieldSnapshotPacket packet;
  for (auto ep : entities_) {
    auto entity = ep.second;
    EntityPacket entity_packet;
    entity_packet.entity_id = entity->id();
    entity_packet.position = entity->position();
    packet.entity_packets.emplace_back(entity_packet);
  }

  pidl::FieldPIDL::instance().ProxySnapshot(this, packet);
}

void Field::_AddPlayer(Player* const player) {
  assert(!players_.count(player->id()));
  players_[player->id()] = player;
  AddEntity(player->field_character());
  L_DEBUG << "[Field " << id_ << "] Player " << player->id() << " added.";
}

void Field::_RemovePlayer(Player* const player) {
  assert(players_.count(player->id()));
  players_.erase(player->id());
  RemoveEntity(player->field_character()->id());
  L_DEBUG << "[Field " << id_ << "] Player " << player->id() << " removed.";
}

void Field::AddEntity(Entity* const entity) {
  assert(!entities_.count(entity->id()));
  entities_[entity->id()] = entity;
  entity->field_ = this;
  EntitySpawnPacket packet;
  packet.id = entity->id();
  packet.player_id = (entity->player() != nullptr ? entity->player()->id() : PLAYER_ID_AI);
  packet.type = entity->type();
  pidl::FieldPIDL::instance().ProxySpawnEntity(this, packet);
  L_DEBUG << "[Field " << id_ << "] Entity " << entity->id() << " added.";
}

void Field::RemoveEntity(int entity_id) {
  assert(entities_.count(entity_id));
  entities_.erase(entity_id);
  pidl::FieldPIDL::instance().ProxyDespawnEntity(this, entity_id);
  L_DEBUG << "[Field " << id_ << "] Entity " << entity_id << " removed.";
}

int Field::id() const {
  return id_;
}

FieldMap* const Field::field_map() {
  return &field_map_;
}

}

}

}