// item_type.h
#ifndef MGG_BABKEMON_ITEM_TYPE_H_
#define MGG_BABKEMON_ITEM_TYPE_H_

#include <ProudNetServer.h>

#include <iostream>
#include <type_traits>

namespace mgg {

namespace babkemon {

enum class ItemType {
  SMALL_POSION
};

inline std::ostream& operator << (std::ostream& os, const ItemType& type) {
  switch (type) {
  case ItemType::SMALL_POSION:
    os << "SMALL_POSION";
  }
  return os;
}

inline Proud::CMessage& operator << (Proud::CMessage& a, const ItemType& type) {
  a << (int)static_cast<std::underlying_type<ItemType>::type>(type);
  return a;
}

inline Proud::CMessage& operator >> (Proud::CMessage& a, ItemType& type) {
  int i;
  a >> i;
  type = static_cast<ItemType>(i);
  return a;
}

}

}

#endif