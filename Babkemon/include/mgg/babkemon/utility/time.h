// time.h
#ifndef MGG_BABKEMON_TIME_H_
#define MGG_BABKEMON_TIME_H_

#include "scheduler.h"
#include <boost/thread/mutex.hpp>

namespace mgg {

namespace babkemon {

using game_time = unsigned int;

class Time {

  static std::chrono::milliseconds last_captured_time_;
  static game_time current_time_;
  static boost::mutex mutex_;

public:

  inline static void Init() {
    last_captured_time_ = std::chrono::duration_cast< std::chrono::milliseconds >(
      std::chrono::system_clock::now().time_since_epoch()
    );
    Scheduler::instance()->interval(std::chrono::milliseconds(1), []()-> bool {
      std::chrono::milliseconds now = std::chrono::duration_cast< std::chrono::milliseconds >(
        std::chrono::system_clock::now().time_since_epoch()
      );
      unsigned int dt = (now - last_captured_time_).count();
      last_captured_time_ = now;
      mutex_.lock();
      current_time_ += dt;
      mutex_.unlock();
      return true;
    });
  }

  inline static game_time current_time() {
    mutex_.lock();
    game_time copied = current_time_;
    mutex_.unlock();
    return copied;
  }

};

}

}

#endif