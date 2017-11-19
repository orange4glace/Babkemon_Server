// field_snapshot_packet.h
#ifndef MGG_BABKEMON_FIELD_FIELD_SNAPSHOT_PACKET_H_
#define MGG_BABKEMON_FIELD_FIELD_SNAPSHOT_PACKET_H_

#include "..\..\utility\ivector2.h"

#include "logger\logger.h"

#include <ProudNetServer.h>

namespace mgg {

namespace babkemon {

namespace field {

struct EntityPacket {

  int entity_id;
  IVector2 position;

  EntityPacket() : position(0, 0) {}
};

struct FieldSnapshotPacket {

  std::vector<EntityPacket> entity_packets;

};

}

}

}

namespace Proud {

inline CMessage& operator >> (CMessage& a, mgg::babkemon::field::FieldSnapshotPacket& packet) {
  return a;
}

inline CMessage& operator << (CMessage& a, const mgg::babkemon::field::FieldSnapshotPacket& packet) {
  a << (int32_t)packet.entity_packets.size();
  for (int i = 0; i < packet.entity_packets.size(); i++) {
    auto emp = packet.entity_packets[i];
    L_DEBUG << "SNPSHOAT " << emp.entity_id << " " << emp.position;
    a << emp.entity_id << emp.position;
  }
  return a;
}

inline void AppendTextOut(String& str, const mgg::babkemon::field::FieldSnapshotPacket& packet) {

}

}

#endif