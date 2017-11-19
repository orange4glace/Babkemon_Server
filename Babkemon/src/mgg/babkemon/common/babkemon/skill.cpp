// skill.cpp
#include "common\babkemon\skill.h"

#include "common\babkemon.h"

namespace mgg {

namespace babkemon {

namespace babkemon {

Skill::Skill(SkillType type, Babkemon* const babkemon) :
  type_(type),
  babkemon_(babkemon) {

}

Babkemon* const Skill::babkemon() {
  return babkemon_;
}

SkillType Skill::type() const {
  return type_;
}

}

}

}