// babkemon.h
#ifndef MGG_BABKEMON_BABKEMON_H_
#define MGG_BABKEMON_BABKEMON_H_

#include "babkemon_type.h"

#include "babkemon\skill.h"

#include <atomic>
#include <map>

using namespace mgg::babkemon::babkemon;

namespace mgg {

namespace babkemon {

class Babkemon {

  static std::atomic<int> next_id;

  int id_;
  BabkemonType type_;

  int hp_;
  int max_hp_;

  std::map<SkillType, Skill*> skills_;

protected:
  Babkemon(BabkemonType type);

public:

  void AddSkill(Skill* const skill);

  inline std::map<SkillType, Skill*>::iterator skills_begin() {
    return skills_.begin();
  }
  inline std::map<SkillType, Skill*>::iterator skills_end() {
    return skills_.end();
  }
  inline int skills_size() const {
    return skills_.size();
  }

  int id() const;
  BabkemonType type() const;

  void set_hp(int val);
  int hp() const;

  void set_max_hp(int val);
  int max_hp() const;

};

}

}

#endif