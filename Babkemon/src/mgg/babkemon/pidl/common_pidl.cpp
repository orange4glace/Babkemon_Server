// common_pidl.cpp
#include "pidl\common_pidl.h"

#include "..\..\..\pidl\common_s2c_common.cpp"
#include "..\..\..\pidl\common_s2c_proxy.cpp"
#include "..\..\..\pidl\common_c2s_common.cpp"
#include "..\..\..\pidl\common_c2s_stub.cpp"

#include "server.h"
#include "field\field_manager.h"

#include "logger\logger.h"

namespace mgg {

namespace babkemon {

namespace pidl {

void CommonPIDL::_SetStubs() {
}

void CommonPIDL::ProxyWelcome(
  Player* const player) {
  L_DEBUG << "[CommonPIDL] Welcome " << player->id();
  proxy_.Welcome(player->host_id(), Proud::RmiContext::ReliableSend, player->id());
}

void CommonPIDL::ProxyEnterBattle(
  Player* const player,
  ::mgg::babkemon::battle::Battle* const battle) {
  L_DEBUG << "[CommonPIDL] Enter Battle " << player->id() << " " << battle->id();
  proxy_.EnterBattle(player->host_id(), Proud::RmiContext::ReliableSend, battle->id());
}

void CommonPIDL::ProxyEnterField(
  Player* const player,
  ::mgg::babkemon::field::Field* const field) {
  L_DEBUG << "[CommonPIDL] Enter Field " << player->id() << " " << field->id();
  proxy_.EnterField(player->host_id(), Proud::RmiContext::ReliableSend, field->id());
}

void CommonPIDL::ProxyAddBabkemon(
  Player* const player,
  packet::BabkemonPacket& packet) {
  proxy_.AddBabkemon(player->host_id(), Proud::RmiContext::ReliableSend, packet);
}

void CommonPIDL::ProxyAddItem(
  Player* const player,
  item::ItemPacket& packet) {
  proxy_.AddItem(player->host_id(), Proud::RmiContext::ReliableSend, packet);
}

void CommonPIDL::ProxyRemoveItem(
  Player* const player,
  int item_id) {
  proxy_.RemoveItem(player->host_id(), Proud::RmiContext::ReliableSend, item_id);
}

void CommonPIDL::ProxySetItemAmount(
  Player* const player,
  int item_id,
  int amount) {
  proxy_.SetItemAmount(player->host_id(), Proud::RmiContext::ReliableSend, item_id, amount);
}

}

}

}