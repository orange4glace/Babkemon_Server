// movable.cpp
#include "field\component\movable.h"

#include "field\field.h"
#include "field\entity\field_entity.h"

#include "logger\logger.h"

namespace mgg {

namespace babkemon {

namespace field {

int dx[5] = { 0, 0, 1, 0, -1 };
int dy[5] = { 0, 1, 0, -1, 0 };

Movable::Movable(Entity* const entity) : ComponentBase<Movable>(entity) {
  entity->AddComponent<Movable>(this);
}

void Movable::Initialize() {
  placeable_ = entity_->GetComponent<Placeable>();
  L_DEBUG << "Initialize movable " << placeable_;
}

bool Movable::Move(int dir, Field* const field) {
  auto position = placeable_->position();
  int nx = position.x() + dx[dir];
  int ny = position.y() + dy[dir];

  auto tile = field->field_map()->tile(nx, ny);
  if (tile == nullptr) return false;
  if (tile->movable()) {
    placeable_->set_position(IVector2(nx, ny));
    return true;
  }
  return false;
}

}

}

}