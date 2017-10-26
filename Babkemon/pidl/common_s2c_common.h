#pragma once

namespace common_s2c {


	//Message ID that replies to each RMI method. 
               
    static const ::Proud::RmiID Rmi_EnterBattle = (::Proud::RmiID)(100+1);
               
    static const ::Proud::RmiID Rmi_EnterField = (::Proud::RmiID)(100+2);

	// List that has RMI ID.
	extern ::Proud::RmiID g_RmiIDList[];
	// RmiID List Count
	extern int g_RmiIDListCount;

}


 
