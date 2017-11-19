// field_map.h
#ifndef MGG_BABKEMON_FIELD_FIELD_MAP_H_
#define MGG_BABKEMON_FIELD_FIELD_MAP_H_

#include "tile.h"

namespace mgg {

namespace babkemon {

namespace field {

class FieldMap {

  int width_, height_;
  Tile** map_;

public:
  FieldMap(int width, int height);

  Tile* const tile(int x, int y) const;
};

}

}

}

#endif