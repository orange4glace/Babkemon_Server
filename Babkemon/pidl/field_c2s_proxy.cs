﻿




// Generated by PIDL compiler.
// Do not modify this file, but modify the source .pidl file.

using System;
using System.Net;

namespace field_c2s
{
	internal class Proxy:Nettention.Proud.RmiProxy
	{
public bool MoveCharacter(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, mgg.babkemon.field.CharacterMovePacket packet)
{
	Nettention.Proud.Message __msg=new Nettention.Proud.Message();
		__msg.SimplePacketMode = core.IsSimplePacketMode();
		Nettention.Proud.RmiID __msgid= Common.MoveCharacter;
		__msg.Write(__msgid);
		mgg.babkemon.network.Marshaler.Write(__msg, packet);
		
	Nettention.Proud.HostID[] __list = new Nettention.Proud.HostID[1];
	__list[0] = remote;
		
	return RmiSend(__list,rmiContext,__msg,
		RmiName_MoveCharacter, Common.MoveCharacter);
}

public bool MoveCharacter(Nettention.Proud.HostID[] remotes,Nettention.Proud.RmiContext rmiContext, mgg.babkemon.field.CharacterMovePacket packet)
{
	Nettention.Proud.Message __msg=new Nettention.Proud.Message();
__msg.SimplePacketMode = core.IsSimplePacketMode();
Nettention.Proud.RmiID __msgid= Common.MoveCharacter;
__msg.Write(__msgid);
mgg.babkemon.network.Marshaler.Write(__msg, packet);
		
	return RmiSend(remotes,rmiContext,__msg,
		RmiName_MoveCharacter, Common.MoveCharacter);
}
#if USE_RMI_NAME_STRING
// RMI name declaration.
// It is the unique pointer that indicates RMI name such as RMI profiler.
const string RmiName_MoveCharacter="MoveCharacter";
       
const string RmiName_First = RmiName_MoveCharacter;
#else
// RMI name declaration.
// It is the unique pointer that indicates RMI name such as RMI profiler.
const string RmiName_MoveCharacter="";
       
const string RmiName_First = "";
#endif
		public override Nettention.Proud.RmiID[] GetRmiIDList() { return Common.RmiIDList; } 
	}
}

