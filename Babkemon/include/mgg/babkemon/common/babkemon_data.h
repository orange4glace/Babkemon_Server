// babkemon_data.h
#ifndef MGG_BABKEMON_BABKEMON_DATA_H_
#define MGG_BABKEMON_BABKEMON_DATA_H_

#include "babkemon_type.h"

namespace mgg {

namespace babkemon {

struct BabkemonData {

  int id;
  BabkemonType type;
  int hp;
  int mp;
  int level;
  int exp;

};

}

}

#endif