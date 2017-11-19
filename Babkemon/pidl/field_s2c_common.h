#pragma once

namespace field_s2c {


	//Message ID that replies to each RMI method. 
               
    static const ::Proud::RmiID Rmi_Snapshot = (::Proud::RmiID)(2200+1);
               
    static const ::Proud::RmiID Rmi_SpawnEntity = (::Proud::RmiID)(2200+2);
               
    static const ::Proud::RmiID Rmi_DespawnEntity = (::Proud::RmiID)(2200+3);

	// List that has RMI ID.
	extern ::Proud::RmiID g_RmiIDList[];
	// RmiID List Count
	extern int g_RmiIDListCount;

}


 
