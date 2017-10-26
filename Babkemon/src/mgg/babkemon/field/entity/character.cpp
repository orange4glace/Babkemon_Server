// character.cpp
#include "field/entity/character.h"

#include <iostream>

namespace mgg {

namespace babkemon {

namespace field {

Character::Character() :
Entity() {
  placeable_ = new Placeable();
  AddComponent<Placeable>(placeable_);
}

void Character::Move(int dir) {
  
}

}

}

}