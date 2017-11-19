// lockable.h
#ifndef MGG_BABKEMON_LOCKABLE_H_
#define MGG_BABKEMON_LOCKABLE_H_

#include <mutex>

namespace mgg {

namespace babkemon {

using ulock = std::unique_lock<std::mutex>;
#define locked(A) std::pair<A* const, std::unique_lock<std::mutex>>

class Lockable {

  std::mutex mutex_;

public:
  inline void Lock() {
    mutex_.lock();
  }

  inline void Unlock() {
    mutex_.unlock();
  }
  inline void lock() {
    mutex_.lock();
  }

  inline void unlock() {
    mutex_.unlock();
  }

  inline std::mutex& mutex() {
    return mutex_;
  }

  inline std::unique_lock<std::mutex> unique_lock() {
    return std::move(std::unique_lock<std::mutex>(mutex_));
  }

};

}

}

#endif