// babkemon_packet.h
#ifndef MGG_BABKEMON_BABKEMON_PACKET_H_
#define MGG_BABKEMON_BABKEMON_PACKET_H_

#include "..\babkemon.h"
#include "skill_packet.h"

#include <ProudNetServer.h>

namespace mgg {

namespace babkemon {

namespace packet {

struct BabkemonPacket {

  Babkemon* babkemon;

  BabkemonPacket(Babkemon* const babkemon) {
    this->babkemon = babkemon;
  }

};

}


}

}

namespace Proud {

inline CMessage& operator << (CMessage& a, const mgg::babkemon::packet::BabkemonPacket& packet) {
  auto babkemon = packet.babkemon;
  a << babkemon->id() << babkemon->type() << babkemon->skills_size();
  for (auto it = babkemon->skills_begin(); it != babkemon->skills_end(); it++) {
    auto skill = it->second;
    skill->Serialize(a);
  }
  return a;
}
inline void AppendTextOut(String& str, const mgg::babkemon::packet::BabkemonPacket& packet) {}

}

#endif