﻿




// Generated by PIDL compiler.
// Do not modify this file, but modify the source .pidl file.

using System;
using System.Net;

namespace common_c2s
{
	internal class Proxy:Nettention.Proud.RmiProxy
	{
public bool null_cmd(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext)
{
	Nettention.Proud.Message __msg=new Nettention.Proud.Message();
		__msg.SimplePacketMode = core.IsSimplePacketMode();
		Nettention.Proud.RmiID __msgid= Common.null_cmd;
		__msg.Write(__msgid);
		
	Nettention.Proud.HostID[] __list = new Nettention.Proud.HostID[1];
	__list[0] = remote;
		
	return RmiSend(__list,rmiContext,__msg,
		RmiName_null_cmd, Common.null_cmd);
}

public bool null_cmd(Nettention.Proud.HostID[] remotes,Nettention.Proud.RmiContext rmiContext)
{
	Nettention.Proud.Message __msg=new Nettention.Proud.Message();
__msg.SimplePacketMode = core.IsSimplePacketMode();
Nettention.Proud.RmiID __msgid= Common.null_cmd;
__msg.Write(__msgid);
		
	return RmiSend(remotes,rmiContext,__msg,
		RmiName_null_cmd, Common.null_cmd);
}
#if USE_RMI_NAME_STRING
// RMI name declaration.
// It is the unique pointer that indicates RMI name such as RMI profiler.
const string RmiName_null_cmd="null_cmd";
       
const string RmiName_First = RmiName_null_cmd;
#else
// RMI name declaration.
// It is the unique pointer that indicates RMI name such as RMI profiler.
const string RmiName_null_cmd="";
       
const string RmiName_First = "";
#endif
		public override Nettention.Proud.RmiID[] GetRmiIDList() { return Common.RmiIDList; } 
	}
}

