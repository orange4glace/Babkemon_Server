// ivector2.h
#ifndef MGG_BABKEMON_IVECTOR2_H_
#define MGG_BABKEMON_IVECTOR2_H_

namespace mgg {

namespace babkemon {

class IVector2 {

  int x_, y_;

public:
  inline int x() const {
    return x_;
 }
  inline int y() const {
    return y_;
  }
  inline void x(int val) {
    x_ = val;
  }
  inline void y(int val) {
    y_ = val;
  }


};

}

}

#endif