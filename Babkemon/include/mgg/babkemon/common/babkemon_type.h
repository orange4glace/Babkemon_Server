// babkemon_type.h
#ifndef MGG_BABKEMON_BABKEMON_TYPE_H_
#define MGG_BABKEMON_BABKEMON_TYPE_H_

#include <iostream>

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

}

}

#endif