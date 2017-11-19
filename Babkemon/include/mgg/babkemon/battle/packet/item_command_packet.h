// item_command_packet.h
#ifndef MGG_BABKEMON_BATTLE_ITEM_COMMAND_PACKET_H_
#define MGG_BABKEMON_BATTLE_ITEM_COMMAND_PACKET_H_

#include "..\battle_player.h"
#include "..\battle_entity.h"
#include "..\..\common\item_type.h"

#include <ProudNetServer.h>

namespace mgg {

namespace babkemon {

namespace battle {

struct ItemCommandPacketRaw {

  ItemType item_type;
  int item_id;

  virtual void Deserialize(Proud::CMessage& a) = 0;

};

struct ItemCommandPacket {

  ItemCommandPacketRaw* raw;

  ~ItemCommandPacket() {
    delete raw;
  }

};

}

}

}

namespace Proud {

CMessage& operator >> (CMessage& a, mgg::babkemon::battle::ItemCommandPacket& packet);

inline void AppendTextOut(String& str, const mgg::babkemon::battle::ItemCommandPacket& packet) {

}

}

#endif