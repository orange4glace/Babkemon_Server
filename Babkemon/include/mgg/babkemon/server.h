// server.h
#ifndef MGG_BABKEMON_SERVER_H_
#define MGG_BABKEMON_SERVER_H_

#include <ProudNetServer.h>

#include "logger\logger.h"

#include "utility\lockable.h"
#include "player.h"

#include "field\snapshot.h"

#include <map>
#include <mutex>

namespace mgg {

namespace babkemon {

class Server : public Proud::INetServerEvent, public Lockable {

  static Server* instance_;

  Proud::CNetServer* server_;

  std::map<PlayerID, Player*> players_;

  Server();
  void initialize();

public:
  static void Initialize();
  inline static Server* const instance() {
    return instance_;
  }

  bool OnConnectionRequest(Proud::AddrPort client_addr, Proud::ByteArray& data, Proud::ByteArray& reply) override;
  void OnClientJoin(Proud::CNetClientInfo* client_info) override;
  void OnClientLeave(Proud::CNetClientInfo* client_info, Proud::ErrorInfo* error_info, const Proud::ByteArray& comment) override;
  void OnClientOffline(Proud::CRemoteOfflineEventArgs& args) override;
  void OnClientOnline(Proud::CRemoteOnlineEventArgs& args) override;

  // Not used
  void OnP2PGroupJoinMemberAckComplete(Proud::HostID group_host_id, Proud::HostID member_host_id, Proud::ErrorType result) override {}
  void OnUserWorkerThreadBegin() override {}
  void OnUserWorkerThreadEnd() override {}
  void OnClientHackSuspected(Proud::HostID client_id, Proud::HackType hack_type) override {}
  void OnP2PGroupRemoved(Proud::HostID group_id) override {}

  void OnError(Proud::ErrorInfo* e) override {
    L_DEBUG_W << "Proud Error " << e->ToString().c_str() << endl;
  }
  void OnWarning(Proud::ErrorInfo* e) override {
    L_DEBUG_W << "Proud Warning " << e->ToString().c_str() << endl;
  }
  void OnInformation(Proud::ErrorInfo* e) override {
    L_DEBUG_W << "Proud Info " << e->ToString().c_str() << endl;
  }
  void OnException(const Proud::Exception& e) override {
    L_DEBUG << e.what() << endl;
  }
  void OnNoRmiProcessed(Proud::RmiID rmiID) override {
    L_DEBUG << "No RMI";
  }

  std::pair<Player* const, std::unique_lock<std::mutex>> GetLockedPlayer(PlayerID id);

  
};

}

}

#endif