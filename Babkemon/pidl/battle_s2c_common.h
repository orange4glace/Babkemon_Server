#pragma once

namespace battle_s2c {


	//Message ID that replies to each RMI method. 
               
    static const ::Proud::RmiID Rmi_SetCooldown = (::Proud::RmiID)(2000+1);
               
    static const ::Proud::RmiID Rmi_BattleInfo = (::Proud::RmiID)(2000+2);
               
    static const ::Proud::RmiID Rmi_SpawnEntity = (::Proud::RmiID)(2000+3);
               
    static const ::Proud::RmiID Rmi_CastSkill = (::Proud::RmiID)(2000+4);
               
    static const ::Proud::RmiID Rmi_BattleEnd = (::Proud::RmiID)(2000+5);
               
    static const ::Proud::RmiID Rmi_BattleWin = (::Proud::RmiID)(2000+6);
               
    static const ::Proud::RmiID Rmi_BattleLose = (::Proud::RmiID)(2000+7);
               
    static const ::Proud::RmiID Rmi_Turn = (::Proud::RmiID)(2000+8);

	// List that has RMI ID.
	extern ::Proud::RmiID g_RmiIDList[];
	// RmiID List Count
	extern int g_RmiIDListCount;

}


 
