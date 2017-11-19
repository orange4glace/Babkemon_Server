// body_slam.cpp
#include "common\babkemon\skill\body_slam.h"

#include "common\packet\skill_battle_cast_packet.h"

#include "battle\battle.h"

namespace mgg {

namespace babkemon {

namespace babkemon {

namespace skill {

BodySlam::BodySlam(Babkemon* const babkemon) :
  Skill(SkillType::BODY_SLAM, babkemon) {

}

SkillCastResult BodySlam::Cast(battle::Entity* const entity) {
  battle::Battle* const battle = entity->battle();
  entity->set_hp(entity->hp() - 1);

  auto packet = new packet::SingleTargetSkillBattleCastPacket(type(), entity->babkemon()->id(), 5);
  return SkillCastResult(packet);
}

/*
BattleCastResult BodySlam::Cast(battle::Entity* const entity) {
  battle::Battle* const battle = entity->battle();
  battle::Entity* entity = entity_->battle()->GetEntity(target_entity_id_);
  assert(entity != nullptr);
  entity->set_hp(entity->hp() - 1);

  packet_ = battle::BodySlamCastPacket();
  packet_.entity_id = target_entity_id_;
  packet_.damage = 1;

  L_DEBUG << "[BodySlam] Casted from " << entity_->id() << " to " << entity->id();
  return packet_;
}
*/

}

}

}

}