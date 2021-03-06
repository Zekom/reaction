#include "ui/runtime.cfg"

#define ITEM_TYPE_TEXT 0                  // simple text
#define ITEM_TYPE_BUTTON 1                // button, basically text with a border 
#define ITEM_TYPE_RADIOBUTTON 2           // toggle button, may be grouped 
#define ITEM_TYPE_CHECKBOX 3              // check box
#define ITEM_TYPE_EDITFIELD 4             // editable text, associated with a cvar
#define ITEM_TYPE_COMBO 5                 // drop down list
#define ITEM_TYPE_LISTBOX 6               // scrollable list  
#define ITEM_TYPE_MODEL 7                 // model
#define ITEM_TYPE_OWNERDRAW 8             // owner draw, name specs what it is
#define ITEM_TYPE_NUMERICFIELD 9          // editable text, associated with a cvar
#define ITEM_TYPE_SLIDER 10               // mouse speed, volume, etc.
#define ITEM_TYPE_YESNO 11                // yes no cvar setting
#define ITEM_TYPE_MULTI 12                // multiple list setting, enumerated
#define ITEM_TYPE_BIND 13		              // multiple list setting, enumerated
    
#define ITEM_ALIGN_LEFT 0                 // left alignment
#define ITEM_ALIGN_CENTER 1               // center alignment
#define ITEM_ALIGN_RIGHT 2                // right alignment

//Makro - added for YES/NO items

#define YESNO_TEXT			0
#define YESNO_ICON_LEFT		1
#define YESNO_ICON_RIGHT	2

#define ITEM_TEXTSTYLE_NORMAL 0           // normal text
#define ITEM_TEXTSTYLE_BLINK 1            // fast blinking
#define ITEM_TEXTSTYLE_PULSE 2            // slow pulsing
#define ITEM_TEXTSTYLE_SHADOWED 3         // drop shadow ( need a color for this )
#define ITEM_TEXTSTYLE_OUTLINED 4         // drop shadow ( need a color for this )
#define ITEM_TEXTSTYLE_OUTLINESHADOWED 5  // drop shadow ( need a color for this )
#define ITEM_TEXTSTYLE_SHADOWEDMORE 6         // drop shadow ( need a color for this )
                          
#define WINDOW_BORDER_NONE 0              // no border
#define WINDOW_BORDER_FULL 1              // full border based on border color ( single pixel )
#define WINDOW_BORDER_HORZ 2              // horizontal borders only
#define WINDOW_BORDER_VERT 3              // vertical borders only 
#define WINDOW_BORDER_KCGRADIENT 4        // horizontal border using the gradient bars
  
#define WINDOW_STYLE_EMPTY 0              // no background
#define WINDOW_STYLE_FILLED 1             // filled with background color
#define WINDOW_STYLE_GRADIENT 2           // gradient bar based on background color 
#define WINDOW_STYLE_SHADER   3           // gradient bar based on background color 
#define WINDOW_STYLE_TEAMCOLOR 4          // team color
#define WINDOW_STYLE_CINEMATIC 5          // cinematic

#define MENU_TRUE 1                       // uh.. true
#define MENU_FALSE 0                      // and false

#define HUD_VERTICAL				0x00
#define HUD_HORIZONTAL				0x01

// list box element types
#define LISTBOX_TEXT  0x00
#define LISTBOX_IMAGE 0x01

// list feeders
#define FEEDER_HEADS						0x00			// model heads
#define FEEDER_MAPS						0x01			// text maps based on game type
#define FEEDER_SERVERS						0x02			// servers
#define FEEDER_CLANS						0x03			// clan names
#define FEEDER_ALLMAPS						0x04			// all maps available, in graphic format
#define FEEDER_REDTEAM_LIST					0x05			// red team members
#define FEEDER_BLUETEAM_LIST					0x06			// blue team members
#define FEEDER_PLAYER_LIST					0x07			// players
#define FEEDER_TEAM_LIST					0x08			// team members for team voting
#define FEEDER_MODS						0x09			// team members for team voting
#define FEEDER_DEMOS 						0x0a			// team members for team voting
#define FEEDER_SCOREBOARD					0x0b			// team members for team voting
#define FEEDER_Q3HEADS		 				0x0c			// model heads
#define FEEDER_SERVERSTATUS					0x0d			// server status
#define FEEDER_FINDPLAYER					0x0e			// find player
#define FEEDER_CINEMATICS					0x0f			// cinematics
//Makro - improved in-game server info screen
#define FEEDER_INGAME_SERVERINFO			0x10
//Makro - for the captains' ingame menu
#define FEEDER_MMHEADS						0x11
//Makro - weapon replacements list
#define FEEDER_REPLACEMENTS					0x12
//Makro - driver info
#define FEEDER_GLDRIVER_INFO					0x13

// display flags
#define CG_SHOW_BLUE_TEAM_HAS_REDFLAG     	0x00000001
#define CG_SHOW_RED_TEAM_HAS_BLUEFLAG     	0x00000002
#define CG_SHOW_ANYTEAMGAME               	0x00000004
#define CG_SHOW_HARVESTER                 	0x00000008
#define CG_SHOW_ONEFLAG                   	0x00000010
#define CG_SHOW_CTF                       	0x00000020
#define CG_SHOW_OBELISK				0x00000040
#define CG_SHOW_HEALTHCRITICAL			0x00000080
#define CG_SHOW_SINGLEPLAYER			0x00000100
#define CG_SHOW_TOURNAMENT			0x00000200
#define CG_SHOW_DURINGINCOMINGVOICE		0x00000400
#define CG_SHOW_IF_PLAYER_HAS_FLAG		0x00000800
#define CG_SHOW_LANPLAYONLY			0x00001000
#define CG_SHOW_MINED				0x00002000
#define CG_SHOW_HEALTHOK			0x00004000
#define CG_SHOW_TEAMINFO			0x00008000
#define CG_SHOW_NOTEAMINFO			0x00010000
#define CG_SHOW_OTHERTEAMHASFLAG		0x00020000
#define CG_SHOW_YOURTEAMHASENEMYFLAG		0x00040000
#define CG_SHOW_ANYNONTEAMGAME			0x00080000
#define CG_SHOW_2DONLY				0x10000000


#define UI_SHOW_LEADER							0x00000001
#define UI_SHOW_NOTLEADER						0x00000002
#define UI_SHOW_FAVORITESERVERS					0x00000004
#define UI_SHOW_ANYNONTEAMGAME					0x00000008
#define UI_SHOW_ANYTEAMGAME						0x00000010
#define UI_SHOW_NEWHIGHSCORE					0x00000020
#define UI_SHOW_DEMOAVAILABLE					0x00000040
#define UI_SHOW_NEWBESTTIME						0x00000080
#define UI_SHOW_FFA								0x00000100
#define UI_SHOW_NOTFFA							0x00000200
#define UI_SHOW_NETANYNONTEAMGAME	 			0x00000400
#define UI_SHOW_NETANYTEAMGAME		 			0x00000800
#define UI_SHOW_NOTFAVORITESERVERS				0x00001000
//Makro - weapon selection
#define UI_SHOW_WEAP1							0x00002000
#define UI_SHOW_WEAP2							0x00004000
#define UI_SHOW_WEAP3							0x00008000
#define UI_SHOW_WEAP4							0x00010000
#define UI_SHOW_WEAP5							0x00020000
#define UI_SHOW_WEAP6							0x00040000
#define UI_SHOW_WEAP7							0x00080000
//Makro - item selection
#define UI_SHOW_ITEM1							0x00100000
#define UI_SHOW_ITEM2							0x00200000
#define UI_SHOW_ITEM3							0x00400000
#define UI_SHOW_ITEM4							0x00800000
#define UI_SHOW_ITEM5							0x01000000
#define UI_SHOW_ITEM6							0x02000000
//Makro - toggle
#define UI_SHOW_TOGGLE							0x04000000
//Makro - hack !
#define UI_SHOW_REPLACEMENT						0x08000000


// owner draw types
// ideally these should be done outside of this file but
// this makes it much easier for the macro expansion to 
// convert them for the designers ( from the .menu files )
#define CG_OWNERDRAW_BASE 1
#define CG_PLAYER_ARMOR_ICON 1              
#define CG_PLAYER_ARMOR_VALUE 2
#define CG_PLAYER_HEAD 3
#define CG_PLAYER_HEALTH 4
#define CG_PLAYER_AMMO_ICON 5
#define CG_PLAYER_AMMO_VALUE 6
#define CG_SELECTEDPLAYER_HEAD 7
#define CG_SELECTEDPLAYER_NAME 8
#define CG_SELECTEDPLAYER_LOCATION 9
#define CG_SELECTEDPLAYER_STATUS 10
#define CG_SELECTEDPLAYER_WEAPON 11
#define CG_SELECTEDPLAYER_POWERUP 12

#define CG_FLAGCARRIER_HEAD 13
#define CG_FLAGCARRIER_NAME 14
#define CG_FLAGCARRIER_LOCATION 15
#define CG_FLAGCARRIER_STATUS 16
#define CG_FLAGCARRIER_WEAPON 17
#define CG_FLAGCARRIER_POWERUP 18

#define CG_PLAYER_ITEM 19
#define CG_PLAYER_SCORE 20

#define CG_BLUE_FLAGHEAD 21
#define CG_BLUE_FLAGSTATUS 22
#define CG_BLUE_FLAGNAME 23
#define CG_RED_FLAGHEAD 24
#define CG_RED_FLAGSTATUS 25
#define CG_RED_FLAGNAME 26

#define CG_BLUE_SCORE 27
#define CG_RED_SCORE 28
#define CG_RED_NAME 29
#define CG_BLUE_NAME 30
#define CG_HARVESTER_SKULLS 31					// only shows in harvester
#define CG_ONEFLAG_STATUS 32						// only shows in one flag
#define CG_PLAYER_LOCATION 33
#define CG_TEAM_COLOR 34
#define CG_CTF_POWERUP 35
                                        
#define CG_AREA_POWERUP	36
#define CG_AREA_LAGOMETER	37            // painted with old system
#define CG_PLAYER_HASFLAG 38            
#define CG_GAME_TYPE 39                 // not done

#define CG_SELECTEDPLAYER_ARMOR 40      
#define CG_SELECTEDPLAYER_HEALTH 41
#define CG_PLAYER_STATUS 42
#define CG_FRAGGED_MSG 43               // painted with old system
#define CG_PROXMINED_MSG 44             // painted with old system
#define CG_AREA_FPSINFO 45              // painted with old system
#define CG_AREA_SYSTEMCHAT 46           // painted with old system
#define CG_AREA_TEAMCHAT 47             // painted with old system
#define CG_AREA_CHAT 48                 // painted with old system
#define CG_GAME_STATUS 49
#define CG_KILLER 50
#define CG_PLAYER_ARMOR_ICON2D 51              
#define CG_PLAYER_AMMO_ICON2D 52
#define CG_ACCURACY 53
#define CG_ASSISTS 54
#define CG_DEFEND 55
#define CG_EXCELLENT 56
#define CG_IMPRESSIVE 57
#define CG_PERFECT 58
#define CG_GAUNTLET 59
#define CG_SPECTATORS 60
#define CG_TEAMINFO 61
#define CG_VOICE_HEAD 62
#define CG_VOICE_NAME 63
#define CG_PLAYER_HASFLAG2D 64            
#define CG_HARVESTER_SKULLS2D 65					// only shows in harvester
#define CG_CAPFRAGLIMIT 66	 
#define CG_1STPLACE 67
#define CG_2NDPLACE 68
#define CG_CAPTURES 69

//Makro - clock
#define UI_CLOCK		149

//Makro - for SSG crosshair selection
#define UI_SSG_CROSSHAIR 150

//Makro - radio presets
#define UI_RQ3_RADIOPRESET1 151
#define UI_RQ3_RADIOPRESET2 152
#define UI_RQ3_RADIOPRESET3 153
#define UI_RQ3_RADIOPRESET4 154
#define UI_RQ3_RADIOPRESET5 155
#define UI_RQ3_RADIOPRESET6 156
#define UI_RQ3_RADIOPRESET7 157
#define UI_RQ3_RADIOPRESET8 158
#define UI_RQ3_RADIOPRESET9 159
#define UI_RQ3_RADIOPRESET10 160

//Makro - join menu items
#define UI_RQ3_JOINTEAM1 161
#define UI_RQ3_JOINTEAM2 162

//Makro - replacement model info
#define UI_RQ3_REPLACEMENTINFO 163
#define UI_RQ3_REPLACEMENTNAME 164
#define UI_RQ3_REPLACEMENTMODEL 165
#define UI_RQ3_REPLACEMENTTYPE 166
#define UI_RQ3_REPLACEMENTSUBTYPE 167
//Makro - startup menu text
#define UI_RQ3_STARTUP 168

#define UI_OWNERDRAW_BASE 200
#define UI_HANDICAP 200
#define UI_EFFECTS 201
#define UI_PLAYERMODEL 202
#define UI_CLANNAME 203
#define UI_CLANLOGO 204
#define UI_GAMETYPE 205
#define UI_MAPPREVIEW 206
#define UI_SKILL 207
#define UI_BLUETEAMNAME 208
#define UI_REDTEAMNAME 209
#define UI_BLUETEAM1 210
#define UI_BLUETEAM2 211
#define UI_BLUETEAM3 212
#define UI_BLUETEAM4 213
#define UI_BLUETEAM5 214
#define UI_REDTEAM1 215
#define UI_REDTEAM2 216
#define UI_REDTEAM3 217
#define UI_REDTEAM4 218
#define UI_REDTEAM5 219
#define UI_NETSOURCE 220
#define UI_NETMAPPREVIEW 221
#define UI_NETFILTER 222
#define UI_TIER 223
#define UI_OPPONENTMODEL 224
#define UI_TIERMAP1 225
#define UI_TIERMAP2 226
#define UI_TIERMAP3 227
#define UI_PLAYERLOGO 228
#define UI_OPPONENTLOGO 229
#define UI_PLAYERLOGO_METAL 230
#define UI_OPPONENTLOGO_METAL 231
#define UI_PLAYERLOGO_NAME 232
#define UI_OPPONENTLOGO_NAME 233
#define UI_TIER_MAPNAME 234
#define UI_TIER_GAMETYPE 235
#define UI_ALLMAPS_SELECTION 236
#define UI_OPPONENT_NAME 237
#define UI_VOTE_KICK 238
#define UI_BOTNAME 239
#define UI_BOTSKILL 240
#define UI_REDBLUE 241
#define UI_CROSSHAIR 242
#define UI_SELECTEDPLAYER 243
#define UI_MAPCINEMATIC 244
#define UI_NETGAMETYPE 245
#define UI_NETMAPCINEMATIC 246
#define UI_SERVERREFRESHDATE 247
#define UI_SERVERMOTD 248
#define UI_GLINFO  249
#define UI_KEYBINDSTATUS 250
#define UI_CLANCINEMATIC 251
#define UI_MAP_TIMETOBEAT 252
#define UI_JOINGAMETYPE 253
#define UI_PREVIEWCINEMATIC 254
#define UI_STARTMAPCINEMATIC 255
#define UI_MAPS_SELECTION 256
#define UI_RESOLUTION 257

#define VOICECHAT_GETFLAG			"getflag"				// command someone to get the flag
#define VOICECHAT_OFFENSE			"offense"				// command someone to go on offense
#define VOICECHAT_DEFEND			"defend"				// command someone to go on defense
#define VOICECHAT_DEFENDFLAG		"defendflag"			// command someone to defend the flag
#define VOICECHAT_PATROL			"patrol"				// command someone to go on patrol (roam)
#define VOICECHAT_CAMP				"camp"					// command someone to camp (we don't have sounds for this one)
#define VOICECHAT_FOLLOWME			"followme"				// command someone to follow you
#define VOICECHAT_RETURNFLAG		"returnflag"			// command someone to return our flag
#define VOICECHAT_FOLLOWFLAGCARRIER	"followflagcarrier"		// command someone to follow the flag carrier
#define VOICECHAT_YES				"yes"					// yes, affirmative, etc.
#define VOICECHAT_NO				"no"					// no, negative, etc.
#define VOICECHAT_ONGETFLAG			"ongetflag"				// I'm getting the flag
#define VOICECHAT_ONOFFENSE			"onoffense"				// I'm on offense
#define VOICECHAT_ONDEFENSE			"ondefense"				// I'm on defense
#define VOICECHAT_ONPATROL			"onpatrol"				// I'm on patrol (roaming)
#define VOICECHAT_ONCAMPING			"oncamp"				// I'm camping somewhere
#define VOICECHAT_ONFOLLOW			"onfollow"				// I'm following
#define VOICECHAT_ONFOLLOWCARRIER	"onfollowcarrier"		// I'm following the flag carrier
#define VOICECHAT_ONRETURNFLAG		"onreturnflag"			// I'm returning our flag
#define VOICECHAT_INPOSITION		"inposition"			// I'm in position
#define VOICECHAT_IHAVEFLAG			"ihaveflag"				// I have the flag
#define VOICECHAT_BASEATTACK		"baseattack"			// the base is under attack
#define VOICECHAT_ENEMYHASFLAG		"enemyhasflag"			// the enemy has our flag (CTF)
#define VOICECHAT_STARTLEADER		"startleader"			// I'm the leader
#define VOICECHAT_STOPLEADER		"stopleader"			// I resign leadership
#define VOICECHAT_TRASH				"trash"					// lots of trash talk
#define VOICECHAT_WHOISLEADER		"whoisleader"			// who is the team leader
#define VOICECHAT_WANTONDEFENSE		"wantondefense"			// I want to be on defense
#define VOICECHAT_WANTONOFFENSE		"wantonoffense"			// I want to be on offense
#define VOICECHAT_KILLINSULT		"kill_insult"			// I just killed you
#define VOICECHAT_TAUNT				"taunt"					// I want to taunt you
#define VOICECHAT_DEATHINSULT		"death_insult"			// you just killed me
#define VOICECHAT_KILLGAUNTLET		"kill_gauntlet"			// I just killed you with the gauntlet
#define VOICECHAT_PRAISE			"praise"				// you did something good



// RQ3 Stuff //

/*
#define RQ3_MAIN_BAR_COLOR 0 0 .1 .95
#define RQ3_MAIN_BAR_COLOR2 1 1 1 1
#define RQ3_MAIN_HINT_COLOR .75 .75 1 .75
*/


// GREY BAR, RED BORDER


/*
#define RQ3_MAIN_BAR_COLOR 1 1 1 .75
#define RQ3_MAIN_BAR_COLOR2  1 0 0 1
//#define RQ3_MAIN_HINT_COLOR .75 .75 .75 1
#define RQ3_MAIN_HINT_COLOR .9 .9 .9 0
*/

#define RQ3_MAIN_BAR_COLOR 0 0 0 .75
#define RQ3_MAIN_BAR_COLOR2  1 1 1 .75
//#define RQ3_MAIN_HINT_COLOR .75 .75 .75 1
#define RQ3_MAIN_HINT_COLOR .9 .9 .9 0


#define UI_FOLDER "ui"
#define UI_ASSETS "ui/assets"

/* old colors, if you like them more
#define RQ3_MAIN_BAR_COLOR 0 0 0 1
#define RQ3_MAIN_BAR_COLOR2 1 0 0 1
#define RQ3_MAIN_HINT_COLOR 1 .5 0 .75
*/

#define RQ3_MAIN_TEXTSIZE .28
#define RQ3_MENU_OVERLAY_COLOR 0 0 0 .5
#define RQ3_MAIN_FOCUSCOLOR .25 .25 .5 1

#define UI_MAIN_ITEM_SPACING_Y	36
#define UI_MAIN_HINT_OFFSET_Y	20
#define UI_MAIN_TEXTSIZE		.28
#define UI_INGAME_TEXTSIZE		.28
#define UI_COLOR_INACTIVE 0 0 0 0.2
#define UI_SUBMENU_TEXTSIZE		.25

//Ingame stuff

#define Ingame_Color1 1 .75 0 0
//#define Ingame_Color2 1 .75 0 .25
#define Ingame_Color2 1 .75 0 0

#define Ingame_TextColor 1 1 1 1
#define Ingame_BorderColor1 0 0 0 0
//#define Ingame_BorderColor2 .35 .35 .35 1
#define Ingame_BorderColor2 .35 .35 .35 0
//#define Ingame_HintColor .75 .75 1 1
//#define Ingame_HintColor .75 .75 .75 1
#define Ingame_HintColor .9 .9 .9 0


#define Ig_Window_Color 0 0 0 .8
#define Ig_Window_Color2 .5 .5 .5 .25
#define Ig_Window_BorderColor .5 .5 .5 1
#define Ig_Window_TitleColor .2 .2 .2 1

#define Ig_Sub_Color1 1 1 1 0
//#define Ig_Sub_Color2 1 .75 0 .2
#define Ig_Sub_Color2 .75 .75 1 .25
#define Ig_Sub_TextColor 1 1 1 1
#define Ig_Sub_BorderColor1 .5 .5 .5 0
#define Ig_Sub_BorderColor2 .35 .35 .35 0
#define Ig_Sub_HintColor .75 .75 1 1

#define Ig_Setup_TabColor .75 .75 .75 1

#define Ig_ShadowSize 12

//Menu colors
#define MENUCOLOR_DEMO		.95 .95 1
#define MENUCOLOR_MOD		1 1 1
#define MENUCOLOR_SETUP 1 .97 .9
#define MENUCOLOR_CONTROLS	.98 .98 .98
#define MENUCOLOR_PLAYER	.95 1 1
#define MENUCOLOR_SYSTEM	.92 .92 .98
#define MENUCOLOR_REPLACEMENTS	.96 .96 1
#define MENUCOLOR_OPTIONS	1 1 1

#define ALIGN_AFTER(ITEM, DIMX, DIMY)\
	alignrect ITEM ITEM_ALIGN_RIGHT -$evalint(DIMX) 0 DIMX DIMY

#define LISTBOX_STYLE(SCALE, ALIGNX)\
	type ITEM_TYPE_LISTBOX\
	style WINDOW_STYLE_FILLED\
	forcetextcolor\
	backcolor 0 0 0 .05\
	border 0\
	bordersize 2\
	bordercolor .5 .5 .5 1\
	forecolor .0 .0 .1 1\
	elementtype LISTBOX_TEXT\
	elementwidth 160\
	elementheight 15\
	textscale SCALE\
	textalign ITEM_ALIGN_LEFT\
	textalignx ALIGNX\
	textaligny 14\
	outlinecolor .0 .0 0 .1

#define STANDARD_MENU()

// alpha fading

#define ALPHA_FADE_EX(what, whichcolor, from, to, duration)	\
			setitemcolor what whichcolor 5 5 5 from ;	\
			timefade what whichcolor 5 5 5 to 0 duration
	
#define ALPHA_FADE_FORE_EX(what, to, duration)	\
		ALPHA_FADE_EX(what, forecolor, 0, to, duration)

#define ALPHA_FADE_BACK_EX(what, to, duration)	\
		ALPHA_FADE_EX(what, backcolor, 0, to, duration)

#define DEFAULT_FADEIN_TIME 125

#define ALPHA_FADE_FORE(what, to)	\
		ALPHA_FADE_FORE_EX(what, to, DEFAULT_FADEIN_TIME)

#define ALPHA_FADE_BACK(what, to)	\
		ALPHA_FADE_BACK_EX(what, to, DEFAULT_FADEIN_TIME)


