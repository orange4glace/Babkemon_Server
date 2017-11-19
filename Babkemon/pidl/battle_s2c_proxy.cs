﻿




// Generated by PIDL compiler.
// Do not modify this file, but modify the source .pidl file.

using System;
using System.Net;

namespace battle_s2c
{
	internal class Proxy:Nettention.Proud.RmiProxy
	{
public bool SetCooldown(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, int id, int cooldown)
{
	Nettention.Proud.Message __msg=new Nettention.Proud.Message();
		__msg.SimplePacketMode = core.IsSimplePacketMode();
		Nettention.Proud.RmiID __msgid= Common.SetCooldown;
		__msg.Write(__msgid);
		mgg.babkemon.network.Marshaler.Write(__msg, id);
		mgg.babkemon.network.Marshaler.Write(__msg, cooldown);
		
	Nettention.Proud.HostID[] __list = new Nettention.Proud.HostID[1];
	__list[0] = remote;
		
	return RmiSend(__list,rmiContext,__msg,
		RmiName_SetCooldown, Common.SetCooldown);
}

public bool SetCooldown(Nettention.Proud.HostID[] remotes,Nettention.Proud.RmiContext rmiContext, int id, int cooldown)
{
	Nettention.Proud.Message __msg=new Nettention.Proud.Message();
__msg.SimplePacketMode = core.IsSimplePacketMode();
Nettention.Proud.RmiID __msgid= Common.SetCooldown;
__msg.Write(__msgid);
mgg.babkemon.network.Marshaler.Write(__msg, id);
mgg.babkemon.network.Marshaler.Write(__msg, cooldown);
		
	return RmiSend(remotes,rmiContext,__msg,
		RmiName_SetCooldown, Common.SetCooldown);
}
public bool BattleInfo(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, mgg.babkemon.battle.BattleInfoPacket battle_info)
{
	Nettention.Proud.Message __msg=new Nettention.Proud.Message();
		__msg.SimplePacketMode = core.IsSimplePacketMode();
		Nettention.Proud.RmiID __msgid= Common.BattleInfo;
		__msg.Write(__msgid);
		mgg.babkemon.network.Marshaler.Write(__msg, battle_info);
		
	Nettention.Proud.HostID[] __list = new Nettention.Proud.HostID[1];
	__list[0] = remote;
		
	return RmiSend(__list,rmiContext,__msg,
		RmiName_BattleInfo, Common.BattleInfo);
}

public bool BattleInfo(Nettention.Proud.HostID[] remotes,Nettention.Proud.RmiContext rmiContext, mgg.babkemon.battle.BattleInfoPacket battle_info)
{
	Nettention.Proud.Message __msg=new Nettention.Proud.Message();
__msg.SimplePacketMode = core.IsSimplePacketMode();
Nettention.Proud.RmiID __msgid= Common.BattleInfo;
__msg.Write(__msgid);
mgg.babkemon.network.Marshaler.Write(__msg, battle_info);
		
	return RmiSend(remotes,rmiContext,__msg,
		RmiName_BattleInfo, Common.BattleInfo);
}
public bool SpawnEntity(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, int battle_player_id, mgg.babkemon.battle.EntitySpawnPacket packet)
{
	Nettention.Proud.Message __msg=new Nettention.Proud.Message();
		__msg.SimplePacketMode = core.IsSimplePacketMode();
		Nettention.Proud.RmiID __msgid= Common.SpawnEntity;
		__msg.Write(__msgid);
		mgg.babkemon.network.Marshaler.Write(__msg, battle_player_id);
		mgg.babkemon.network.Marshaler.Write(__msg, packet);
		
	Nettention.Proud.HostID[] __list = new Nettention.Proud.HostID[1];
	__list[0] = remote;
		
	return RmiSend(__list,rmiContext,__msg,
		RmiName_SpawnEntity, Common.SpawnEntity);
}

public bool SpawnEntity(Nettention.Proud.HostID[] remotes,Nettention.Proud.RmiContext rmiContext, int battle_player_id, mgg.babkemon.battle.EntitySpawnPacket packet)
{
	Nettention.Proud.Message __msg=new Nettention.Proud.Message();
__msg.SimplePacketMode = core.IsSimplePacketMode();
Nettention.Proud.RmiID __msgid= Common.SpawnEntity;
__msg.Write(__msgid);
mgg.babkemon.network.Marshaler.Write(__msg, battle_player_id);
mgg.babkemon.network.Marshaler.Write(__msg, packet);
		
	return RmiSend(remotes,rmiContext,__msg,
		RmiName_SpawnEntity, Common.SpawnEntity);
}
public bool CastSkill(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, int entity_id, mgg.babkemon.packet.SkillBattleCastPacket packet)
{
	Nettention.Proud.Message __msg=new Nettention.Proud.Message();
		__msg.SimplePacketMode = core.IsSimplePacketMode();
		Nettention.Proud.RmiID __msgid= Common.CastSkill;
		__msg.Write(__msgid);
		mgg.babkemon.network.Marshaler.Write(__msg, entity_id);
		mgg.babkemon.network.Marshaler.Write(__msg, packet);
		
	Nettention.Proud.HostID[] __list = new Nettention.Proud.HostID[1];
	__list[0] = remote;
		
	return RmiSend(__list,rmiContext,__msg,
		RmiName_CastSkill, Common.CastSkill);
}

public bool CastSkill(Nettention.Proud.HostID[] remotes,Nettention.Proud.RmiContext rmiContext, int entity_id, mgg.babkemon.packet.SkillBattleCastPacket packet)
{
	Nettention.Proud.Message __msg=new Nettention.Proud.Message();
__msg.SimplePacketMode = core.IsSimplePacketMode();
Nettention.Proud.RmiID __msgid= Common.CastSkill;
__msg.Write(__msgid);
mgg.babkemon.network.Marshaler.Write(__msg, entity_id);
mgg.babkemon.network.Marshaler.Write(__msg, packet);
		
	return RmiSend(remotes,rmiContext,__msg,
		RmiName_CastSkill, Common.CastSkill);
}
public bool BattleEnd(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext)
{
	Nettention.Proud.Message __msg=new Nettention.Proud.Message();
		__msg.SimplePacketMode = core.IsSimplePacketMode();
		Nettention.Proud.RmiID __msgid= Common.BattleEnd;
		__msg.Write(__msgid);
		
	Nettention.Proud.HostID[] __list = new Nettention.Proud.HostID[1];
	__list[0] = remote;
		
	return RmiSend(__list,rmiContext,__msg,
		RmiName_BattleEnd, Common.BattleEnd);
}

public bool BattleEnd(Nettention.Proud.HostID[] remotes,Nettention.Proud.RmiContext rmiContext)
{
	Nettention.Proud.Message __msg=new Nettention.Proud.Message();
__msg.SimplePacketMode = core.IsSimplePacketMode();
Nettention.Proud.RmiID __msgid= Common.BattleEnd;
__msg.Write(__msgid);
		
	return RmiSend(remotes,rmiContext,__msg,
		RmiName_BattleEnd, Common.BattleEnd);
}
public bool BattleWin(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext)
{
	Nettention.Proud.Message __msg=new Nettention.Proud.Message();
		__msg.SimplePacketMode = core.IsSimplePacketMode();
		Nettention.Proud.RmiID __msgid= Common.BattleWin;
		__msg.Write(__msgid);
		
	Nettention.Proud.HostID[] __list = new Nettention.Proud.HostID[1];
	__list[0] = remote;
		
	return RmiSend(__list,rmiContext,__msg,
		RmiName_BattleWin, Common.BattleWin);
}

public bool BattleWin(Nettention.Proud.HostID[] remotes,Nettention.Proud.RmiContext rmiContext)
{
	Nettention.Proud.Message __msg=new Nettention.Proud.Message();
__msg.SimplePacketMode = core.IsSimplePacketMode();
Nettention.Proud.RmiID __msgid= Common.BattleWin;
__msg.Write(__msgid);
		
	return RmiSend(remotes,rmiContext,__msg,
		RmiName_BattleWin, Common.BattleWin);
}
public bool BattleLose(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext)
{
	Nettention.Proud.Message __msg=new Nettention.Proud.Message();
		__msg.SimplePacketMode = core.IsSimplePacketMode();
		Nettention.Proud.RmiID __msgid= Common.BattleLose;
		__msg.Write(__msgid);
		
	Nettention.Proud.HostID[] __list = new Nettention.Proud.HostID[1];
	__list[0] = remote;
		
	return RmiSend(__list,rmiContext,__msg,
		RmiName_BattleLose, Common.BattleLose);
}

public bool BattleLose(Nettention.Proud.HostID[] remotes,Nettention.Proud.RmiContext rmiContext)
{
	Nettention.Proud.Message __msg=new Nettention.Proud.Message();
__msg.SimplePacketMode = core.IsSimplePacketMode();
Nettention.Proud.RmiID __msgid= Common.BattleLose;
__msg.Write(__msgid);
		
	return RmiSend(remotes,rmiContext,__msg,
		RmiName_BattleLose, Common.BattleLose);
}
public bool Turn(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext)
{
	Nettention.Proud.Message __msg=new Nettention.Proud.Message();
		__msg.SimplePacketMode = core.IsSimplePacketMode();
		Nettention.Proud.RmiID __msgid= Common.Turn;
		__msg.Write(__msgid);
		
	Nettention.Proud.HostID[] __list = new Nettention.Proud.HostID[1];
	__list[0] = remote;
		
	return RmiSend(__list,rmiContext,__msg,
		RmiName_Turn, Common.Turn);
}

public bool Turn(Nettention.Proud.HostID[] remotes,Nettention.Proud.RmiContext rmiContext)
{
	Nettention.Proud.Message __msg=new Nettention.Proud.Message();
__msg.SimplePacketMode = core.IsSimplePacketMode();
Nettention.Proud.RmiID __msgid= Common.Turn;
__msg.Write(__msgid);
		
	return RmiSend(remotes,rmiContext,__msg,
		RmiName_Turn, Common.Turn);
}
#if USE_RMI_NAME_STRING
// RMI name declaration.
// It is the unique pointer that indicates RMI name such as RMI profiler.
const string RmiName_SetCooldown="SetCooldown";
const string RmiName_BattleInfo="BattleInfo";
const string RmiName_SpawnEntity="SpawnEntity";
const string RmiName_CastSkill="CastSkill";
const string RmiName_BattleEnd="BattleEnd";
const string RmiName_BattleWin="BattleWin";
const string RmiName_BattleLose="BattleLose";
const string RmiName_Turn="Turn";
       
const string RmiName_First = RmiName_SetCooldown;
#else
// RMI name declaration.
// It is the unique pointer that indicates RMI name such as RMI profiler.
const string RmiName_SetCooldown="";
const string RmiName_BattleInfo="";
const string RmiName_SpawnEntity="";
const string RmiName_CastSkill="";
const string RmiName_BattleEnd="";
const string RmiName_BattleWin="";
const string RmiName_BattleLose="";
const string RmiName_Turn="";
       
const string RmiName_First = "";
#endif
		public override Nettention.Proud.RmiID[] GetRmiIDList() { return Common.RmiIDList; } 
	}
}

