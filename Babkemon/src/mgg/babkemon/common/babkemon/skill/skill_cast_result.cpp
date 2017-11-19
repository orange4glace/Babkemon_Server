// skill_cast_result.cpp
#include "common\babkemon\skill\skill_cast_result.h"

#include "battle\packet\battle_skill_cast_packet.h"

namespace mgg {

namespace babkemon {

namespace babkemon {

namespace skill {

SkillCastResult::SkillCastResult(battle::packet::BattleSkillCastPacket* const packet) {
  this->packet = packet;
}

SkillCastResult::~SkillCastResult() {
  delete packet;
}

}

}

}

}