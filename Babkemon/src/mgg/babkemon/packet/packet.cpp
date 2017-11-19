// packet.cpp
#include "packet.h"

namespace mgg {

namespace babkemon {

void Packet::AppendInt32(int32_t val) {
  bytes_.push_back((val) & 0xFF);
  bytes_.push_back((val >> 8) & 0xFF);
  bytes_.push_back((val >> 16) & 0xFF);
  bytes_.push_back((val >> 24) & 0xFF);
}

void Packet::AppendUint32(uint32_t val) {
  bytes_.push_back((val) & 0xFF);
  bytes_.push_back((val >> 8) & 0xFF);
  bytes_.push_back((val >> 16) & 0xFF);
  bytes_.push_back((val >> 24) & 0xFF);
}

void Packet::AppendInt8(int8_t val) {
  bytes_.push_back((val) & 0xFF);
}

void Packet::AppendUint8(uint8_t val) {
  bytes_.push_back((val) & 0xFF);
}

void Packet::AppendBool(bool val) {
  if (val) bytes_.push_back(1);
  else bytes_.push_back(0);
}


}

}