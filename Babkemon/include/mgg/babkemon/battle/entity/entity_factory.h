// entity_factory.h
#ifndef MGG_BABKEMON_BATTLE_ENTITY_ENTITY_FACTORY_H_
#define MGG_BABKEMON_BATTLE_ENTITY_ENTITY_FACTORY_H_

#include "../../common/babkemon_data.h"
#include "battle_entity.h"
#include "battle_slime.h"

#include <cassert>

namespace mgg {

namespace babkemon {

namespace battle {

namespace entity {

class EntityFactory {

public:
  static Entity* CreateEntity(BabkemonData data) {
    auto type = data.type;
    Entity* result = nullptr;
    switch (type) {
    case BabkemonType::SLIME:
      result = new Slime();
    }
    assert(result != nullptr);
    result->set_hp(data.hp);
    return result;
  }

};

}

}

}

}

#endif