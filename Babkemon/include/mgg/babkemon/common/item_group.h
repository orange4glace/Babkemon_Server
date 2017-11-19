// item_group.h
#ifndef MGG_BABKEMON_ITEM_GROUP_H_
#define MGG_BABKEMON_ITEM_GROUP_H_

#include <ProudNetServer.h>

#include <iostream>
#include <type_traits>

namespace mgg {

namespace babkemon {

enum class ItemGroup {
  BABKEMON_EDIBLE
};

inline std::ostream& operator << (std::ostream& os, const ItemGroup& type) {
  switch (type) {
  case ItemGroup::BABKEMON_EDIBLE:
    os << "BABKEMON_EDIBLE";
  }
  return os;
}

inline Proud::CMessage& operator << (Proud::CMessage& a, const ItemGroup& type) {
  a << (int)static_cast<std::underlying_type<ItemGroup>::type>(type);
  return a;
}

}

}

#endif