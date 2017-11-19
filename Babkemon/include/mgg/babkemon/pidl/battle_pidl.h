// battle_pidl.h
#ifndef MGG_BABKEMON_PIDL_BATTLE_PIDL_H_
#define MGG_BABKEMON_PIDL_BATTLE_PIDL_H_

#include "pidl.h"

#include "..\battle\battle.h"
#include "..\battle\packet\entity_spawn_packet.h"
#include "..\battle\packet\battle_info_packet.h"
#include "..\battle\packet\skill_command_packet.h"
#include "..\battle\packet\item_command_packet.h"

#include "..\common\packet\skill_battle_cast_packet.h"

#include "..\..\..\pidl\battle_s2c_common.h"
#include "..\..\..\pidl\battle_s2c_proxy.h"
#include "..\..\..\pidl\battle_c2s_common.h"
#include "..\..\..\pidl\battle_c2s_stub.h"

namespace mgg {

namespace babkemon {

namespace pidl {

class BattlePIDL : public PIDL<class BattlePIDL, battle_s2c::Proxy, battle_c2s::StubFunctional> {

protected:
  void _SetStubs() override;

public:

  void ProxyBattleInfo(
    ::mgg::babkemon::battle::Battle* const battle,
    ::mgg::babkemon::battle::BattleInfoPacket& const packet);
  void ProxySetCooldown(
    ::mgg::babkemon::battle::Battle* const battle,
    ::mgg::babkemon::battle::Entity* const entity,
    int cooldown);
  void ProxySpawnEntity(
    ::mgg::babkemon::battle::Battle* const battle,
    PlayerID battle_player_id,
    const ::mgg::babkemon::battle::EntitySpawnPacket& packet);
  void ProxyCastSkill(
    ::mgg::babkemon::battle::Battle* const battle,
    ::mgg::babkemon::battle::Entity* const entity,
    ::mgg::babkemon::packet::SkillBattleCastPacket& const packet);
  void ProxyTurn(
    ::mgg::babkemon::battle::Battle* const battle);
  void ProxyBattleEnd(
    ::mgg::babkemon::Player* const player);
  void ProxyBattleWin(
    ::mgg::babkemon::Player* const player);
  void ProxyBattleLose(
    ::mgg::babkemon::Player* const player);

  bool StubSpawnEntity(::Proud::HostID remote, ::Proud::RmiContext& rmiContext, const int& entity_id);
  bool StubSkillCommand(::Proud::HostID remote, ::Proud::RmiContext& rmiContext,
    const int& entity_id,
    const ::mgg::babkemon::battle::SkillCommandPacket& packet);
  bool StubItemCommand(::Proud::HostID remote, ::Proud::RmiContext& rmiContext,
    const int& entity_id,
    const ::mgg::babkemon::battle::ItemCommandPacket& packet);
};

}

}

}

#endif