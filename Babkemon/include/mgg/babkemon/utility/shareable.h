// shareable.h
#ifndef MGG_BABKEMON_SHAREABLE_H_
#define MGG_BABKEMON_SHAREABLE_H_

#include "lockable.h"

#include <memory>

namespace mgg {

namespace babkemon {

#ifdef likely
#define lock_share(shareable_shared_ptr) \
  [&]() {\
    shareable_shared_ptr->unique_lock();\
    bool destroied = shareable_shared_ptr->destroied();\
    if (likely(!destroied)) 
#else
#define lock_share(shareable_shared_ptr) \
  [&]() {\
    shareable_shared_ptr->unique_lock();\
    bool destroied = shareable_shared_ptr->destroied();\
    if (!destroied)
#endif
#define unlock_share(shareable_shared_ptr) \
    return !destroied;\
  }();

class Shareable : public Lockable {

  std::shared_ptr<Shareable> shared_ptr_;
  bool shareable_destroied_;

  virtual void destroy() = 0;

public:
  inline Shareable() :
    shared_ptr_(this),
    shareable_destroied_(false) {
  }

  inline std::shared_ptr<Shareable> copy_shared_ptr() {
    return shared_ptr_;
  }

  inline void ref_shared_ptr(std::shared_ptr<Shareable>& ptr) {
    ptr = shared_ptr_;
  }

  inline bool destroied() const {
    return shareable_destroied_;
  }

  inline void Destroy() {
    Lock();
    assert(!shareable_destroied_);
    destroy();
    shareable_destroied_ = true;
    Unlock();
    shared_ptr_.reset();
  }

};

}

}

#endif