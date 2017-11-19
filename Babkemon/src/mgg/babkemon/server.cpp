// server.cpp
#include "server.h"

#include "logger\logger.h"

#include "player.h"
#include "inventory.h"

#include "pidl\common_pidl.h"
#include "pidl\battle_pidl.h"
#include "pidl\field_pidl.h"

#include "field\field_manager.h"
#include "battle\battle_manager.h"

#include "common\item_factory.h"
#include "common\babkemon\skill_factory.h"
#include "common\babkemon_factory.h"

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

    pidl::CommonPIDL::instance().AttachProxy(server_);
    pidl::CommonPIDL::instance().AttachStub(server_);
    pidl::BattlePIDL::instance().AttachProxy(server_);
    pidl::BattlePIDL::instance().AttachStub(server_);
    pidl::FieldPIDL::instance().AttachProxy(server_);
    pidl::FieldPIDL::instance().AttachStub(server_);

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
  auto lock = unique_lock();
  Player* player = new Player((PlayerID)client_info->m_HostID, client_info->m_HostID);
  assert(!players_.count((PlayerID)client_info->m_HostID));
  players_[(PlayerID)client_info->m_HostID] = player;
  L_DEBUG << "Client joined. " << player->id();
  pidl::CommonPIDL::instance().ProxyWelcome(player);
  field::FieldManager::instance()->SetPlayerField(player, 0);

  auto booty = ItemFactory::CreateItem(ItemType::SMALL_POSION);
  player->inventory()->AddItem(booty);

  auto slime = BabkemonFactory::Create(BabkemonType::SLIME);
  auto skill = babkemon::SkillFactory::Create(slime, babkemon::SkillType::BODY_SLAM);
  slime->AddSkill(skill);
  player->AddBabkemon(slime);
}

void Server::OnClientLeave(Proud::CNetClientInfo* client_info, Proud::ErrorInfo* error_info, const Proud::ByteArray& comment) {
  auto lock = unique_lock();
  // Server locked
  // No other threads can access players
  assert(players_.count((PlayerID)client_info->m_HostID));
  auto player = players_[(PlayerID)client_info->m_HostID];
  // Wait for other thread to finish a player locked job if any
  player->Lock();
  player->Unlock();
  // Player jobs are finished
  // Since Any thread which wants to access the player should lock Server first,
  // In this phase, no other threads can access this player.
  field::FieldManager::instance()->ClearPlayerField(player);
  players_.erase((PlayerID)client_info->m_HostID);
  delete player;

  // TODO : Much more cleanups

  // Server unlocked
  // Now other threads can access players
  // Try to access this player returns nullptr
  L_DEBUG << "Client leaved. " << client_info->m_HostID;
}

void Server::OnClientOffline(Proud::CRemoteOfflineEventArgs& args) {

}

void Server::OnClientOnline(Proud::CRemoteOnlineEventArgs& args) {

}

std::pair<Player* const, std::unique_lock<std::mutex>> Server::GetLockedPlayer(PlayerID id) {
  auto lock = unique_lock();
  auto player = players_[id];
  return{ players_[id], std::move(std::unique_lock<std::mutex>(player->mutex())) };
}

}

}