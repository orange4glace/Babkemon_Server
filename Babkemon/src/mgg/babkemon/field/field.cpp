// field.cpp
#include "field\field.h"

namespace mgg {

namespace babkemon {

namespace field {

Field::Field(int id) :
  id_(id) {

}

void Field::AddEntity(Entity* const entity) {

}

int Field::id() const {
  return id_;
}

}

}

}