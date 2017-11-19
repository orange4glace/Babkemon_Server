#pragma once

namespace battle_c2s {


	//Message ID that replies to each RMI method. 
               
    static const ::Proud::RmiID Rmi_SpawnEntity = (::Proud::RmiID)(2100+1);
               
    static const ::Proud::RmiID Rmi_SkillCommand = (::Proud::RmiID)(2100+2);
               
    static const ::Proud::RmiID Rmi_ItemCommand = (::Proud::RmiID)(2100+3);

	// List that has RMI ID.
	extern ::Proud::RmiID g_RmiIDList[];
	// RmiID List Count
	extern int g_RmiIDListCount;

}


 
