// skill_type.h
#ifndef MGG_BABKEMON_BABKEMON_SKILL_TYPE_H_
#define MGG_BABKEMON_BABKEMON_SKILL_TYPE_H_

#include <type_traits>

#include <ProudNetServer.h>

namespace mgg {

namespace babkemon {

namespace babkemon {

enum class SkillType {
  BODY_SLAM
};

inline Proud::CMessage& operator << (Proud::CMessage& a, const SkillType& type) {
  a << (int)static_cast<std::underlying_type<SkillType>::type>(type);
  return a;
}

inline Proud::CMessage& operator >> (Proud::CMessage& a, SkillType& type) {
  int itype;
  a >> itype;
  type = static_cast<SkillType>(itype);
  return a;
}

}

}

}

#endif