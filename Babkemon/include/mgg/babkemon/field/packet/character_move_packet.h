// character_move_packet.h
#ifndef MGG_BABKEMON_FIELD_CHARACTER_MOVE_PACKET_H_
#define MGG_BABKEMON_FIELD_CHARACTER_MOVE_PACKET_H_

#include "..\..\utility\ivector2.h"

#include <ProudNetServer.h>

namespace mgg {

namespace babkemon {

namespace field {

struct CharacterMovePacket {

  std::vector<int> dirs;

};

}

}

}

namespace Proud {

inline CMessage& operator >> (CMessage& a, mgg::babkemon::field::CharacterMovePacket& packet) {
  int size;
  a >> size;
  for (int i = 0; i < size; i++) {
    int dir;
    a >> dir;
    packet.dirs.push_back(dir);
  }
  return a;
}

inline CMessage& operator << (CMessage& a, const mgg::babkemon::field::CharacterMovePacket& packet) {
  return a;
}

inline void AppendTextOut(String& str, const mgg::babkemon::field::CharacterMovePacket& packet) {

}

}

#endif