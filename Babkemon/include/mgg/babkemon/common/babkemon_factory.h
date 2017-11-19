// babkemon_factory.h
#ifndef MGG_BABKEMON_BABKEMON_FACTORY_H_
#define MGG_BABKEMON_BABKEMON_FACTORY_H_

#include "babkemon.h"

#include "babkemon\slime.h"

namespace mgg {

namespace babkemon {

class BabkemonFactory {

public:
  inline static Babkemon* const Create(BabkemonType type) {
    Babkemon* result = nullptr;
    switch (type) {
    case BabkemonType::SLIME:
      result = new babkemon::Slime();
      break;
    }
    assert(result != nullptr);
    result->set_max_hp(20);
    result->set_hp(10);
    return result;
  }

};

}

}

#endif