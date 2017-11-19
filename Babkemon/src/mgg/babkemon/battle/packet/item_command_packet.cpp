// item_command_packet.cpp
#include "battle\packet\item_command_packet.h"

// #include "battle\packet\self_cast_item_command_packet.h"
#include "common\item.h"

#include "logger\logger.h"

namespace Proud {

using namespace mgg::babkemon::item;

CMessage& operator >> (CMessage& a, mgg::babkemon::battle::ItemCommandPacket& packet) {
  /*
  int item_id;
  a >> item_id;
  ItemType item_type;
  a >> item_type;
  switch (item_type) {
  case ItemType::SMALL_POSION:
    packet.raw = new mgg::babkemon::battle::SelfCastItemCommandPacket();
    packet.raw->Deserialize(a);
    break;
  }
  packet.raw->item_id = item_id;
  packet.raw->item_type = item_type;
  */
  return a;
}

}