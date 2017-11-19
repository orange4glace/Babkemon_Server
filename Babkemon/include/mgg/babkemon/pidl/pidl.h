// pidl.h
#ifndef MGG_BABKEMON_PIDL_PIDL_H_
#define MGG_BABKEMON_PIDL_PIDL_H_

#include <ProudNetServer.h>

namespace mgg {

namespace babkemon {

namespace pidl {

template <class Self, class Proxy, class Stub>
class PIDL {
  static Self instance_;

protected:
  Proxy proxy_;
  Stub stub_;

  virtual void _SetStubs() {}

public:
  static Self& instance() {
    return instance_;
  }

  void AttachProxy(Proud::CNetServer* server) {
    server->AttachProxy(&proxy_);
  }

  void AttachStub(Proud::CNetServer* server) {
    _SetStubs();
    server->AttachStub(&stub_);
  }

};

template <class Self, class Proxy, class Stub>
Self PIDL<Self, Proxy, Stub>::instance_;

}

}

}

#endif