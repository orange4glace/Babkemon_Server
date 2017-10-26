#pragma once

namespace field_s2c {


	//Message ID that replies to each RMI method. 
               
    static const ::Proud::RmiID Rmi_Snapshot = (::Proud::RmiID)(200+1);

	// List that has RMI ID.
	extern ::Proud::RmiID g_RmiIDList[];
	// RmiID List Count
	extern int g_RmiIDListCount;

}


 
