// field_entity_type.h
#ifndef MGG_BABKEMON_FIELD_ENTITY_TYPE_H_
#define MGG_BABKEMON_FIELD_ENTITY_TYPE_H_

#include <type_traits>

#include <ProudNetServer.h>

namespace mgg {

namespace babkemon {

namespace field {

enum class EntityType {
  CHARACTER
};

inline Proud::CMessage& operator << (Proud::CMessage& a, const EntityType& type) {
  a << (int)static_cast<std::underlying_type<EntityType>::type>(type);
  return a;
}

}

}

}


#endif