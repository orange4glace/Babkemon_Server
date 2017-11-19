// field_pidl.h
#ifndef MGG_BABKEMON_PIDL_FIELD_PIDL_H_
#define MGG_BABKEMON_PIDL_FIELD_PIDL_H_

#include "pidl.h"

#include "..\player.h"
#include "..\field\field.h"
#include "..\field\packet\field_snapshot_packet.h"
#include "..\field\packet\entity_spawn_packet.h"
#include "..\field\packet\character_move_packet.h"

#include "..\..\..\pidl\field_s2c_common.h"
#include "..\..\..\pidl\field_s2c_proxy.h"
#include "..\..\..\pidl\field_c2s_common.h"
#include "..\..\..\pidl\field_c2s_stub.h"

namespace mgg {

namespace babkemon {

namespace pidl {

class FieldPIDL : public PIDL<class FieldPIDL, field_s2c::Proxy, field_c2s::StubFunctional> {

protected:
  void _SetStubs() override;

public:

  void ProxySnapshot(::mgg::babkemon::field::Field* const field, const ::mgg::babkemon::field::FieldSnapshotPacket& const packet);
  void ProxySpawnEntity(
    ::mgg::babkemon::field::Field* const field,
    const ::mgg::babkemon::field::EntitySpawnPacket& packet);
  void ProxyDespawnEntity(
    ::mgg::babkemon::field::Field* const field,
    int entity_id);

  bool StubMoveCharacter(::Proud::HostID remote, ::Proud::RmiContext& rmiContext,
    const ::mgg::babkemon::field::CharacterMovePacket& packet);

};

}

}

}

#endif