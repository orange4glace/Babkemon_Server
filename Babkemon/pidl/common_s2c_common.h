#pragma once

namespace common_s2c {


	//Message ID that replies to each RMI method. 
               
    static const ::Proud::RmiID Rmi_Welcome = (::Proud::RmiID)(2400+1);
               
    static const ::Proud::RmiID Rmi_EnterBattle = (::Proud::RmiID)(2400+2);
               
    static const ::Proud::RmiID Rmi_EnterField = (::Proud::RmiID)(2400+3);
               
    static const ::Proud::RmiID Rmi_AddItem = (::Proud::RmiID)(2400+4);
               
    static const ::Proud::RmiID Rmi_RemoveItem = (::Proud::RmiID)(2400+5);
               
    static const ::Proud::RmiID Rmi_SetItemAmount = (::Proud::RmiID)(2400+6);
               
    static const ::Proud::RmiID Rmi_AddBabkemon = (::Proud::RmiID)(2400+7);

	// List that has RMI ID.
	extern ::Proud::RmiID g_RmiIDList[];
	// RmiID List Count
	extern int g_RmiIDListCount;

}


 
