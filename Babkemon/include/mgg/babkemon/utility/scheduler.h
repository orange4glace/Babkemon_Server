// scheduler.h
#ifndef MGG_BABKEMON_SCHEDULER_H_
#define MGG_BABKEMON_SCHEDULER_H_

#include <chrono>
#include "..\..\external_lib\scheduler\Scheduler.h"

#define MS(milli) std::chrono::milliseconds(milli)

namespace mgg {

namespace babkemon {

class Scheduler {

  static Bosma::Scheduler* s_;

public:
  inline static void Init() {
    s_ = new Bosma::Scheduler(8);
  }

  inline static Bosma::Scheduler* instance() {
    return s_;
  }

};

}

}

#endif