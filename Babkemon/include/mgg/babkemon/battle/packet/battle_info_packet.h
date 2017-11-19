// battle_info_packet.h
#ifndef MGG_BABKEMON_BATTLE_BATTLE_INFO_PACKET_H_
#define MGG_BABKEMON_BATTLE_BATTLE_INFO_PACKET_H_

#include <ProudNetServer.h>

#include "..\battle_player.h"
#include "..\..\logger\logger.h"

#include <vector>
#include <stdint.h>

namespace mgg {

namespace babkemon {

namespace battle {

struct BattleInfoPacket {
  BattleType type;
  std::vector<BattlePlayer*> battle_players;
};

}

}

}

namespace Proud {

inline CMessage& operator >> (CMessage& a, mgg::babkemon::battle::BattleInfoPacket& packet) {
  return a;
}

inline CMessage& operator << (CMessage& a, const mgg::babkemon::battle::BattleInfoPacket& packet) {
  a << (int)(packet.type == mgg::babkemon::battle::BattleType::PVE ? 0 : 1);
  a << (int32_t)packet.battle_players.size();
  for (auto battle_player : packet.battle_players) {
    a << battle_player->id();
    L_DEBUG << "id="<< battle_player->id();
  }
  return a;
}

inline void AppendTextOut(String& str, const mgg::babkemon::battle::BattleInfoPacket& packet) {

}

}

#endif