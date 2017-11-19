// item_packet.h
#ifndef MGG_BABKEMON_ITEM_ITEM_PACKET_H_
#define MGG_BABKEMON_ITEM_ITEM_PACKET_H_

#include "..\item_type.h"

#include <ProudNetServer.h>

namespace mgg {

namespace babkemon {

class Item;

namespace item {

struct ItemPacket {

  Item* item;
  ItemType type;
  int amount;

  // For Serialize
  ItemPacket(Item* const _item);
  // For Deserialize
  ItemPacket();

};

}

}

}

namespace Proud {

CMessage& operator >> (CMessage& a, mgg::babkemon::item::ItemPacket& packet);
CMessage& operator << (CMessage& a, const mgg::babkemon::item::ItemPacket& packet);
inline void AppendTextOut(String& str, const mgg::babkemon::item::ItemPacket& packet) {}

}

#endif