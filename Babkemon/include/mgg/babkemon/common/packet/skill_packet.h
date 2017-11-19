// skill_packet.h
#ifndef MGG_BABKEMON_BABKEMON_SKILL_PACKET_H_
#define MGG_BABKEMON_BABKEMON_SKILL_PACKET_H_

#include "..\babkemon\skill.h"

#include <ProudNetServer.h>

using namespace ::mgg::babkemon::babkemon;

namespace mgg {

namespace babkemon {

namespace packet {

struct SkillPacket {

  SkillType type;

  inline SkillPacket(Skill* skill) {
    type = skill->type();
  }

  virtual void Serialize(Proud::CMessage&) const {}
};

}

}

}

namespace Proud {

inline CMessage& operator << (CMessage& a, const mgg::babkemon::packet::SkillPacket& packet) {
  a << packet.type;
  packet.Serialize(a);
  return a;
}

inline void AppendTextOut(String& str, const mgg::babkemon::packet::SkillPacket& packet) {

}

}

#endif