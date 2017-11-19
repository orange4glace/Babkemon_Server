// babkemon_type.h
#ifndef MGG_BABKEMON_BABKEMON_TYPE_H_
#define MGG_BABKEMON_BABKEMON_TYPE_H_

#include <ProudNetServer.h>

#include <iostream>
#include <type_traits>

namespace mgg {

namespace babkemon {

enum class BabkemonType {
  SLIME
};

inline std::ostream& operator << (std::ostream& os, const BabkemonType& type) {
  switch (type) {
  case BabkemonType::SLIME:
    os << "Slime";
  }
  return os;
}

inline Proud::CMessage& operator << (Proud::CMessage& a, const BabkemonType& type) {
  a << (int)static_cast<std::underlying_type<BabkemonType>::type>(type);
  return a;
}

}

}

#endif