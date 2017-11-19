// field_pidl.cpp
#include "pidl\field_pidl.h"

#include "..\..\..\pidl\field_s2c_common.cpp"
#include "..\..\..\pidl\field_s2c_proxy.cpp"
#include "..\..\..\pidl\field_c2s_common.cpp"
#include "..\..\..\pidl\field_c2s_stub.cpp"

#include "server.h"
#include "field\field_manager.h"
#include "field\entity\character.h"

namespace mgg {

namespace babkemon {

namespace pidl {

void FieldPIDL::_SetStubs() {
  stub_.MoveCharacter_Function = [&]PARAM_field_c2s_MoveCharacter{
    StubMoveCharacter(remote, rmiContext, packet);
    return true;
  };
}

void FieldPIDL::ProxySnapshot(
  ::mgg::babkemon::field::Field* const field,
  const ::mgg::babkemon::field::FieldSnapshotPacket& const packet) {
  for (auto it = field->players_begin(); it != field->players_end(); it++) {
    auto player = it->second;
    proxy_.Snapshot(player->host_id(), ::Proud::RmiContext::ReliableSend, packet);
  }
}

void FieldPIDL::ProxySpawnEntity(
  ::mgg::babkemon::field::Field* const field,
  const ::mgg::babkemon::field::EntitySpawnPacket& packet) {
  for (auto it = field->players_begin(); it != field->players_end(); it++) {
    auto player = it->second;
    proxy_.SpawnEntity(player->host_id(), ::Proud::RmiContext::ReliableSend, packet);
  }
}

void FieldPIDL::ProxyDespawnEntity(
  ::mgg::babkemon::field::Field* const field,
  int entity_id) {
  for (auto it = field->players_begin(); it != field->players_end(); it++) {
    auto player = it->second;
    proxy_.DespawnEntity(player->host_id(), ::Proud::RmiContext::ReliableSend, entity_id);
  }
}

bool FieldPIDL::StubMoveCharacter(::Proud::HostID remote, ::Proud::RmiContext& rmiContext,
  const ::mgg::babkemon::field::CharacterMovePacket& packet) {
  // lock the player
  auto locked_player = ::mgg::babkemon::Server::instance()->GetLockedPlayer(remote);
  auto player = locked_player.first;
  if (player == nullptr) return true;
  // lock the field
  player->field_character()->field()->unique_lock();
  for (int i = 0; i < packet.dirs.size(); i++) {
    player->field_character()->Move(packet.dirs[i]);
    if (packet.dirs[i] > 0)
      L_DEBUG << "[FieldPIDL] Move Character Stub " << remote;
  }
  return true;
}

}

}

}