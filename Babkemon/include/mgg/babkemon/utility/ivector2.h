// ivector2.h
#ifndef MGG_BABKEMON_IVECTOR2_H_
#define MGG_BABKEMON_IVECTOR2_H_

#include <iostream>

#include <ProudNetServer.h>

namespace mgg {

namespace babkemon {

class IVector2 {

  int x_, y_;

public:
  inline IVector2(int x, int y) :
    x_(x), y_(y) {
  }

  inline int x() const {
    return x_;
 }
  inline int y() const {
    return y_;
  }
  inline void set_x(int val) {
    x_ = val;
  }
  inline void set_y(int val) {
    y_ = val;
  }
  inline void set(const IVector2& val) {
    x_ = val.x();
    y_ = val.y();
  }
  inline void set(const IVector2&& val) {
    x_ = val.x();
    y_ = val.y();
  }

};

inline std::ostream& operator << (std::ostream& os, const IVector2& vec) {
  os << "(" << vec.x() << "," << vec.y() << ")";
  return os;
}

}

}

namespace Proud {

inline CMessage& operator >> (CMessage& a, mgg::babkemon::IVector2& val) {
  int x, y;
  a >> x >> y;
  val.set_x(x);
  val.set_y(y);
  return a;
}

inline CMessage& operator << (CMessage& a, const mgg::babkemon::IVector2& val) {
  a << val.x() << val.y();
  return a;
}

inline void AppendTextOut(String& str, const mgg::babkemon::IVector2& val) {

}

}

#endif