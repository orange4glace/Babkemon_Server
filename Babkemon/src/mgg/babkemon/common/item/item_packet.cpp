// item_packet.cpp
#include "common\item\item_packet.h"

#include "common\item.h"

#include "common\item_factory.h"

namespace mgg {

namespace babkemon {

namespace item {

ItemPacket::ItemPacket(Item* const _item) :
item(_item) {
  type = item->type();
}

ItemPacket::ItemPacket() {}

}

}

}

namespace Proud {

CMessage& operator >> (CMessage& a, mgg::babkemon::item::ItemPacket& packet) {
  a >> packet.type >> packet.amount;
  packet.item = mgg::babkemon::ItemFactory::CreateItem(packet.type);
  assert(packet.item->stackable());
  packet.item->set_amount(packet.amount);
  packet.item->Deserialize(a);
  return a;
}

CMessage& operator << (CMessage& a, const mgg::babkemon::item::ItemPacket& packet) {
  a << packet.item->id() << packet.type << packet.item->amount();
  packet.item->Serialize(a);
  return a;
}

}