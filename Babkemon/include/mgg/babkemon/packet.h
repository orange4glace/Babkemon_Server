// packet.h
#ifndef MGG_BABKEMON_PACKET_H_
#define MGG_BABKEMON_PACKET_H_

#include <vector>
#include <stdint.h>

#include <ProudNetServer.h>

namespace mgg {

namespace babkemon {

class Packet {

  std::vector<int8_t> bytes_;

public:
  void AppendInt32(int32_t val);
  void AppendUint32(uint32_t val);
  void AppendBool(bool val);
  void AppendInt8(int8_t val);
  void AppendUint8(uint8_t val);

};

}

}

namespace Proud {

inline CMessage& operator >> (CMessage& a, mgg::babkemon::Packet& packet) {
  return a;
}

inline CMessage& operator << (CMessage& a, const mgg::babkemon::Packet& packet) {
  return a;
}

inline void AppendTextOut(String& str, const mgg::babkemon::Packet& packet) {

}

}

#endif