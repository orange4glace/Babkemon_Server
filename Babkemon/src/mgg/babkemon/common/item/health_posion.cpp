// health_posion.cpp
#include "common/item/health_posion.h"

namespace mgg {

namespace babkemon {

namespace item {

HealthPosion::HealthPosion(ItemType type, int hp_amount) :
  BabkemonEdible(type),
  hp_amount_(hp_amount) {

}

void HealthPosion::Serialize(Proud::CMessage& a) const {

}

void HealthPosion::Deserialize(Proud::CMessage& a) {

}

}

}

}