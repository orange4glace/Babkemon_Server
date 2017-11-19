// spawn_entity_packet.h
#ifndef MGG_BABKEMON_FIELD_SPAWN_ENTITY_PACKET_H_
#define MGG_BABKEMON_FIELD_SPAWN_ENTITY_PACKET_H_

#include "..\..\utility\ivector2.h"

#include "..\entity\field_entity.h"

#include <ProudNetServer.h>

namespace mgg {

namespace babkemon {

namespace field {

struct EntitySpawnPacket {

  int id;
  int player_id;
  EntityType type;

};

}

}

}

namespace Proud {

inline CMessage& operator >> (CMessage& a, mgg::babkemon::field::EntitySpawnPacket& packet) {
  return a;
}

inline CMessage& operator << (CMessage& a, const mgg::babkemon::field::EntitySpawnPacket& packet) {
  a << packet.id << packet.player_id << packet.type;
  return a;
}

inline void AppendTextOut(String& str, const mgg::babkemon::field::EntitySpawnPacket& packet) {

}

}

#endif