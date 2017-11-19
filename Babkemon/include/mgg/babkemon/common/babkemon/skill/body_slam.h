// body_slam.h
#ifndef MGG_BABKEMON_BABKEMON_SKILL_BODY_SLAM_H_
#define MGG_BABKEMON_BABKEMON_SKILL_BODY_SLAM_H_

#include "..\skill.h"

namespace mgg {

namespace babkemon {

namespace babkemon {

namespace skill {

class BodySlam : public Skill {

public:
  BodySlam(Babkemon* const babkemon);

  SkillCastResult Cast(battle::Entity* const entity) override;

};

}

}

}

}

#endif