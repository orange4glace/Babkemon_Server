// babkemon.cpp
#include "common\babkemon.h"

namespace mgg {

namespace babkemon {

std::atomic<int> Babkemon::next_id(0);

Babkemon::Babkemon(BabkemonType type) :
id_(next_id++),
type_(type) {
}

void Babkemon::AddSkill(Skill* const skill) {
  assert(skills_.count(skill->type()) == 0);
  skills_[skill->type()] = skill;
}

int Babkemon::id() const {
  return id_;
}

BabkemonType Babkemon::type() const {
  return type_;
}

void Babkemon::set_hp(int val) {
  hp_ = val;
}

int Babkemon::hp() const {
  return hp_;
}

void Babkemon::set_max_hp(int val) {
  max_hp_ = val;
}

int Babkemon::max_hp() const {
  return max_hp_;
}

}

}