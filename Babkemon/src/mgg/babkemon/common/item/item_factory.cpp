// item_factory.cpp
#include "common/item_factory.h"

#include "common/item/health_posion.h"

#include <cassert>

namespace mgg {

namespace babkemon {

Item* ItemFactory::CreateItem(ItemType type) {
  Item* ret = nullptr;
  switch (type) {
  case ItemType::SMALL_POSION:
    ret = new item::HealthPosion(ItemType::SMALL_POSION, 10);
  }
  assert(ret != nullptr);
  return ret;
}

}

}