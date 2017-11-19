// skill_cast_packet.h
#ifndef MGG_BABKEMON_BATTLE_BATTLE_SKILL_CAST_RESULT_H_
#define MGG_BABKEMON_BATTLE_BATTLE_SKILL_CAST_RESULT_H_

#include "execution_packet.h"

#include "..\..\common\babkemon\skill.h"

#include <ProudNetServer.h>

namespace mgg {

namespace babkemon {

namespace battle {

namespace packet {

using namespace ::mgg::babkemon::babkemon;

struct BattleSkillCastPacket : ExecutionPacket {

  SkillType skill_type;

  inline BattleSkillCastPacket(SkillType stype) {
    skill_type = stype;
  }

  virtual void Serialize(Proud::CMessage&) const = 0;
};

struct BattleSingleTargetSkillCastPacket : BattleSkillCastPacket {

  int target_entity_id;
  int damage;

  inline BattleSingleTargetSkillCastPacket(SkillType type, int target_entity_id, int damage) :
    BattleSkillCastPacket(type) {
    this->target_entity_id = target_entity_id;
    this->damage = damage;
  }

  inline void Serialize(Proud::CMessage& a) const {
    a << target_entity_id << damage;
  }
};

}

}

}

}

namespace Proud {

inline CMessage& operator << (CMessage& a, const mgg::babkemon::battle::packet::BattleSkillCastPacket& packet) {
  return a;
}

inline void AppendTextOut(String& str, const mgg::babkemon::battle::packet::BattleSkillCastPacket& packet) {

}

}

#endif