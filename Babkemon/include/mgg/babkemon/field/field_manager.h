// field_manager.h
#ifndef MGG_BABKEMON_FIELD_FIELD_MANAGER_H_
#define MGG_BABKEMON_FIELD_FIELD_MANAGER_H_

#include "field.h"

#include <map>

namespace mgg {

namespace babkemon {

namespace field {

class FieldManager {

  static FieldManager* instance_;

  std::map<int, Field*> fields_;
  std::map<const Player* const, Field*> player_field_map_;

public:
  inline static FieldManager* instance() {
    if (instance_ == nullptr)
      instance_ = new FieldManager();
    return instance_;
  }

  FieldManager();

  void AddField(Field* const field);
  Field* const GetField(int id);
  void SetPlayerField(const Player* const player, Field* const field);
  Field* const GetPlayerField(const Player* const player);

};

}

}

}

#endif