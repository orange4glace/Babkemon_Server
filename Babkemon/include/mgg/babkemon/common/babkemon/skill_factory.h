// skill_factory.h
#ifndef MGG_BABKEMON_BABKEMON_SKILL_FACTORY_H_
#define MGG_BABKEMON_BABKEMON_SKILL_FACTORY_H_

#include "skill.h"
#include "skill\body_slam.h"

using namespace mgg::babkemon::babkemon::skill;

namespace mgg {

namespace babkemon {

namespace babkemon {

class SkillFactory {

public:
  inline static Skill* const Create(Babkemon* const babkemon, SkillType type) {
    Skill* result = nullptr;
    switch (type) {
    case SkillType::BODY_SLAM:
      result = new BodySlam(babkemon);
      break;
    }
    assert(result != nullptr);
    return result;
  }

};

}

}

}

#endif