// skill_command_packet.cpp
#include "battle\packet\skill_command_packet.h"

#include "battle\packet\single_target_skill_command_packet.h"

#include "logger\logger.h"

namespace Proud {

using namespace mgg::babkemon::babkemon;

CMessage& operator>>(CMessage& a, mgg::babkemon::battle::SkillCommandPacket& packet) {
  SkillType skill_type;
  a >> skill_type;
  switch (skill_type) {
  case SkillType::BODY_SLAM:
    packet.raw = new mgg::babkemon::battle::SingleTargetSkillCommandPacket(skill_type);
    packet.raw->Deserialize(a);
    break;
  }
  return a;
}

}