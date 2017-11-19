// health_posion.h
#ifndef MGG_BABKEMON_ITEM_HEALTH_POSION_H_
#define MGG_BABKEMON_ITEM_HEALTH_POSION_H_

#include "babkemon_edible.h"

namespace mgg {

namespace babkemon {

namespace item {

class HealthPosion : public BabkemonEdible {

  int hp_amount_;

public:
  HealthPosion(ItemType type, int hp_amount);

  void Serialize(Proud::CMessage& a) const override;
  void Deserialize(Proud::CMessage& a) override;

};

}

}

}

#endif