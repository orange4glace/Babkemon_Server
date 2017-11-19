// execution_packet.h
#ifndef MGG_BABKEMON_BATTLE_EXECUTION_PACKET_H_
#define MGG_BABKEMON_BATTLE_EXECUTION_PACKET_H_

namespace mgg {

namespace babkemon {

namespace battle {

enum class ExeuctionType {
  SKILL, ITEM
};

struct ExecutionPacket {
  ExeuctionType execution_type;
};

}

}

}

#endif