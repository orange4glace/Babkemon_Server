// common_pidl.h
#ifndef MGG_BABKEMON_PIDL_COMMON_PIDL_H_
#define MGG_BABKEMON_PIDL_COMMON_PIDL_H_

#include "pidl.h"

#include "..\player.h"

#include "..\battle\battle.h"
#include "..\field\field.h"
#include "..\common\item\item_packet.h"
#include "..\common\packet\babkemon_packet.h"
#include "..\..\..\pidl\common_s2c_common.h"
#include "..\..\..\pidl\common_s2c_proxy.h"
#include "..\..\..\pidl\common_c2s_common.h"
#include "..\..\..\pidl\common_c2s_stub.h"

namespace mgg {

namespace babkemon {

namespace pidl {

class CommonPIDL : public PIDL<class CommonPIDL, common_s2c::Proxy, common_c2s::StubFunctional> {

protected:
  void _SetStubs() override;

public:
  void ProxyWelcome(
    Player* const player);

  void ProxyEnterBattle(
    Player* const player,
    ::mgg::babkemon::battle::Battle* const battle);

  void ProxyEnterField(
    Player* const player,
    ::mgg::babkemon::field::Field* const field);

  void ProxyAddBabkemon(
    Player* const player,
    packet::BabkemonPacket& packet);

  void ProxyAddItem(
    Player* const player,
    item::ItemPacket& packet);

  void ProxyRemoveItem(
    Player* const player,
    int item_id);

  void ProxySetItemAmount(
    Player* const player,
    int item_id,
    int amount);

};

}

}

}

#endif