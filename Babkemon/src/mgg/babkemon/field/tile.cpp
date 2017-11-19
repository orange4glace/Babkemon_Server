// tile.cpp
#include "field\tile.h"

namespace mgg {

namespace babkemon {

namespace field {

Tile::Tile() :
  type_(0) {

}

Tile::Tile(int type) :
  type_(type) {

}

bool Tile::movable() const {
  return true;
}

}

}

}