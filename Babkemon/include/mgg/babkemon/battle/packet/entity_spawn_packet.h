// entity_spawn_packet.h
#ifndef MGG_BABKEMON_BATTLE_ENTITY_SPAWN_PACKET_H_
#define MGG_BABKEMON_BATTLE_ENTITY_SPAWN_PACKET_H_

#include "..\battle_player.h"
#include "..\battle_entity.h"

#include <ProudNetServer.h>

namespace mgg {

namespace babkemon {

namespace battle {

struct EntitySpawnPacket {

  int id;
  BabkemonType type;
  int max_hp;
  int hp;

  inline EntitySpawnPacket(Entity* const entity) {
    id = entity->babkemon()->id();
    type = entity->babkemon()->type();
    max_hp = entity->babkemon()->max_hp();
    hp = entity->babkemon()->hp();
  }

};

}

}

}

namespace Proud {

inline CMessage& operator >> (CMessage& a, mgg::babkemon::battle::EntitySpawnPacket& packet) {
  return a;
}

inline CMessage& operator << (CMessage& a, const mgg::babkemon::battle::EntitySpawnPacket& packet) {
  a << packet.id << packet.type << packet.max_hp << packet.hp;
  return a;
}

inline void AppendTextOut(String& str, const mgg::babkemon::battle::EntitySpawnPacket& packet) {

}

}

#endif