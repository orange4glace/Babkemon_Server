// tile.h
#ifndef MGG_BABKEMON_FIELD_TILE_H_
#define MGG_BABKEMON_FIELD_TILE_H_

namespace mgg {

namespace babkemon {

namespace field {

class Tile {

  int type_;

public:
  Tile();
  Tile(int type);

  bool movable() const;

};

}

}

}

#endif