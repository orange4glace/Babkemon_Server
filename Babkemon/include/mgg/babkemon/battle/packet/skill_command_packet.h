// skill_command_packet.h
#ifndef MGG_BABKEMON_BATTLE_SKILL_COMMAND_PACKET_H_
#define MGG_BABKEMON_BATTLE_SKILL_COMMAND_PACKET_H_

#include "skill_command_packet_raw.h"
#include "..\battle_player.h"
#include "..\battle_entity.h"

#include "..\..\common\babkemon\skill_type.h"

#include <ProudNetServer.h>

namespace mgg {

namespace babkemon {

namespace battle {

struct SkillCommandPacket {

  SkillCommandPacketRaw* raw;

  ~SkillCommandPacket() {
  }

};

}

}

}

namespace Proud {

CMessage& operator >> (CMessage& a, mgg::babkemon::battle::SkillCommandPacket& packet);

inline void AppendTextOut(String& str, const mgg::babkemon::battle::SkillCommandPacket& packet) {

}

}

#endif