// skill_cast_result.h
#ifndef MGG_BABKEMON_BABKEMON_SKILL_CAST_RESULT_H_
#define MGG_BABKEMON_BABKEMON_SKILL_CAST_RESULT_H_

namespace mgg {

namespace babkemon {

namespace battle {
namespace packet {
struct BattleSkillCastPacket;
}
}

namespace babkemon {

namespace skill {

struct SkillCastResult {

  battle::packet::BattleSkillCastPacket* packet;

  SkillCastResult(battle::packet::BattleSkillCastPacket* const packet);

  ~SkillCastResult();

};

}

}

}

}

#endif