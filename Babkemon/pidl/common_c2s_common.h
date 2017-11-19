#pragma once

namespace common_c2s {


	//Message ID that replies to each RMI method. 
               
    static const ::Proud::RmiID Rmi_null_cmd = (::Proud::RmiID)(2500+1);

	// List that has RMI ID.
	extern ::Proud::RmiID g_RmiIDList[];
	// RmiID List Count
	extern int g_RmiIDListCount;

}


 
