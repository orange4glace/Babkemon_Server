// battle_field.h
#ifndef MGG_BABKEMON_BATTLE_ENTITY_ENTITY_H_
#define MGG_BABKEMON_BATTLE_ENTITY_ENTITY_H_

#include "..\common\babkemon.h"
#include "..\utility\time.h"

#include "packet\command_packet.h"
#include "packet\execution_packet.h"

#include <memory>

namespace mgg {

namespace babkemon {

namespace battle {

class Battle;
class BattlePlayer;

using EntityID = int;

class Entity {

  Babkemon* babkemon_;
  Battle* battle_;
  BattlePlayer* battle_player_;
  BabkemonType type_;

  CommandPacket* command_;

public:
  Entity(Battle* const battle, BattlePlayer* const battle_player, Babkemon* const babkemon);
  ~Entity();

  void Start();

  void ExecuteCommand();

  CommandPacket* const command();
  void set_command(CommandPacket* const command);
  
  int hp() const;
  void set_hp(int val);

  Babkemon* const babkemon();
  BattlePlayer* battle_player();
  Battle* const battle();

};

}

}

}

#endif