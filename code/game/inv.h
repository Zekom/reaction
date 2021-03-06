//-----------------------------------------------------------------------------
//
// $Id$
//
//-----------------------------------------------------------------------------
//
// $Log$
// Revision 1.13  2002/07/22 06:31:47  niceass
// cleaned up the powerup code
//
// Revision 1.12  2002/06/16 20:06:14  jbravo
// Reindented all the source files with "indent -kr -ut -i8 -l120 -lc120 -sob -bad -bap"
//
// Revision 1.11  2002/06/16 17:38:00  jbravo
// Removed the MISSIONPACK ifdefs and missionpack only code.
//
// Revision 1.10  2002/05/10 13:21:53  makro
// Mainly bot stuff. Also fixed a couple of crash bugs
//
// Revision 1.9  2002/04/30 11:54:37  makro
// Bots rule ! Also, added clips to give all. Maybe some other things
//
// Revision 1.8  2002/04/01 02:56:50  jbravo
// Some sourcecode reformatting
//
// Revision 1.7  2002/01/11 19:48:30  jbravo
// Formatted the source in non DOS format.
//
// Revision 1.6  2001/12/31 16:28:42  jbravo
// I made a Booboo with the Log tag.
//
//
//-----------------------------------------------------------------------------
// Elder: we have to seriously repair this file

#define INVENTORY_NONE			0
//armor
#define INVENTORY_ARMOR			1
//weapons
#define INVENTORY_KNIFE			4	// was gauntlet
#define INVENTORY_M3			5	// was shotgun
#define INVENTORY_PISTOL		6	// was machinegun
#define INVENTORY_GRENADE		7	// was grenade launcher
#define INVENTORY_HANDCANNON		8	// was rocket launcher
#define INVENTORY_AKIMBO		9	// was lightning gun
#define INVENTORY_SSG3000		10	// was railgun
#define INVENTORY_MP5			11	// was plasma gun
#define INVENTORY_M4			13	// was BFG10K
/*
#define INVENTORY_GRAPPLINGHOOK		14
#define INVENTORY_NAILGUN		15
#define INVENTORY_PROXLAUNCHER		16
#define INVENTORY_CHAINGUN		17
*/

//ammo
#define INVENTORY_KNIFEAMMO		14
#define INVENTORY_PISTOLAMMO		15
#define INVENTORY_M3AMMO		16
#define INVENTORY_SSG3000AMMO		17
#define INVENTORY_MP5AMMO		18
#define INVENTORY_M4AMMO		19
#define INVENTORY_HANDCANNONAMMO	20
#define INVENTORY_AKIMBOAMMO		21
#define INVENTORY_GRENADEAMMO		22

// Duffman: I stole the below numbers for RQ3 Items

#define INVENTORY_KEVLAR		23
#define INVENTORY_LASER			24
#define INVENTORY_SLIPPERS		25
#define INVENTORY_SILENCER		26
#define INVENTORY_BANDOLIER		27

/*
#define INVENTORY_SHELLS		18
#define INVENTORY_BULLETS		19
#define INVENTORY_GRENADES		20
#define INVENTORY_CELLS			21
#define INVENTORY_LIGHTNINGAMMO		22
#define INVENTORY_ROCKETS		23
#define INVENTORY_SLUGS			24
#define INVENTORY_BFGAMMO		25
#define INVENTORY_NAILS			26
#define INVENTORY_MINES			27
#define INVENTORY_BELT			28
*/

//powerups
#define INVENTORY_HEALTH		29
#define INVENTORY_TELEPORTER		30
#define INVENTORY_MEDKIT		31
#define INVENTORY_KAMIKAZE		32
#define INVENTORY_PORTAL		33
#define INVENTORY_INVULNERABILITY	34
//
#define INVENTORY_REDFLAG		45
#define INVENTORY_BLUEFLAG		46
#define INVENTORY_NEUTRALFLAG		47
#define INVENTORY_REDCUBE		48
#define INVENTORY_BLUECUBE		49

//Makro - adding clips to inventory
#define INVENTORY_KNIFECLIP			100
#define INVENTORY_PISTOLCLIP		101
#define INVENTORY_M3CLIP			102
#define INVENTORY_SSG3000CLIP		103
#define INVENTORY_MP5CLIP			104
#define INVENTORY_M4CLIP			105
#define INVENTORY_HANDCANNONCLIP	106
#define INVENTORY_AKIMBOCLIP		107
#define INVENTORY_GRENADECLIP		108

//enemy stuff
#define ENEMY_HORIZONTAL_DIST		200
#define ENEMY_HEIGHT			201
#define NUM_VISIBLE_ENEMIES		202
#define NUM_VISIBLE_TEAMMATES		203

//item numbers (make sure they are in sync with bg_itemlist in bg_misc.c)
#define MODELINDEX_KNIFE		1
#define MODELINDEX_PISTOL		2
#define MODELINDEX_M4			3
#define MODELINDEX_SSG3000		4
#define MODELINDEX_MP5			5
#define MODELINDEX_HANDCANNON		6
#define MODELINDEX_M3			7
#define MODELINDEX_AKIMBO		8
#define MODELINDEX_GRENADE		9
// Elder: these are not necessary but oh well
#define MODELINDEX_KNIFE_1ST		10
#define MODELINDEX_PISTOL_1ST		11
#define MODELINDEX_M4_1ST		12
#define MODELINDEX_SSG3000_1ST		13
#define MODELINDEX_MP5_1ST		14
#define MODELINDEX_HANDCANNON_1ST	15
#define MODELINDEX_M3_1ST		16
#define MODELINDEX_AKIMBO_1ST		17
#define MODELINDEX_GRENADE_1ST		18

#define MODELINDEX_PISTOLAMMO		19
#define MODELINDEX_M3AMMO		20
#define MODELINDEX_SSG3000AMMO		21
#define MODELINDEX_MP5AMMO		22
#define MODELINDEX_M4AMMO		23
// Elder: for CTB later?
#define MODELINDEX_REDFLAG		24
#define MODELINDEX_BLUEFLAG		25

#define MODELINDEX_KEVLAR		26
#define MODELINDEX_SILENCER		27
#define MODELINDEX_LASER		28
#define MODELINDEX_BANDOLIER		29
#define MODELINDEX_SLIPPERS		30

/*
#define MODELINDEX_ARMORSHARD		1
#define MODELINDEX_ARMORCOMBAT		2
#define MODELINDEX_ARMORBODY		3
#define MODELINDEX_HEALTHSMALL		4
#define MODELINDEX_HEALTH		5
#define MODELINDEX_HEALTHLARGE		6
#define MODELINDEX_HEALTHMEGA		7

#define MODELINDEX_GAUNTLET		8
#define MODELINDEX_SHOTGUN		9
#define MODELINDEX_MACHINEGUN		10
#define MODELINDEX_GRENADELAUNCHER	11
#define MODELINDEX_ROCKETLAUNCHER	12
#define MODELINDEX_LIGHTNING		13
#define MODELINDEX_RAILGUN		14
#define MODELINDEX_PLASMAGUN		15
#define MODELINDEX_BFG10K		16
#define MODELINDEX_GRAPPLINGHOOK	17

#define MODELINDEX_SHELLS		18
#define MODELINDEX_BULLETS		19
#define MODELINDEX_GRENADES		20
#define MODELINDEX_CELLS		21
#define MODELINDEX_LIGHTNINGAMMO	22
#define MODELINDEX_ROCKETS		23
#define MODELINDEX_SLUGS		24
#define MODELINDEX_BFGAMMO		25

#define MODELINDEX_TELEPORTER		26
#define MODELINDEX_MEDKIT		27
#define MODELINDEX_QUAD			28
#define MODELINDEX_ENVIRONMENTSUIT	29
#define MODELINDEX_HASTE		30
#define MODELINDEX_INVISIBILITY		31
#define MODELINDEX_REGEN		32
#define MODELINDEX_FLIGHT		33

#define MODELINDEX_REDFLAG		34
#define MODELINDEX_BLUEFLAG		35

// mission pack only defines

#define MODELINDEX_KAMIKAZE		36
#define MODELINDEX_PORTAL		37
#define MODELINDEX_INVULNERABILITY	38

#define MODELINDEX_NAILS		39
#define MODELINDEX_MINES		40
#define MODELINDEX_BELT			41

#define MODELINDEX_SCOUT		42
#define MODELINDEX_GUARD		43
#define MODELINDEX_DOUBLER		44
#define MODELINDEX_AMMOREGEN		45

#define MODELINDEX_NEUTRALFLAG		46
#define MODELINDEX_REDCUBE		47
#define MODELINDEX_BLUECUBE		48

#define MODELINDEX_NAILGUN		49
#define MODELINDEX_PROXLAUNCHER		50
#define MODELINDEX_CHAINGUN		51
*/

/*
#define WEAPONINDEX_GRAPPLING_HOOK	10
#define WEAPONINDEX_NAILGUN		11
#define WEAPONINDEX_PROXLAUNCHER	12
#define WEAPONINDEX_CHAINGUN		13
*/
//Makro - these were messed up
/*
#define WEAPONINDEX_KNIFE				1
#define WEAPONINDEX_PISTOL				2
#define WEAPONINDEX_M3					3
#define WEAPONINDEX_GRENADE				4
#define WEAPONINDEX_HANDCANNON				5
#define WEAPONINDEX_AKIMBO				6
#define WEAPONINDEX_SSG3000				7
#define WEAPONINDEX_MP5					8
#define WEAPONINDEX_M4					9
*/
#define WEAPONINDEX_PISTOL				1
#define WEAPONINDEX_M3					2
#define WEAPONINDEX_MP5					3
#define WEAPONINDEX_HANDCANNON			4
#define WEAPONINDEX_SSG3000				5
#define WEAPONINDEX_M4					6
#define WEAPONINDEX_AKIMBO				7
#define WEAPONINDEX_KNIFE				8
#define WEAPONINDEX_GRENADE				9
