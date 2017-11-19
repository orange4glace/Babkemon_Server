// placeable.cpp
#include "field\component\placeable.h"

#include "utility\ivector2.h"

#include "field\entity\field_entity.h"

namespace mgg {

namespace babkemon {

namespace field {

Placeable::Placeable(Entity* const entity) : ComponentBase<Placeable>(entity),
position_(0, 0) {
  entity->AddComponent<Placeable>(this);
}

const IVector2& Placeable::position() const {
  return position_;
}

void Placeable::set_position(const IVector2& val) {
  position_.set(val);
}

}

}

}