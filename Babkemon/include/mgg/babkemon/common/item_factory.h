// item_factory.h
#ifndef MGG_BABKEMON_ITEM_ITEM_FACTORY_H_
#define MGG_BABKEMON_ITEM_ITEM_FACTORY_H_

#include "item.h"

namespace mgg {

namespace babkemon {

class ItemFactory {

public:
  static Item* CreateItem(ItemType type);

};

}

}

#endif