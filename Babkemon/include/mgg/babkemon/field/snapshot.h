// snapshot.h
#ifndef MGG_BABKEMON_FIELD_FIELD_SNAPSHOT_H_
#define MGG_BABKEMON_FIELD_FIELD_SNAPSHOT_H_

#include <ProudNetServer.h>

#include "field.h"

namespace mgg {

namespace babkemon {

namespace field {

struct Snapshot {

};

}

}

}

namespace Proud {

inline CMessage& operator >> (CMessage& a, mgg::babkemon::field::Snapshot& packet) {
  return a;
}

inline CMessage& operator << (CMessage& a, const mgg::babkemon::field::Snapshot& packet) {
  return a;
}

inline void AppendTextOut(String& str, const mgg::babkemon::field::Snapshot& packet) {

}

}

#endif