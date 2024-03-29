﻿




// Generated by PIDL compiler.
// Do not modify this file, but modify the source .pidl file.

using System;
using System.Net;	     

namespace field_c2s
{
	internal class Stub:Nettention.Proud.RmiStub
	{
public AfterRmiInvocationDelegate AfterRmiInvocation = delegate(Nettention.Proud.AfterRmiSummary summary) {};
public BeforeRmiInvocationDelegate BeforeRmiInvocation = delegate(Nettention.Proud.BeforeRmiSummary summary) {};

		public delegate bool MoveCharacterDelegate(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, mgg.babkemon.field.CharacterMovePacket packet);  
		public MoveCharacterDelegate MoveCharacter = delegate(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, mgg.babkemon.field.CharacterMovePacket packet)
		{ 
			return false;
		};
	public override bool ProcessReceivedMessage(Nettention.Proud.ReceivedMessage pa, Object hostTag) 
	{
		Nettention.Proud.HostID remote=pa.RemoteHostID;
		if(remote==Nettention.Proud.HostID.HostID_None)
		{
			ShowUnknownHostIDWarning(remote);
		}

		Nettention.Proud.Message __msg=pa.ReadOnlyMessage;
		int orgReadOffset = __msg.ReadOffset;
        Nettention.Proud.RmiID __rmiID = Nettention.Proud.RmiID.RmiID_None;
        if (!__msg.Read( out __rmiID))
            goto __fail;
					
		switch(__rmiID)
		{
case Common.MoveCharacter:
	{
		Nettention.Proud.RmiContext ctx=new Nettention.Proud.RmiContext();
		ctx.sentFrom=pa.RemoteHostID;
		ctx.relayed=pa.IsRelayed;
		ctx.hostTag=hostTag;
		ctx.encryptMode = pa.EncryptMode;
		ctx.compressMode = pa.CompressMode;
			
		mgg.babkemon.field.CharacterMovePacket packet; mgg.babkemon.network.Marshaler.Read(__msg,out packet);	
core.PostCheckReadMessage(__msg, RmiName_MoveCharacter);
		if(enableNotifyCallFromStub==true)
		{
			string parameterString="";
			parameterString+=packet.ToString()+",";
			NotifyCallFromStub(Common.MoveCharacter, RmiName_MoveCharacter,parameterString);
		}
			
		if(enableStubProfiling)
		{
			Nettention.Proud.BeforeRmiSummary summary = new Nettention.Proud.BeforeRmiSummary();
			summary.rmiID = Common.MoveCharacter;
			summary.rmiName = RmiName_MoveCharacter;
			summary.hostID = remote;
			summary.hostTag = hostTag;
			BeforeRmiInvocation(summary);
		}
			
		long t0 = Nettention.Proud.PreciseCurrentTime.GetTimeMs();
			
		// Call this method.
		bool __ret=MoveCharacter (remote,ctx , packet );
			
		if(__ret==false)
		{
			// Error: RMI function that a user did not create has been called. 
			core.ShowNotImplementedRmiWarning(RmiName_MoveCharacter);
		}
			
		if(enableStubProfiling)
		{
			Nettention.Proud.AfterRmiSummary summary = new Nettention.Proud.AfterRmiSummary();
			summary.rmiID = Common.MoveCharacter;
			summary.rmiName = RmiName_MoveCharacter;
			summary.hostID = remote;
			summary.hostTag = hostTag;
			summary.elapsedTime = Nettention.Proud.PreciseCurrentTime.GetTimeMs()-t0;
			AfterRmiInvocation(summary);
		}
	}
	break;
		default:
			 goto __fail;
		}
		return true;
__fail:
	  {
			__msg.ReadOffset = orgReadOffset;
			return false;
	  }
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
		public override Nettention.Proud.RmiID[] GetRmiIDList { get{return Common.RmiIDList;} }
		
	}
}

