// command_packet.h
#ifndef MGG_BABKEMON_BATTLE_COMMAND_PACKET_H_
#define MGG_BABKEMON_BATTLE_COMMAND_PACKET_H_

namespace mgg {

namespace babkemon {

namespace battle {

enum class CommandType {
  SKILL, ITEM
};

struct CommandPacket {
  CommandType command_type;
};

}

}

}

#endif