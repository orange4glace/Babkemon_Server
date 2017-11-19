// skill.h
#ifndef MGG_BABKEMON_BABKEMON_SKILL_H_
#define MGG_BABKEMON_BABKEMON_SKILL_H_

#include "skill_type.h"

#include "skill\skill_cast_result.h"

#include <ProudNetServer.h>

namespace mgg {

namespace babkemon {

class Babkemon;

namespace battle {
class Entity;
}

namespace babkemon {

class Skill {

  SkillType type_;

  Babkemon* babkemon_;

protected:
  virtual void _Serialize(Proud::CMessage& a) const {}

public:
  Skill(SkillType type, Babkemon* const babkemon);

  virtual skill::SkillCastResult Cast(battle::Entity* const entity) = 0;
  inline void Serialize(Proud::CMessage& a) const {
    a << type_;
    _Serialize(a);
  }

  Babkemon* const babkemon();
  SkillType type() const;

};

}

}

}

#endif