// field.h
#ifndef MGG_BABKEMON_FIELD_FIELD_H_
#define MGG_BABKEMON_FIELD_FIELD_H_

#include "..\player.h"
#include "entity\field_entity.h"

#include <map>

namespace mgg {

namespace babkemon {

namespace field {

class Field {

  int id_;
  std::map<int, Entity*> entities_;

public:
  Field(int id);

  void AddEntity(Entity* const entity);

  int id() const;

};

}

}

}

#endif