// server.cpp
#include "server.h"

#include "logger\logger.h"

#include "..\..\..\pidl\common_s2c_common.cpp"
#include "..\..\..\pidl\common_s2c_proxy.cpp"
#include "..\..\..\pidl\field_s2c_common.cpp"
#include "..\..\..\pidl\field_s2c_proxy.cpp"

#include "battle\battle_manager.h"

#include <cassert>
#include <iostream>

namespace mgg {

namespace babkemon {

Server* Server::instance_ = nullptr;

void Server::Initialize() {
  instance_ = new Server();
  instance_->initialize();
}

Server::Server() {
}

void Server::initialize() {
  server_ = Proud::CNetServer::Create();
  try {
    Proud::CStartServerParameter server_param;

    Proud::CThreadPoolEventFunctional e;

    Proud::PNGUID guid = { 0x3ae33249, 0xecc6, 0x4980,{ 0xbc, 0x5d, 0x7b, 0xa, 0x99, 0x9c, 0x07, 0x39 } };
    Proud::Guid g_Version = Proud::Guid(guid);
    server_param.m_protocolVersion = g_Version;
    server_param.m_tcpPorts.Add(33334);
    // server_param.m_localNicAddr = Proud::String("192.168.0.19");
    server_->SetEventSink(this);

    server_->AttachProxy(&common_s2c_proxy_);
    server_->AttachProxy(&field_s2c_proxy_);

    /* Starts the server.
    This function throws an exception on failure.
    Note: As we specify nothing for threading model,
    RMI function by message receive and event callbacks are
    called in a separate thread pool.
    You can change the thread model. Check out the help pages for details. */
    server_->Start(server_param);
  }
  catch (Proud::Exception &e) {
    cout << "Server start failed: " << e.what() << endl;
  }
  catch (exception e) {
    cout << e.what() << endl;
  }
}

bool Server::OnConnectionRequest(Proud::AddrPort client_addr, Proud::ByteArray& data, Proud::ByteArray& reply) {
  return true;
}

void Server::OnClientJoin(Proud::CNetClientInfo* client_info) {
  L_DEBUG << "Client joined.";
  Player* player = new Player((PlayerID)client_info->m_HostID, client_info->m_HostID);
  assert(!players_.count((PlayerID)client_info->m_HostID));
  players_[(PlayerID)client_info->m_HostID] = player;
  auto battle = battle::BattleManager::instance()->CreateBattle();
  battle::BattleManager::instance()->EnterPlayerBattle(player, battle);
}

void Server::OnClientLeave(Proud::CNetClientInfo* client_info, Proud::ErrorInfo* error_info, const Proud::ByteArray& comment) {
  L_DEBUG << "Client leaved.";
  assert(players_.count((PlayerID)client_info->m_HostID));
  players_.erase((PlayerID)client_info->m_HostID);
}

void Server::OnClientOffline(Proud::CRemoteOfflineEventArgs& args) {

}

void Server::OnClientOnline(Proud::CRemoteOnlineEventArgs& args) {

}

Player* const Server::GetPlayer(PlayerID id) {
  assert(players_.count(id));
  return players_[id];
}

void Server::ProxyEnterField(const Player* const player, int field_id) {
  common_s2c_proxy_.EnterField(player->host_id(), Proud::RmiContext::ReliableSend, field_id);
}

void Server::ProxyEnterBattle(const Player* const player, int battle_id) {
  common_s2c_proxy_.EnterBattle(player->host_id(), Proud::RmiContext::ReliableSend, battle_id);
}

}

}