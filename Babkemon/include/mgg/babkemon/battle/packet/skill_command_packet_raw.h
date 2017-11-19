// skill_command_packet_raw.h
#ifndef MGG_BABKEMON_BATTLE_SKILL_COMMAND_PACKET_RAW_H_
#define MGG_BABKEMON_BATTLE_SKILL_COMMAND_PACKET_RAW_H_

#include "command_packet.h"

#include "..\battle_player.h"
#include "..\battle_entity.h"

#include "..\..\common\babkemon\skill_type.h"

namespace mgg {

namespace babkemon {

namespace battle {

struct SkillCommandPacketRaw : CommandPacket {

  babkemon::SkillType skill_type;

  inline SkillCommandPacketRaw(babkemon::SkillType stype) {
    command_type = CommandType::SKILL;
    skill_type = stype;
  }

  virtual void Deserialize(Proud::CMessage&) = 0;

};

}

}

}

#endif