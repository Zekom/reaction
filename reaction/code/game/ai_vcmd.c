//-----------------------------------------------------------------------------
//
// $Id$
//
//-----------------------------------------------------------------------------
//
// $Log$
// Revision 1.8  2002/07/02 20:22:35  jbravo
// Changed the files to use the right ui.
//
// Revision 1.7  2002/06/16 20:06:13  jbravo
// Reindented all the source files with "indent -kr -ut -i8 -l120 -lc120 -sob -bad -bap"
//
// Revision 1.6  2002/06/16 17:37:59  jbravo
// Removed the MISSIONPACK ifdefs and missionpack only code.
//
// Revision 1.5  2002/04/04 18:06:44  makro
// Improved door code. Bots reply to radio treport from teammates.
// Improved reloading code.
//
// Revision 1.4  2002/01/11 19:48:29  jbravo
// Formatted the source in non DOS format.
//
// Revision 1.3  2001/12/31 16:28:42  jbravo
// I made a Booboo with the Log tag.
//
//
//-----------------------------------------------------------------------------
// Copyright (C) 1999-2000 Id Software, Inc.
//

/*****************************************************************************
 * name:		ai_vcmd.c
 *
 * desc:		Quake3 bot AI
 *
 * $Archive: /MissionPack/code/game/ai_vcmd.c $
 * $Author$ 
 * $Revision$
 * $Modtime: 11/17/00 5:37a $
 * $Date$
 *
 *****************************************************************************/

#include "g_local.h"
#include "botlib.h"
#include "be_aas.h"
#include "be_ea.h"
#include "be_ai_char.h"
#include "be_ai_chat.h"
#include "be_ai_gen.h"
#include "be_ai_goal.h"
#include "be_ai_move.h"
#include "be_ai_weap.h"
//
#include "ai_main.h"
#include "ai_dmq3.h"
#include "ai_chat.h"
#include "ai_cmd.h"
#include "ai_dmnet.h"
#include "ai_team.h"
#include "ai_vcmd.h"
//
#include "chars.h"		//characteristics
#include "inv.h"		//indexes into the inventory
#include "syn.h"		//synonyms
#include "match.h"		//string matching types and vars

// for the voice chats

//Blaze: was there a extra ../ here?
#include "../ui/menudef.h"

typedef struct voiceCommand_s {
	char *cmd;
	void (*func) (bot_state_t * bs, int client, int mode);
} voiceCommand_t;

/*
==================
BotVoiceChat_GetFlag
==================
*/
void BotVoiceChat_GetFlag(bot_state_t * bs, int client, int mode)
{
	//
	if (gametype == GT_CTF) {
		if (!ctf_redflag.areanum || !ctf_blueflag.areanum)
			return;
	} else {
		return;
	}
	//
	bs->decisionmaker = client;
	bs->ordered = qtrue;
	bs->order_time = FloatTime();
	//set the time to send a message to the team mates
	bs->teammessage_time = FloatTime() + 2 * random();
	//set the ltg type
	bs->ltgtype = LTG_GETFLAG;
	//set the team goal time
	bs->teamgoal_time = FloatTime() + CTF_GETFLAG_TIME;
	// get an alternate route in ctf
	if (gametype == GT_CTF) {
		//get an alternative route goal towards the enemy base
		BotGetAlternateRouteGoal(bs, BotOppositeTeam(bs));
	}
	//
	BotSetTeamStatus(bs);
	// remember last ordered task
	BotRememberLastOrderedTask(bs);
#ifdef DEBUG
	BotPrintTeamGoal(bs);
#endif				//DEBUG
}

/*
==================
BotVoiceChat_Offense
==================
*/
void BotVoiceChat_Offense(bot_state_t * bs, int client, int mode)
{
	if (gametype == GT_CTF) {
		BotVoiceChat_GetFlag(bs, client, mode);
		return;
	}
	bs->decisionmaker = client;
	bs->ordered = qtrue;
	bs->order_time = FloatTime();
	//set the time to send a message to the team mates
	bs->teammessage_time = FloatTime() + 2 * random();
	//set the ltg type
	bs->ltgtype = LTG_ATTACKENEMYBASE;
	//set the team goal time
	bs->teamgoal_time = FloatTime() + TEAM_ATTACKENEMYBASE_TIME;
	bs->attackaway_time = 0;
	//
	BotSetTeamStatus(bs);
	// remember last ordered task
	BotRememberLastOrderedTask(bs);
#ifdef DEBUG
	BotPrintTeamGoal(bs);
#endif				//DEBUG
}

/*
==================
BotVoiceChat_Defend
==================
*/
void BotVoiceChat_Defend(bot_state_t * bs, int client, int mode)
{
	if (gametype == GT_CTF) {
		switch (BotTeam(bs)) {
		case TEAM_RED:
			memcpy(&bs->teamgoal, &ctf_redflag, sizeof(bot_goal_t));
			break;
		case TEAM_BLUE:
			memcpy(&bs->teamgoal, &ctf_blueflag, sizeof(bot_goal_t));
			break;
		default:
			return;
		}
	} else {
		return;
	}
	//
	bs->decisionmaker = client;
	bs->ordered = qtrue;
	bs->order_time = FloatTime();
	//set the time to send a message to the team mates
	bs->teammessage_time = FloatTime() + 2 * random();
	//set the ltg type
	bs->ltgtype = LTG_DEFENDKEYAREA;
	//get the team goal time
	bs->teamgoal_time = FloatTime() + TEAM_DEFENDKEYAREA_TIME;
	//away from defending
	bs->defendaway_time = 0;
	//
	BotSetTeamStatus(bs);
	// remember last ordered task
	BotRememberLastOrderedTask(bs);
#ifdef DEBUG
	BotPrintTeamGoal(bs);
#endif				//DEBUG
}

/*
==================
BotVoiceChat_DefendFlag
==================
*/
void BotVoiceChat_DefendFlag(bot_state_t * bs, int client, int mode)
{
	BotVoiceChat_Defend(bs, client, mode);
}

/*
==================
BotVoiceChat_Patrol
==================
*/
void BotVoiceChat_Patrol(bot_state_t * bs, int client, int mode)
{
	//
	bs->decisionmaker = client;
	//
	bs->ltgtype = 0;
	bs->lead_time = 0;
	bs->lastgoal_ltgtype = 0;
	//
	BotAI_BotInitialChat(bs, "dismissed", NULL);
	trap_BotEnterChat(bs->cs, client, CHAT_TELL);
	BotVoiceChatOnly(bs, -1, VOICECHAT_ONPATROL);
	//
	BotSetTeamStatus(bs);
#ifdef DEBUG
	BotPrintTeamGoal(bs);
#endif				//DEBUG
}

/*
==================
BotVoiceChat_Camp
==================
*/
void BotVoiceChat_Camp(bot_state_t * bs, int client, int mode)
{
	int areanum;
	aas_entityinfo_t entinfo;
	char netname[MAX_NETNAME];

	//
	bs->teamgoal.entitynum = -1;
	BotEntityInfo(client, &entinfo);
	//if info is valid (in PVS)
	if (entinfo.valid) {
		areanum = BotPointAreaNum(entinfo.origin);
		if (areanum) {	// && trap_AAS_AreaReachability(areanum)) {
			//NOTE: just assume the bot knows where the person is
			//if (BotEntityVisible(bs->entitynum, bs->eye, bs->viewangles, 360, client)) {
			bs->teamgoal.entitynum = client;
			bs->teamgoal.areanum = areanum;
			VectorCopy(entinfo.origin, bs->teamgoal.origin);
			VectorSet(bs->teamgoal.mins, -8, -8, -8);
			VectorSet(bs->teamgoal.maxs, 8, 8, 8);
			//}
		}
	}
	//if the other is not visible
	if (bs->teamgoal.entitynum < 0) {
		BotAI_BotInitialChat(bs, "whereareyou", EasyClientName(client, netname, sizeof(netname)), NULL);
		trap_BotEnterChat(bs->cs, client, CHAT_TELL);
		return;
	}
	//
	bs->decisionmaker = client;
	bs->ordered = qtrue;
	bs->order_time = FloatTime();
	//set the time to send a message to the team mates
	bs->teammessage_time = FloatTime() + 2 * random();
	//set the ltg type
	bs->ltgtype = LTG_CAMPORDER;
	//get the team goal time
	bs->teamgoal_time = FloatTime() + TEAM_CAMP_TIME;
	//the teammate that requested the camping
	bs->teammate = client;
	//not arrived yet
	bs->arrive_time = 0;
	//
	BotSetTeamStatus(bs);
	// remember last ordered task
	BotRememberLastOrderedTask(bs);
#ifdef DEBUG
	BotPrintTeamGoal(bs);
#endif				//DEBUG
}

/*
==================
BotVoiceChat_FollowMe
==================
*/
void BotVoiceChat_FollowMe(bot_state_t * bs, int client, int mode)
{
	int areanum;
	aas_entityinfo_t entinfo;
	char netname[MAX_NETNAME];

	bs->teamgoal.entitynum = -1;
	BotEntityInfo(client, &entinfo);
	//if info is valid (in PVS)
	if (entinfo.valid) {
		areanum = BotPointAreaNum(entinfo.origin);
		if (areanum) {	// && trap_AAS_AreaReachability(areanum)) {
			bs->teamgoal.entitynum = client;
			bs->teamgoal.areanum = areanum;
			VectorCopy(entinfo.origin, bs->teamgoal.origin);
			VectorSet(bs->teamgoal.mins, -8, -8, -8);
			VectorSet(bs->teamgoal.maxs, 8, 8, 8);
		}
	}
	//if the other is not visible
	if (bs->teamgoal.entitynum < 0) {
		BotAI_BotInitialChat(bs, "whereareyou", EasyClientName(client, netname, sizeof(netname)), NULL);
		trap_BotEnterChat(bs->cs, client, CHAT_TELL);
		return;
	}
	//
	bs->decisionmaker = client;
	bs->ordered = qtrue;
	bs->order_time = FloatTime();
	//the team mate
	bs->teammate = client;
	//last time the team mate was assumed visible
	bs->teammatevisible_time = FloatTime();
	//set the time to send a message to the team mates
	bs->teammessage_time = FloatTime() + 2 * random();
	//get the team goal time
	bs->teamgoal_time = FloatTime() + TEAM_ACCOMPANY_TIME;
	//set the ltg type
	bs->ltgtype = LTG_TEAMACCOMPANY;
	bs->formation_dist = 3.5 * 32;	//3.5 meter
	bs->arrive_time = 0;
	//
	BotSetTeamStatus(bs);
	// remember last ordered task
	BotRememberLastOrderedTask(bs);
#ifdef DEBUG
	BotPrintTeamGoal(bs);
#endif				//DEBUG
}

/*
==================
BotVoiceChat_FollowFlagCarrier
==================
*/
void BotVoiceChat_FollowFlagCarrier(bot_state_t * bs, int client, int mode)
{
	int carrier;

	carrier = BotTeamFlagCarrier(bs);
	if (carrier >= 0)
		BotVoiceChat_FollowMe(bs, carrier, mode);
#ifdef DEBUG
	BotPrintTeamGoal(bs);
#endif				//DEBUG
}

/*
==================
BotVoiceChat_ReturnFlag
==================
*/
void BotVoiceChat_ReturnFlag(bot_state_t * bs, int client, int mode)
{
	//if not in CTF mode
	if (gametype != GT_CTF) {
		return;
	}
	//
	bs->decisionmaker = client;
	bs->ordered = qtrue;
	bs->order_time = FloatTime();
	//set the time to send a message to the team mates
	bs->teammessage_time = FloatTime() + 2 * random();
	//set the ltg type
	bs->ltgtype = LTG_RETURNFLAG;
	//set the team goal time
	bs->teamgoal_time = FloatTime() + CTF_RETURNFLAG_TIME;
	bs->rushbaseaway_time = 0;
	BotSetTeamStatus(bs);
#ifdef DEBUG
	BotPrintTeamGoal(bs);
#endif				//DEBUG
}

/*
==================
BotVoiceChat_StartLeader
==================
*/
void BotVoiceChat_StartLeader(bot_state_t * bs, int client, int mode)
{
	ClientName(client, bs->teamleader, sizeof(bs->teamleader));
}

/*
==================
BotVoiceChat_StopLeader
==================
*/
void BotVoiceChat_StopLeader(bot_state_t * bs, int client, int mode)
{
	char netname[MAX_MESSAGE_SIZE];

	if (!Q_stricmp(bs->teamleader, ClientName(client, netname, sizeof(netname)))) {
		bs->teamleader[0] = '\0';
		notleader[client] = qtrue;
	}
}

/*
==================
BotVoiceChat_WhoIsLeader
==================
*/
void BotVoiceChat_WhoIsLeader(bot_state_t * bs, int client, int mode)
{
	char netname[MAX_MESSAGE_SIZE];

	if (!TeamPlayIsOn())
		return;

	ClientName(bs->client, netname, sizeof(netname));
	//if this bot IS the team leader
	if (!Q_stricmp(netname, bs->teamleader)) {
		BotAI_BotInitialChat(bs, "iamteamleader", NULL);
		trap_BotEnterChat(bs->cs, 0, CHAT_TEAM);
		BotVoiceChatOnly(bs, -1, VOICECHAT_STARTLEADER);
	}
}

/*
==================
BotVoiceChat_WantOnDefense
==================
*/
void BotVoiceChat_WantOnDefense(bot_state_t * bs, int client, int mode)
{
	char netname[MAX_NETNAME];
	int preference;

	preference = BotGetTeamMateTaskPreference(bs, client);
	preference &= ~TEAMTP_ATTACKER;
	preference |= TEAMTP_DEFENDER;
	BotSetTeamMateTaskPreference(bs, client, preference);
	//
	EasyClientName(client, netname, sizeof(netname));
	BotAI_BotInitialChat(bs, "keepinmind", netname, NULL);
	trap_BotEnterChat(bs->cs, client, CHAT_TELL);
	BotVoiceChatOnly(bs, client, VOICECHAT_YES);
	//Makro - BUTTON_AFFIRMATIVE is now used for reloading
	//trap_EA_Action(bs->client, ACTION_AFFIRMATIVE);
}

/*
==================
BotVoiceChat_WantOnOffense
==================
*/
void BotVoiceChat_WantOnOffense(bot_state_t * bs, int client, int mode)
{
	char netname[MAX_NETNAME];
	int preference;

	preference = BotGetTeamMateTaskPreference(bs, client);
	preference &= ~TEAMTP_DEFENDER;
	preference |= TEAMTP_ATTACKER;
	BotSetTeamMateTaskPreference(bs, client, preference);
	//
	EasyClientName(client, netname, sizeof(netname));
	BotAI_BotInitialChat(bs, "keepinmind", netname, NULL);
	trap_BotEnterChat(bs->cs, client, CHAT_TELL);
	BotVoiceChatOnly(bs, client, VOICECHAT_YES);
	//Makro - BUTTON_AFFIRMATIVE is now used for reloading
	//trap_EA_Action(bs->client, ACTION_AFFIRMATIVE);
}

void BotVoiceChat_Dummy(bot_state_t * bs, int client, int mode)
{
}

voiceCommand_t voiceCommands[] = {
	{VOICECHAT_GETFLAG, BotVoiceChat_GetFlag},
	{VOICECHAT_OFFENSE, BotVoiceChat_Offense},
	{VOICECHAT_DEFEND, BotVoiceChat_Defend},
	{VOICECHAT_DEFENDFLAG, BotVoiceChat_DefendFlag},
	{VOICECHAT_PATROL, BotVoiceChat_Patrol},
	{VOICECHAT_CAMP, BotVoiceChat_Camp},
	{VOICECHAT_FOLLOWME, BotVoiceChat_FollowMe},
	{VOICECHAT_FOLLOWFLAGCARRIER, BotVoiceChat_FollowFlagCarrier},
	{VOICECHAT_RETURNFLAG, BotVoiceChat_ReturnFlag},
	{VOICECHAT_STARTLEADER, BotVoiceChat_StartLeader},
	{VOICECHAT_STOPLEADER, BotVoiceChat_StopLeader},
	{VOICECHAT_WHOISLEADER, BotVoiceChat_WhoIsLeader},
	{VOICECHAT_WANTONDEFENSE, BotVoiceChat_WantOnDefense},
	{VOICECHAT_WANTONOFFENSE, BotVoiceChat_WantOnOffense},
	{NULL, BotVoiceChat_Dummy}
};

int BotVoiceChatCommand(bot_state_t * bs, int mode, char *voiceChat)
{
	int i, voiceOnly, clientNum, color;
	char *ptr, buf[MAX_MESSAGE_SIZE], *cmd;

	if (!TeamPlayIsOn()) {
		return qfalse;
	}

	if (mode == SAY_ALL) {
		return qfalse;	// don't do anything with voice chats to everyone
	}

	Q_strncpyz(buf, voiceChat, sizeof(buf));
	cmd = buf;
	for (ptr = cmd; *cmd && *cmd > ' '; cmd++);
	while (*cmd && *cmd <= ' ')
		*cmd++ = '\0';
	voiceOnly = atoi(ptr);
	for (ptr = cmd; *cmd && *cmd > ' '; cmd++);
	while (*cmd && *cmd <= ' ')
		*cmd++ = '\0';
	clientNum = atoi(ptr);
	for (ptr = cmd; *cmd && *cmd > ' '; cmd++);
	while (*cmd && *cmd <= ' ')
		*cmd++ = '\0';
	color = atoi(ptr);

	if (!BotSameTeam(bs, clientNum)) {
		return qfalse;
	}

	for (i = 0; voiceCommands[i].cmd; i++) {
		if (!Q_stricmp(cmd, voiceCommands[i].cmd)) {
			voiceCommands[i].func(bs, clientNum, mode);
			return qtrue;
		}
	}
	return qfalse;
}