#pragma once

namespace field_c2s {


	//Message ID that replies to each RMI method. 
               
    static const ::Proud::RmiID Rmi_MoveCharacter = (::Proud::RmiID)(2300+1);

	// List that has RMI ID.
	extern ::Proud::RmiID g_RmiIDList[];
	// RmiID List Count
	extern int g_RmiIDListCount;

}


 
