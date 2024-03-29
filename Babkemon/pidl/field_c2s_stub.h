﻿  






// Generated by PIDL compiler.
// Do not modify this file, but modify the source .pidl file.
   
#pragma once


#include "field_c2s_common.h"

     
namespace field_c2s {


	class Stub : public ::Proud::IRmiStub
	{
	public:
               
		virtual bool MoveCharacter ( ::Proud::HostID, ::Proud::RmiContext& , const mgg::babkemon::field::CharacterMovePacket  & )		{ 
			return false;
		} 

#define DECRMI_field_c2s_MoveCharacter bool MoveCharacter ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const mgg::babkemon::field::CharacterMovePacket  & packet) PN_OVERRIDE

#define DEFRMI_field_c2s_MoveCharacter(DerivedClass) bool DerivedClass::MoveCharacter ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const mgg::babkemon::field::CharacterMovePacket  & packet)
#define CALL_field_c2s_MoveCharacter MoveCharacter ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const mgg::babkemon::field::CharacterMovePacket  & packet)
#define PARAM_field_c2s_MoveCharacter ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const mgg::babkemon::field::CharacterMovePacket  & packet)
 
		virtual bool ProcessReceivedMessage(::Proud::CReceivedMessage &pa, void* hostTag) PN_OVERRIDE;
		static const PNTCHAR* RmiName_MoveCharacter;
		static const PNTCHAR* RmiName_First;
		virtual ::Proud::RmiID* GetRmiIDList() PN_OVERRIDE { return g_RmiIDList; }
		virtual int GetRmiIDListCount() PN_OVERRIDE { return g_RmiIDListCount; }
	};

#ifdef SUPPORTS_CPP11 
	
	class StubFunctional : public Stub 
	{
	public:
               
		std::function< bool ( ::Proud::HostID, ::Proud::RmiContext& , const mgg::babkemon::field::CharacterMovePacket  & ) > MoveCharacter_Function;
		virtual bool MoveCharacter ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const mgg::babkemon::field::CharacterMovePacket  & packet) 
		{ 
			if (MoveCharacter_Function==nullptr) 
				return true; 
			return MoveCharacter_Function(remote,rmiContext, packet); 
		}

	};
#endif

}


