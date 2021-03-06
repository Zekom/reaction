//-----------------------------------------------------------------------------
//
// $Id$
//
//-----------------------------------------------------------------------------
//
// $Log$
// Revision 1.10  2002/06/16 20:06:13  jbravo
// Reindented all the source files with "indent -kr -ut -i8 -l120 -lc120 -sob -bad -bap"
//
// Revision 1.9  2002/06/16 17:37:59  jbravo
// Removed the MISSIONPACK ifdefs and missionpack only code.
//
// Revision 1.8  2002/05/30 21:18:28  makro
// Bots should reload/bandage when roaming around
// Added "pathtarget" key to all the entities
//
// Revision 1.7  2002/05/10 13:21:53  makro
// Mainly bot stuff. Also fixed a couple of crash bugs
//
// Revision 1.6  2002/05/02 23:05:25  makro
// Loading screen. Jump kicks. Bot stuff
//
// Revision 1.5  2002/04/06 21:42:20  makro
// Changes to bot code. New surfaceparm system.
//
// Revision 1.4  2002/01/11 19:48:29  jbravo
// Formatted the source in non DOS format.
//
// Revision 1.3  2001/12/31 16:28:41  jbravo
// I made a Booboo with the Log tag.
//
//
//-----------------------------------------------------------------------------
// Copyright (C) 1999-2000 Id Software, Inc.
//

/*****************************************************************************
 * name:		ai_dmq3.h
 *
 * desc:		Quake3 bot AI
 *
 * $Archive: /source/code/botai/ai_chat.c $
 * $Author$ 
 * $Revision$
 * $Modtime: 11/10/99 3:30p $
 * $Date$
 *
 *****************************************************************************/

//setup the deathmatch AI
void BotSetupDeathmatchAI(void);

//shutdown the deathmatch AI
void BotShutdownDeathmatchAI(void);

//let the bot live within it's deathmatch AI net
void BotDeathmatchAI(bot_state_t * bs, float thinktime);

//free waypoints
void BotFreeWaypoints(bot_waypoint_t * wp);

//choose a weapon
void BotChooseWeapon(bot_state_t * bs);

//setup movement stuff
void BotSetupForMovement(bot_state_t * bs);

//update the inventory
void BotUpdateInventory(bot_state_t * bs);

//update the inventory during battle
void BotUpdateBattleInventory(bot_state_t * bs, int enemy);

//use holdable items during battle
void BotBattleUseItems(bot_state_t * bs);

//return true if the bot is dead
qboolean BotIsDead(bot_state_t * bs);

//returns true if the bot is in observer mode
qboolean BotIsObserver(bot_state_t * bs);

//returns true if the bot is in the intermission
qboolean BotIntermission(bot_state_t * bs);

//returns true if the bot is in lava or slime
qboolean BotInLavaOrSlime(bot_state_t * bs);

//returns true if the entity is dead
qboolean EntityIsDead(aas_entityinfo_t * entinfo);

//returns true if the entity is invisible
qboolean EntityIsInvisible(aas_entityinfo_t * entinfo);

//returns true if the entity is shooting
qboolean EntityIsShooting(aas_entityinfo_t * entinfo);

// set a user info key/value pair
void BotSetUserInfo(bot_state_t * bs, char *key, char *value);

// set the team status (offense, defense etc.)
void BotSetTeamStatus(bot_state_t * bs);

//returns the name of the client
char *ClientName(int client, char *name, int size);

//returns an simplyfied client name
char *EasyClientName(int client, char *name, int size);

//returns the skin used by the client
char *ClientSkin(int client, char *skin, int size);

// returns the appropriate synonym context for the current game type and situation
int BotSynonymContext(bot_state_t * bs);

// set last ordered task
int BotSetLastOrderedTask(bot_state_t * bs);

// selection of goals for teamplay
void BotTeamGoals(bot_state_t * bs, int retreat);

//returns the aggression of the bot in the range [0, 100]
float BotAggression(bot_state_t * bs);

//returns how bad the bot feels
float BotFeelingBad(bot_state_t * bs);

//returns true if the bot wants to retreat
int BotWantsToRetreat(bot_state_t * bs);

//returns true if the bot wants to chase
int BotWantsToChase(bot_state_t * bs);

//returns true if the bot wants to help
int BotWantsToHelp(bot_state_t * bs);

//returns true if the bot can and wants to rocketjump
int BotCanAndWantsToRocketJump(bot_state_t * bs);

// returns true if the bot has a persistant powerup and a weapon
int BotHasPersistantPowerupAndWeapon(bot_state_t * bs);

//returns true if the bot wants to and goes camping
int BotWantsToCamp(bot_state_t * bs);

//the bot will perform attack movements
bot_moveresult_t BotAttackMove(bot_state_t * bs, int tfl);

//returns true if the bot and the entity are in the same team
int BotSameTeam(bot_state_t * bs, int entnum);

//returns true if teamplay is on
int TeamPlayIsOn(void);

// returns the client number of the team mate flag carrier (-1 if none)
int BotTeamFlagCarrier(bot_state_t * bs);

//returns visible team mate flag carrier if available
int BotTeamFlagCarrierVisible(bot_state_t * bs);

//returns visible enemy flag carrier if available
int BotEnemyFlagCarrierVisible(bot_state_t * bs);

//get the number of visible teammates and enemies
void BotVisibleTeamMatesAndEnemies(bot_state_t * bs, int *teammates, int *enemies, float range);

//returns true if within the field of vision for the given angles
qboolean InFieldOfVision(vec3_t viewangles, float fov, vec3_t angles);

//returns true and sets the .enemy field when an enemy is found
int BotFindEnemy(bot_state_t * bs, int curenemy);

//returns a roam goal
void BotRoamGoal(bot_state_t * bs, vec3_t goal);

//returns entity visibility in the range [0, 1]
float BotEntityVisible(int viewer, vec3_t eye, vec3_t viewangles, float fov, int ent);

//the bot will aim at the current enemy
void BotAimAtEnemy(bot_state_t * bs);

//check if the bot should attack
void BotCheckAttack(bot_state_t * bs);

//AI when the bot is blocked
void BotAIBlocked(bot_state_t * bs, bot_moveresult_t * moveresult, int activate);

//AI to predict obstacles
int BotAIPredictObstacles(bot_state_t * bs, bot_goal_t * goal);

//enable or disable the areas the blocking entity is in
void BotEnableActivateGoalAreas(bot_activategoal_t * activategoal, int enable);

//pop an activate goal from the stack
int BotPopFromActivateGoalStack(bot_state_t * bs);

//clear the activate goal stack
void BotClearActivateGoalStack(bot_state_t * bs);

//returns the team the bot is in
int BotTeam(bot_state_t * bs);

//retuns the opposite team of the bot
int BotOppositeTeam(bot_state_t * bs);

//returns the flag the bot is carrying (CTFFLAG_?)
int BotCTFCarryingFlag(bot_state_t * bs);

//remember the last ordered task
void BotRememberLastOrderedTask(bot_state_t * bs);

//set ctf goals (defend base, get enemy flag) during seek
void BotCTFSeekGoals(bot_state_t * bs);

//set ctf goals (defend base, get enemy flag) during retreat
void BotCTFRetreatGoals(bot_state_t * bs);

//
//get a random alternate route goal towards the given base
int BotGetAlternateRouteGoal(bot_state_t * bs, int base);

//returns either the alternate route goal or the given goal
bot_goal_t *BotAlternateRoute(bot_state_t * bs, bot_goal_t * goal);

//create a new waypoint
bot_waypoint_t *BotCreateWayPoint(char *name, vec3_t origin, int areanum);

//find a waypoint with the given name
bot_waypoint_t *BotFindWayPoint(bot_waypoint_t * waypoints, char *name);

//strstr but case insensitive
char *stristr(char *str, char *charset);

//returns the number of the client with the given name
int ClientFromName(char *name);
int ClientOnSameTeamFromName(bot_state_t * bs, char *name);

//
int BotPointAreaNum(vec3_t origin);

//
void BotMapScripts(bot_state_t * bs);

// RQ3 bot functions //

qboolean RQ3_Bot_CheckBandage(bot_state_t * bs);
qboolean RQ3_Bot_CanReload(bot_state_t * bs, int weapon);
int RQ3_Bot_NeedToBandage(bot_state_t * bs);
void VectorTargetDist(vec3_t src, vec3_t dest, int dist, vec3_t final);
void BotAttack(bot_state_t * bs);
bot_moveresult_t BotMoveTo(bot_state_t * bs, vec3_t dest);
void BotMoveTowardsEnt(bot_state_t * bs, vec3_t dest, int dist);
char *BotGetUserInfoKey(bot_state_t * bs, char *key);
void RQ3_Bot_IdleActions(bot_state_t * bs);

//ctf flags
#define CTF_FLAG_NONE		0
#define CTF_FLAG_RED		1
#define CTF_FLAG_BLUE		2
//CTF skins
#define CTF_SKIN_REDTEAM	"red"
#define CTF_SKIN_BLUETEAM	"blue"

extern int gametype;		//game type
extern int maxclients;		//maximum number of clients

extern vmCvar_t bot_grapple;
extern vmCvar_t bot_rocketjump;
extern vmCvar_t bot_fastchat;
extern vmCvar_t bot_nochat;
extern vmCvar_t bot_testrchat;
extern vmCvar_t bot_challenge;

extern bot_goal_t ctf_redflag;
extern bot_goal_t ctf_blueflag;
