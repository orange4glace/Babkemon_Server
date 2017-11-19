// single_target_skill_command_packet.h
#ifndef MGG_BABKEMON_BATTLE_SINGLE_TARGET_SKILL_COMMAND_PACKET_H_
#define MGG_BABKEMON_BATTLE_SINGLE_TARGET_SKILL_COMMAND_PACKET_H_

#include "skill_command_packet_raw.h"

#include <ProudNetServer.h>

namespace mgg {

namespace babkemon {

namespace battle {

struct SingleTargetSkillCommandPacket : SkillCommandPacketRaw {

  int target;

  inline SingleTargetSkillCommandPacket(babkemon::SkillType stype) : SkillCommandPacketRaw(stype) {
  }

  inline void Deserialize(Proud::CMessage& a) override {
    a >> target;
  }

};

}

}

}

#endif