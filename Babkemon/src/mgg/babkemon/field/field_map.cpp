// field_map.cpp
#include "field\field_map.h"

namespace mgg {

namespace babkemon {

namespace field {

FieldMap::FieldMap(int width, int height) :
width_(width),
height_(height) {
  map_ = new Tile*[width];
  for (int i = 0; i < width; i++)
    map_[i] = new Tile[height];
}

Tile* const FieldMap::tile(int x, int y) const {
  if (x < 0 || y < 0 || x >= width_ || y >= height_) return nullptr;
  return &map_[x][y];
}

}

}

}