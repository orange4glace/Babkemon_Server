// field_manager.h
#ifndef MGG_BABKEMON_FIELD_FIELD_MANAGER_H_
#define MGG_BABKEMON_FIELD_FIELD_MANAGER_H_

#include "field.h"

#include "..\utility\lockable.h"

#include "logger\logger.h"

#include <map>

namespace mgg {

namespace babkemon {

namespace field {

class FieldManager : public Lockable {

  static FieldManager* instance_;

  std::map<int, Field*> fields_;
  std::map<const Player* const, Field*> player_field_map_;

public:
  inline static FieldManager* instance() {
    return instance_;
  }

  static void Init();

  FieldManager();

  void AddField(Field* const field);
  locked(Field) GetLockedField(int id);
  void SetPlayerField(Player* const player, int field_id);
  void ClearPlayerField(Player* const player);
  locked(Field) GetLockedFieldByPlayer(const Player* const player);

};

}

}

}

#endif