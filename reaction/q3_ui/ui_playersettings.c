//-----------------------------------------------------------------------------
//
// $Id$
//
//-----------------------------------------------------------------------------
//
// $Log$
// Revision 1.7  2002/01/11 19:48:30  jbravo
// Formatted the source in non DOS format.
//
// Revision 1.6  2001/12/31 16:28:42  jbravo
// I made a Booboo with the Log tag.
//
//
//-----------------------------------------------------------------------------
// Copyright (C) 1999-2000 Id Software, Inc.
//
#include "ui_local.h"

//#define ART_FRAMEL			"menu/art/frame2_l"
//#define ART_FRAMER			"menu/art/frame1_r"
//#define ART_MODEL0			"menu/art/model_0"
//#define ART_MODEL1			"menu/art/model_1"
#define ART_MODEL0			"menu/art/rq3-player-models.jpg"
#define ART_MODEL1			"menu/art/rq3-player-models-focus.jpg"
#define ART_BACK0			"menu/art/rq3-menu-back.tga"
#define ART_BACK1			"menu/art/rq3-menu-back-focus.tga"
//#define ART_BACK0			"menu/art/back_0"
//#define ART_BACK1			"menu/art/back_1"
#define ART_FX_BASE			"menu/art/fx_base"
#define ART_FX_BLUE			"menu/art/fx_blue"
#define ART_FX_CYAN			"menu/art/fx_cyan"
#define ART_FX_GREEN		"menu/art/fx_grn"
#define ART_FX_RED			"menu/art/fx_red"
#define ART_FX_TEAL			"menu/art/fx_teal"
#define ART_FX_WHITE		"menu/art/fx_white"
#define ART_FX_YELLOW		"menu/art/fx_yel"

//Elder: RQ3 stuff
#define RQ3_SETUP_ICON		"menu/art/rq3-setup-player.jpg"
#define RQ3_SETUP_TITLE		"menu/art/rq3-title-setup.tga"

#define PLAYERINFO_X_POS		72

#define ID_NAME			10
#define ID_HANDICAP		11
#define ID_EFFECTS		12
#define ID_BACK			13
#define ID_MODEL		14

#define MAX_NAMELENGTH	20


typedef struct {
	menuframework_s		menu;

//Blaze: Dont need this
//	menutext_s			banner;
//	menubitmap_s		framel;
//	menubitmap_s		framer;
/* Elder: removed
	menutext_s		multim;
	menutext_s		setupm;
	menutext_s		demom;
	menutext_s		modsm;
	menutext_s		exitm;
*/
	//Elder: RQ3 stuff	
	menubitmap_s	rq3_setuptitle;
	menubitmap_s	rq3_setupicon;	
	
	menubitmap_s		player;

	menufield_s			name;
	menulist_s			handicap;
	menulist_s			effects;

	menubitmap_s		back;
	menubitmap_s		model;
	//menubitmap_s		item_null;

	qhandle_t			fxBasePic;
	qhandle_t			fxPic[7];
	playerInfo_t		playerinfo;
	int					current_fx;
	char				playerModel[MAX_QPATH];
} playersettings_t;

static playersettings_t	s_playersettings;

static int gamecodetoui[] = {4,2,3,0,5,1,6};
static int uitogamecode[] = {4,6,2,3,1,5,7};

static const char *handicap_items[] = {
	"None",
	"95",
	"90",
	"85",
	"80",
	"75",
	"70",
	"65",
	"60",
	"55",
	"50",
	"45",
	"40",
	"35",
	"30",
	"25",
	"20",
	"15",
	"10",
	"5",
	0
};


/*
=================
PlayerSettings_DrawName
=================
*/
static void PlayerSettings_DrawName( void *self ) {
	menufield_s		*f;
	qboolean		focus;
	int				style;
	char			*txt;
	char			c;
	float			*color;
	int				n;
	int				basex, x, y;
	char			name[32];

	f = (menufield_s*)self;
	basex = f->generic.x;
	y = f->generic.y;
	focus = (f->generic.parent->cursor == f->generic.menuPosition);

	style = UI_LEFT|UI_SMALLFONT;
	color = text_color_normal;
	if( focus ) {
		style |= UI_PULSE;
		color = text_color_highlight;
	}

	UI_DrawProportionalString( basex, y, "Name", style, color );

	// draw the actual name
	basex += 64;
	y += PROP_HEIGHT;
	txt = f->field.buffer;
	color = g_color_table[ColorIndex(COLOR_WHITE)];
	x = basex;
	while ( (c = *txt) != 0 ) {
		if ( !focus && Q_IsColorString( txt ) ) {
			n = ColorIndex( *(txt+1) );
			if( n == 0 ) {
				n = 7;
			}
			color = g_color_table[n];
			txt += 2;
			continue;
		}
		UI_DrawChar( x, y, c, style, color );
		txt++;
		x += SMALLCHAR_WIDTH;
	}

	// draw cursor if we have focus
	if( focus ) {
		if ( trap_Key_GetOverstrikeMode() ) {
			c = 11;
		} else {
			c = 10;
		}

		style &= ~UI_PULSE;
		style |= UI_BLINK;

		UI_DrawChar( basex + f->field.cursor * SMALLCHAR_WIDTH, y, c, style, color_white );
	}

	// draw at bottom also using proportional font
	// Elder removed
	//Q_strncpyz( name, f->field.buffer, sizeof(name) );
	//Q_CleanStr( name );
	//UI_DrawProportionalString( 320, 440, name, UI_CENTER|UI_BIGFONT, text_color_normal );
}


/*
=================
PlayerSettings_DrawHandicap
=================
*/
static void PlayerSettings_DrawHandicap( void *self ) {
	menulist_s		*item;
	qboolean		focus;
	int				style;
	float			*color;

	item = (menulist_s *)self;
	focus = (item->generic.parent->cursor == item->generic.menuPosition);

	style = UI_LEFT|UI_SMALLFONT;
	color = text_color_normal;
	if( focus ) {
		style |= UI_PULSE;
		color = text_color_highlight;
	}

	UI_DrawProportionalString( item->generic.x, item->generic.y, "Handicap", style, color );
	UI_DrawProportionalString( item->generic.x + 64, item->generic.y + PROP_HEIGHT, handicap_items[item->curvalue], style, color );
}


/*
=================
PlayerSettings_DrawEffects
=================
*/
static void PlayerSettings_DrawEffects( void *self ) {
	menulist_s		*item;
	qboolean		focus;
	int				style;
	float			*color;

	item = (menulist_s *)self;
	focus = (item->generic.parent->cursor == item->generic.menuPosition);

	style = UI_LEFT|UI_SMALLFONT;
	color = text_color_normal;
	if( focus ) {
		style |= UI_PULSE;
		color = text_color_highlight;
	}

	UI_DrawProportionalString( item->generic.x, item->generic.y, "Effects", style, color );

	UI_DrawHandlePic( item->generic.x + 64, item->generic.y + PROP_HEIGHT + 8, 128, 8, s_playersettings.fxBasePic );
	UI_DrawHandlePic( item->generic.x + 64 + item->curvalue * 16 + 8, item->generic.y + PROP_HEIGHT + 6, 16, 12, s_playersettings.fxPic[item->curvalue] );
}


/*
=================
PlayerSettings_DrawPlayer
=================
*/
static void PlayerSettings_DrawPlayer( void *self ) {
	menubitmap_s	*b;
	vec3_t			viewangles;
	char			buf[MAX_QPATH];

	trap_Cvar_VariableStringBuffer( "model", buf, sizeof( buf ) );
	if ( strcmp( buf, s_playersettings.playerModel ) != 0 ) {
		UI_PlayerInfo_SetModel( &s_playersettings.playerinfo, buf );
		strcpy( s_playersettings.playerModel, buf );

		viewangles[YAW]   = 180 - 60;
		//viewangles[YAW] = ( uis.realtime / 1000 ) % 360;
		viewangles[PITCH] = 0;
		viewangles[ROLL]  = 0;
		//Blaze: Default draw of player, changed WP_MACHINEGUN to WP_PISTOL
		UI_PlayerInfo_SetInfo( &s_playersettings.playerinfo, LEGS_IDLE, TORSO_STAND, viewangles, vec3_origin, WP_M4, qfalse );
	}

	b = (menubitmap_s*) self;
	UI_DrawPlayer( b->generic.x, b->generic.y, b->width, b->height, &s_playersettings.playerinfo, uis.realtime/2 );
}


/*
=================
PlayerSettings_SaveChanges
=================
*/
static void PlayerSettings_SaveChanges( void ) {
	// name
	trap_Cvar_Set( "name", s_playersettings.name.field.buffer );

	// handicap
	trap_Cvar_SetValue( "handicap", 100 - s_playersettings.handicap.curvalue * 5 );

	// effects color
	trap_Cvar_SetValue( "color1", uitogamecode[s_playersettings.effects.curvalue] );
}


/*
=================
PlayerSettings_MenuKey
=================
*/
static sfxHandle_t PlayerSettings_MenuKey( int key ) {
	if( key == K_MOUSE2 || key == K_ESCAPE ) {
		PlayerSettings_SaveChanges();
	}
	return Menu_DefaultKey( &s_playersettings.menu, key );
}


/*
=================
PlayerSettings_SetMenuItems
=================
*/
static void PlayerSettings_SetMenuItems( void ) {
	vec3_t	viewangles;
	int		c;
	int		h;

	// name
	Q_strncpyz( s_playersettings.name.field.buffer, UI_Cvar_VariableString("name"), sizeof(s_playersettings.name.field.buffer) );

	// effects color
	c = trap_Cvar_VariableValue( "color1" ) - 1;
	if( c < 0 || c > 6 ) {
		c = 6;
	}
	s_playersettings.effects.curvalue = gamecodetoui[c];

	// model/skin
	memset( &s_playersettings.playerinfo, 0, sizeof(playerInfo_t) );
	
	viewangles[YAW]   = 180 - 30;
	//viewangles[YAW] = ( uis.realtime / 1000 ) % 360;
	viewangles[PITCH] = 0;
	viewangles[ROLL]  = 0;

	UI_PlayerInfo_SetModel( &s_playersettings.playerinfo, UI_Cvar_VariableString( "model" ) );
	//Blaze: Changed WP_MACHINEGUN to WP_PISTOL
	UI_PlayerInfo_SetInfo( &s_playersettings.playerinfo, LEGS_IDLE, TORSO_STAND, viewangles, vec3_origin, WP_M4, qfalse );

	// handicap
	h = Com_Clamp( 5, 100, trap_Cvar_VariableValue("handicap") );
	s_playersettings.handicap.curvalue = 20 - h / 5;
}


/*
=================
PlayerSettings_MenuEvent
=================
*/
static void PlayerSettings_MenuEvent( void* ptr, int event ) {
	if( event != QM_ACTIVATED ) {
		return;
	}

	switch( ((menucommon_s*)ptr)->id ) {
	case ID_HANDICAP:
		trap_Cvar_Set( "handicap", va( "%i", 100 - 25 * s_playersettings.handicap.curvalue ) );
		break;

	case ID_MODEL:
		PlayerSettings_SaveChanges();
		UI_PlayerModelMenu();
		break;

	case ID_BACK:
		PlayerSettings_SaveChanges();
		UI_PopMenu();
		break;
	}
}

/*
===============
Added by Elder
PlayerSettings_MenuDraw
===============
*/
static void PlayerSettings_MenuDraw( void ) {
	//Elder: "Dim" and "Letterbox" mask
	UI_FillRect( 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, color_deepdim );
	UI_FillRect( 0, 0, SCREEN_WIDTH, 54, color_black);
	UI_FillRect( 0, 426, SCREEN_WIDTH, 54, color_black);
	UI_FillRect( 0, 54, SCREEN_WIDTH, 2, color_red);
	UI_FillRect( 0, 426, SCREEN_WIDTH, 2, color_red);
	
	// standard menu drawing
	Menu_Draw( &s_playersettings.menu );
}

/*
=================
PlayerSettings_MenuInit
=================
*/
static void PlayerSettings_MenuInit( void ) {
	int		y;

	memset(&s_playersettings,0,sizeof(playersettings_t));

	PlayerSettings_Cache();

	s_playersettings.menu.draw		 = PlayerSettings_MenuDraw;
	s_playersettings.menu.key        = PlayerSettings_MenuKey;
	s_playersettings.menu.wrapAround = qtrue;
	s_playersettings.menu.fullscreen = qtrue;
	s_playersettings.menu.showlogo	 = qtrue;

/*	s_playersettings.banner.generic.type  = MTYPE_BTEXT;
	s_playersettings.banner.generic.x     = 320;
	s_playersettings.banner.generic.y     = 16;
	s_playersettings.banner.string        = "PLAYER SETTINGS";
	s_playersettings.banner.color         = color_white;
	s_playersettings.banner.style         = UI_CENTER;

	s_playersettings.framel.generic.type  = MTYPE_BITMAP;
	s_playersettings.framel.generic.name  = ART_FRAMEL;
	s_playersettings.framel.generic.flags = QMF_LEFT_JUSTIFY|QMF_INACTIVE;
	s_playersettings.framel.generic.x     = 0;
	s_playersettings.framel.generic.y     = 78;
	s_playersettings.framel.width         = 256;
	s_playersettings.framel.height        = 329;

	s_playersettings.framer.generic.type  = MTYPE_BITMAP;
	s_playersettings.framer.generic.name  = ART_FRAMER;
	s_playersettings.framer.generic.flags = QMF_LEFT_JUSTIFY|QMF_INACTIVE;
	s_playersettings.framer.generic.x     = 376;
	s_playersettings.framer.generic.y     = 76;
	s_playersettings.framer.width         = 256;
	s_playersettings.framer.height        = 334;
*/
/* Elder: removed
	s_playersettings.multim.generic.type	= MTYPE_PTEXT;
	s_playersettings.multim.generic.flags 	= QMF_CENTER_JUSTIFY|QMF_PULSEIFFOCUS|QMF_INACTIVE;
	s_playersettings.multim.generic.x		= 120;
	s_playersettings.multim.generic.y		= 3;
	s_playersettings.multim.string			= "MULTIPLAYER";
	s_playersettings.multim.color			= color_red;
	s_playersettings.multim.style			= UI_CENTER | UI_DROPSHADOW;

	s_playersettings.setupm.generic.type	= MTYPE_PTEXT;
	s_playersettings.setupm.generic.flags 	= QMF_CENTER_JUSTIFY|QMF_INACTIVE|QMF_HIGHLIGHT;
	s_playersettings.setupm.generic.x		= 280;
	s_playersettings.setupm.generic.y		= 3;
	s_playersettings.setupm.string			= "SETUP";
	s_playersettings.setupm.color			= color_red;
	s_playersettings.setupm.style			= UI_CENTER | UI_DROPSHADOW;

	s_playersettings.demom.generic.type		= MTYPE_PTEXT;
	s_playersettings.demom.generic.flags	= QMF_CENTER_JUSTIFY|QMF_PULSEIFFOCUS|QMF_INACTIVE;
	s_playersettings.demom.generic.x		= 390;
	s_playersettings.demom.generic.y		= 3;
	s_playersettings.demom.string			= "DEMOS";
	s_playersettings.demom.color			= color_red;
	s_playersettings.demom.style			= UI_CENTER | UI_DROPSHADOW;

	s_playersettings.modsm.generic.type		= MTYPE_PTEXT;
//Note the following line, this makes it highlight
	s_playersettings.modsm.generic.flags 	= QMF_CENTER_JUSTIFY|QMF_PULSEIFFOCUS|QMF_INACTIVE;
	s_playersettings.modsm.generic.x		= 500;
	s_playersettings.modsm.generic.y		= 3;
	s_playersettings.modsm.string			= "MODS";
	s_playersettings.modsm.color			= color_red;
	s_playersettings.modsm.style			= UI_CENTER | UI_DROPSHADOW;

	s_playersettings.exitm.generic.type		= MTYPE_PTEXT;
	s_playersettings.exitm.generic.flags  	= QMF_CENTER_JUSTIFY|QMF_PULSEIFFOCUS|QMF_INACTIVE;
	s_playersettings.exitm.generic.x		= 590;
	s_playersettings.exitm.generic.y		= 3;
	s_playersettings.exitm.string			= "EXIT";
	s_playersettings.exitm.color			= color_red;
	s_playersettings.exitm.style			= UI_CENTER | UI_DROPSHADOW;
*/

	//Elder: Info for system icon
	s_playersettings.rq3_setupicon.generic.type					= MTYPE_BITMAP;
	s_playersettings.rq3_setupicon.generic.name					= RQ3_SETUP_ICON;
	s_playersettings.rq3_setupicon.generic.flags				= QMF_LEFT_JUSTIFY|QMF_INACTIVE;
	s_playersettings.rq3_setupicon.generic.x					= 0;
	s_playersettings.rq3_setupicon.generic.y					= 4;
	s_playersettings.rq3_setupicon.width						= RQ3_ICON_WIDTH;
	s_playersettings.rq3_setupicon.height						= RQ3_ICON_HEIGHT;

	//Elder: Info for setup title
	s_playersettings.rq3_setuptitle.generic.type				= MTYPE_BITMAP;
	s_playersettings.rq3_setuptitle.generic.name				= RQ3_SETUP_TITLE;
	s_playersettings.rq3_setuptitle.generic.flags				= QMF_LEFT_JUSTIFY|QMF_INACTIVE;
	s_playersettings.rq3_setuptitle.generic.x					= 64;
	s_playersettings.rq3_setuptitle.generic.y					= 12;
	s_playersettings.rq3_setuptitle.width						= 256;
	s_playersettings.rq3_setuptitle.height						= 32;
	
	y = 144;
	s_playersettings.name.generic.type			= MTYPE_FIELD;
	s_playersettings.name.generic.flags			= QMF_NODEFAULTINIT;
	s_playersettings.name.generic.ownerdraw		= PlayerSettings_DrawName;
	s_playersettings.name.field.widthInChars	= MAX_NAMELENGTH;
	s_playersettings.name.field.maxchars		= MAX_NAMELENGTH;
	s_playersettings.name.generic.x				= PLAYERINFO_X_POS;
	s_playersettings.name.generic.y				= y;
	s_playersettings.name.generic.left			= 192 - 8;
	s_playersettings.name.generic.top			= y - 8;
	s_playersettings.name.generic.right			= 192 + 200;
	s_playersettings.name.generic.bottom		= y + 2 * PROP_HEIGHT;

	y += 3 * PROP_HEIGHT;
	s_playersettings.handicap.generic.type		= MTYPE_SPINCONTROL;
	s_playersettings.handicap.generic.flags		= QMF_NODEFAULTINIT;
	s_playersettings.handicap.generic.id		= ID_HANDICAP;
	s_playersettings.handicap.generic.ownerdraw	= PlayerSettings_DrawHandicap;
	s_playersettings.handicap.generic.x			= PLAYERINFO_X_POS;
	s_playersettings.handicap.generic.y			= y;
	s_playersettings.handicap.generic.left		= 192 - 8;
	s_playersettings.handicap.generic.top		= y - 8;
	s_playersettings.handicap.generic.right		= 192 + 200;
	s_playersettings.handicap.generic.bottom	= y + 2 * PROP_HEIGHT;
	s_playersettings.handicap.numitems			= 20;

	y += 3 * PROP_HEIGHT;
	s_playersettings.effects.generic.type		= MTYPE_SPINCONTROL;
	s_playersettings.effects.generic.flags		= QMF_NODEFAULTINIT;
	s_playersettings.effects.generic.id			= ID_EFFECTS;
	s_playersettings.effects.generic.ownerdraw	= PlayerSettings_DrawEffects;
	s_playersettings.effects.generic.x			= PLAYERINFO_X_POS;
	s_playersettings.effects.generic.y			= y;
	s_playersettings.effects.generic.left		= 192 - 8;
	s_playersettings.effects.generic.top		= y - 8;
	s_playersettings.effects.generic.right		= 192 + 200;
	s_playersettings.effects.generic.bottom		= y + 2* PROP_HEIGHT;
	s_playersettings.effects.numitems			= 7;

	s_playersettings.model.generic.type			= MTYPE_BITMAP;
	s_playersettings.model.generic.name			= ART_MODEL0;
	s_playersettings.model.generic.flags		= QMF_RIGHT_JUSTIFY|QMF_PULSEIFFOCUS;
	s_playersettings.model.generic.id			= ID_MODEL;
	s_playersettings.model.generic.callback		= PlayerSettings_MenuEvent;
	s_playersettings.model.generic.x			= 640 - 8;
	s_playersettings.model.generic.y			= 480-44;
	s_playersettings.model.width				= 64;
	s_playersettings.model.height				= 32;
	s_playersettings.model.focuspic				= ART_MODEL1;

	s_playersettings.player.generic.type		= MTYPE_BITMAP;
	s_playersettings.player.generic.flags		= QMF_INACTIVE;
	s_playersettings.player.generic.ownerdraw	= PlayerSettings_DrawPlayer;
	s_playersettings.player.generic.x			= 400;
	s_playersettings.player.generic.y			= -40;
	s_playersettings.player.width				= 32*10;
	s_playersettings.player.height				= 56*10;

	s_playersettings.back.generic.type			= MTYPE_BITMAP;
	s_playersettings.back.generic.name			= ART_BACK0;
	s_playersettings.back.generic.flags			= QMF_LEFT_JUSTIFY|QMF_PULSEIFFOCUS;
	s_playersettings.back.generic.id			= ID_BACK;
	s_playersettings.back.generic.callback		= PlayerSettings_MenuEvent;
	s_playersettings.back.generic.x				= 8;
	s_playersettings.back.generic.y				= 480-44;
	s_playersettings.back.width					= 32;
	s_playersettings.back.height				= 32;
	s_playersettings.back.focuspic				= ART_BACK1;

	//s_playersettings.item_null.generic.type		= MTYPE_BITMAP;
	//s_playersettings.item_null.generic.flags	= QMF_LEFT_JUSTIFY|QMF_MOUSEONLY|QMF_SILENT;
	//s_playersettings.item_null.generic.x		= 0;
	//s_playersettings.item_null.generic.y		= 0;
	//s_playersettings.item_null.width			= 640;
	//s_playersettings.item_null.height			= 480;

//	Menu_AddItem( &s_playersettings.menu, &s_playersettings.banner );
//	Menu_AddItem( &s_playersettings.menu, &s_playersettings.framel );
//	Menu_AddItem( &s_playersettings.menu, &s_playersettings.framer );
//Elder: removed
//	Menu_AddItem( &s_playersettings.menu, &s_playersettings.multim );
//	Menu_AddItem( &s_playersettings.menu, &s_playersettings.setupm );
//	Menu_AddItem( &s_playersettings.menu, &s_playersettings.demom );
//	Menu_AddItem( &s_playersettings.menu, &s_playersettings.modsm );
//	Menu_AddItem( &s_playersettings.menu, &s_playersettings.exitm );

	Menu_AddItem( &s_playersettings.menu, &s_playersettings.rq3_setupicon );
	Menu_AddItem( &s_playersettings.menu, &s_playersettings.rq3_setuptitle );

	Menu_AddItem( &s_playersettings.menu, &s_playersettings.name );
	Menu_AddItem( &s_playersettings.menu, &s_playersettings.handicap );
	Menu_AddItem( &s_playersettings.menu, &s_playersettings.effects );
	Menu_AddItem( &s_playersettings.menu, &s_playersettings.model );
	Menu_AddItem( &s_playersettings.menu, &s_playersettings.back );

	Menu_AddItem( &s_playersettings.menu, &s_playersettings.player );

	//Menu_AddItem( &s_playersettings.menu, &s_playersettings.item_null );

	PlayerSettings_SetMenuItems();
}


/*
=================
PlayerSettings_Cache
=================
*/
void PlayerSettings_Cache( void ) {
	//trap_R_RegisterShaderNoMip( ART_FRAMEL );
	//trap_R_RegisterShaderNoMip( ART_FRAMER );
	trap_R_RegisterShaderNoMip( ART_MODEL0 );
	trap_R_RegisterShaderNoMip( ART_MODEL1 );
	trap_R_RegisterShaderNoMip( ART_BACK0 );
	trap_R_RegisterShaderNoMip( ART_BACK1 );
	
	trap_R_RegisterShaderNoMip( RQ3_SETUP_ICON );
	trap_R_RegisterShaderNoMip( RQ3_SETUP_TITLE );

	s_playersettings.fxBasePic = trap_R_RegisterShaderNoMip( ART_FX_BASE );
	s_playersettings.fxPic[0] = trap_R_RegisterShaderNoMip( ART_FX_RED );
	s_playersettings.fxPic[1] = trap_R_RegisterShaderNoMip( ART_FX_YELLOW );
	s_playersettings.fxPic[2] = trap_R_RegisterShaderNoMip( ART_FX_GREEN );
	s_playersettings.fxPic[3] = trap_R_RegisterShaderNoMip( ART_FX_TEAL );
	s_playersettings.fxPic[4] = trap_R_RegisterShaderNoMip( ART_FX_BLUE );
	s_playersettings.fxPic[5] = trap_R_RegisterShaderNoMip( ART_FX_CYAN );
	s_playersettings.fxPic[6] = trap_R_RegisterShaderNoMip( ART_FX_WHITE );
}


/*
=================
UI_PlayerSettingsMenu
=================
*/
void UI_PlayerSettingsMenu( void ) {
	PlayerSettings_MenuInit();
	UI_PushMenu( &s_playersettings.menu );
}