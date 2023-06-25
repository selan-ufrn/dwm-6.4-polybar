/* See LICENSE file for copyright and license details. */

/*
 *  You obviously need the X11 development package installed, but here is the upstream copy
 *  of this header if you can't bother using the contents of your own hard drive. ;-P
 *  https://cgit.freedesktop.org/xorg/proto/x11proto/tree/XF86keysym.h
 */
#include <X11/XF86keysym.h>

#include "colors/stock.h" // Custom colors. See comment in the code, where colors were originally defined.

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const Gap default_gap        = {.isgap = 1, .realgap = 10, .gappx = 10};
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int usealtbar          = 1;        /* 1 means use non-dwm status bar */
static const char *altbarclass      = "Polybar"; /* Alternate bar class name */
static const char *altbarcmd        = "$HOME/.config/polybar/launch_polybar.sh"; /* Alternate bar launch command */
static const char *fonts[]          = { 
  "Fira Code:style=Medium:pixelsize=20:antialias=true:autohint=true",
  "VictorMono Nerd Font:style=Medium:pixelsize=20:antialias=true:autohint=true",
  "JetBrainsMono Nerd Font:style=Medium:pixelsize=14:antialias=true:autohint=true",
	"Ubuntu Nerd Font:size=12",
  "monospace:size=10"
};
static const char dmenufont[]       = "Fira Code:style=Medium:pixelsize=18:antialias=true:autohint=true";
// static const char dmenufont[]       = "JetBrainsMono Nerd Font:style=Medium:pixelsize=18:antialias=true:autohint=true";
// static const char dmenufont[]       = "Ubuntu Nerd Font:size=12";
// static const char dmenufont[]       = "VictorMono Nerd Font:style=Medium:pixelsize=18:antialias=true:autohint=true";
// static const char dmenufont[]       = "monospace:size=10";
// static const char dmenufont[]       = "fontawesome:size=12";
// static const char dmenufont[]       = "Hack:size=12:antialias=true:autohint=true";
// static const char dmenufont[]       = "Mononoki:size=12:antialias=true:autohint=true";
// static const char dmenufont[]       = "Terminus:size=18:weight=bold:size=18:antialias=true:hinting=true";
// static const char dmenufont[]       = "SauceCodePro Nerd Font Mono:weight=bold:size=18:antialias=true:hinting=true";
// static const char dmenufont[]       = "3270medium nerd font:weight=bold:size=12:antialias=true:hinting=true";

// ====================================================
// Now Colors come from colors/stock.h
// See that header to lear how to customize colors.
// ====================================================

// static const char col_gray1[]       = "#222222";
// static const char col_gray2[]       = "#444444";
// static const char col_gray3[]       = "#bbbbbb";
// static const char col_gray4[]       = "#eeeeee";
// static const char col_cyan[]        = "#005577";
// static const char *colors[][3]      = {
	/*               fg         bg         border   */
	// [SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	// [SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
// };

typedef struct {
	const char *name;
	const void *cmd;
} Sp;
const char *spcmd1[] = {"st", "-n", "spterm", "-g", "120x34", NULL };
const char *spcmd2[] = {"st", "-n", "spfm", "-g", "144x41", "-e", "ranger", NULL };
// const char *spcmd1[] = {"kitty", "--name", "spterm", "-o", "initial_window_width=125", "-o", "initial_window_height=25", NULL };
// const char *spcmd2[] = {"kitty", "--name", "spfm", "-o", "initial_window_width=120", "-o", "initial_window_height=30", "ranger", NULL };
// const char *spcmd2[] = {"kitty", "--name", "spfm", "-o", "initial_window_width=122","-o", "initial_window_height=30", "--detach", "ranger", NULL };
const char *spcmd3[] = {"keepassxc", NULL };
const char *spcmd4[] = {"st", "-n", "spmusic", "-g", "144x41", "-e", "ncmpcpp", NULL };
static Sp scratchpads[] = {
	/* name          cmd  */
	{"spterm",      spcmd1},
	{"spranger",    spcmd2},
	{"keepassxc",   spcmd3},
	{"spmusic",     spcmd4},
};

/* tagging */
// static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
// static const char *tags[] = { "", "", "", "󰙯", "", "", "", "", ""};
static const char *tags[] = { "", "", "", "", "", "", "", "", ""};
// 
static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class                instance     title       tags mask     iscentered   isfloating   monitor */
	{ "Gimp",               NULL,        NULL,           0,            0,           1,           -1 },
	{ "St",                 NULL,        NULL,           0,            1,           0,           -1 },
	{ "kitty",              NULL,        NULL,           0,            1,           0,           -1 },
	{ "Spotify",            NULL,        NULL,           1 << 8,       1,           0,           -1 },
	{ "Sxiv",               NULL,        NULL,           0,            1,           1,           -1 },
	{ "Blueman-manager",    NULL,        NULL,           0,            1,           1,           -1 },
	{ "zoom",               NULL,        NULL,           0,            1,           1,           -1 },
	{ "xpad",               NULL,        NULL,           0,            1,           1,           -1 },
	{ "gnome-calculator",   NULL,        NULL,           0,            1,           1,           -1 },
	{ "Lxappearance",       NULL,        NULL,           0,            1,           1,           -1 },
	{ NULL,                 NULL,        "System Logout",0,            1,           1,           -1 },
	{ NULL,                 NULL,        "Brave",        1 << 1,       1,           0,           -1 },
	{ "Skype",              NULL,        NULL,           1 << 5,       1,           1,           -1 },
	{ "firefox",            NULL,        NULL,           1 << 1,       1,           0,           -1 },
	{ "TelegramDesktop",    NULL,        NULL,           1 << 2,       1,           0,           -1 },
	{ "Whatsapp-for-linux", NULL,        NULL,           1 << 2,       1,           0,           -1 },
	{ "discord",            NULL,        NULL,           1 << 3,       1,           0,           -1 },
	{ "VirtualBox Manager", NULL,        NULL,           1 << 7,       1,           1,           -1 },
	{ "qBittorrent",        NULL,        NULL,           1 << 7,       1,           0,           -1 },
	// { "mpv",                NULL,        NULL,           0,            1,           1,           -1 },
	{ NULL,                 "spterm",		 NULL,           SPTAG(0),		 1,           1,			     -1 },
	{ NULL,                 "spfm",		   NULL,           SPTAG(1),		 1,           1,			     -1 },
	{ NULL,                 "keepassxc", NULL,           SPTAG(2),		 1,           1,			     -1 },
	{ NULL,                 "spmusic",   NULL,           SPTAG(3),		 1,           1,			     -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
// static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */
static const int lockfullscreen = 0; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "",      tile },    /* first entry is default */
	{ "",      NULL },    /* no layout function means floating behavior */
	{ "",      monocle },
	{ "",      centeredmaster },
	{ "",      centeredfloatingmaster },
	{ "",      bstack },
	{ "",      bstackhoriz },
	{ NULL,       NULL },
};

	// { "flt",      NULL },    /* no layout function means floating behavior */
	// { "s",      monocle },
	// { "s",      centeredmaster },
	// { "s",      centeredfloatingmaster },
	// { "s",      bstack },
	// { "s",      bstackhoriz },
	// { "[]=",      tile },    /* first entry is default */
	// { "><>",      NULL },    /* no layout function means floating behavior */
	// { "[M]",      monocle },
	// { "|M|",      centeredmaster },
	// { ">M>",      centeredfloatingmaster },
	// { "TTT",      bstack },
	// { "===",      bstackhoriz },
/* key definitions */
#define MODKEY Mod4Mask
#define ALTKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
// static const char *dmenucmd[] = { "dmenu_run", "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = {
	"dmenu_run",
	// "j4-dmenu-desktop",
	"-m", dmenumon,
	"-fn", dmenufont,
	"-nb", col_gray1,
	"-nf", col_gray3,
	"-sb", col_cyan,
	"-sf", col_gray4,
  "-l" , "15",
  "-c" , NULL,
	NULL
};

//== st
static const char *termcmd[]  = { "kitty", NULL };
//== alacritty
static const char *term2cmd[]  = { "alacritty", NULL };
//== kitty
static const char *term3cmd[]  = { "st", NULL };
//== firefox
static const char *browser_cmd[]  = { "${BROWSER}", NULL };
//== File manager
static const char *filemgr_cmd[]  = { "thunar", NULL };
//== discord
static const char *discord_cmd[]  = { "discord", NULL };
//== spotify
// static const char *spotify_cmd[]  = { "spotify", NULL };
//== sxiv to change background and dwm's colorscheme:
// After app runs, choose the new background and then type
// Ctrl-x + Ctrl-w
// This calls a script that calls pywall and sets background with xwallpaper.
// After that, press MODKEY+Fn+F5 to reload color scheme based on xrbd
// static const char *sxiv_cmd[]  = { "sxiv -t /home/selan/Pictures/wallpapers", NULL };

static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,          spawn,             SHCMD("dmenu_run_customized.sh") }, 
	{ MODKEY|ShiftMask,             XK_d,          spawn,             {.v = dmenucmd } },
	{ MODKEY,                       XK_Return,     spawn,             {.v = termcmd } },
	{ MODKEY|ShiftMask,             XK_Return,     spawn,             {.v = term2cmd } },
	{ MODKEY|ALTKEY,                XK_Return,     spawn,             {.v = term3cmd } },
  { MODKEY,                       XK_c,          spawn,             SHCMD("toggle_dark_conky") },
	{ MODKEY|ShiftMask,             XK_c,          spawn,             SHCMD("toggle_light_conky") },
	{ MODKEY,                       XK_t,          spawn,             SHCMD("toggle_picom") },
	{ MODKEY,                       XK_a,          spawn,             SHCMD("toggle_systray") },

  //== Keybindings for programs using the format SUPER + ALT + "key"
	{ MODKEY|ALTKEY,           XK_b,          spawn,                  SHCMD("$BROWSER") },
	{ MODKEY|ALTKEY,           XK_c,          spawn,                  SHCMD("scshot -s $HOME/Pictures/screenshots/") },
	{ MODKEY|ALTKEY,           XK_d,          spawn,                  {.v = discord_cmd} },
	{ MODKEY|ALTKEY,           XK_e,          spawn,                  SHCMD("flameshot gui -p $HOME/Pictures/screenshots/") },
	{ MODKEY|ALTKEY,           XK_f,          spawn,                  {.v = filemgr_cmd} },
 	{ MODKEY|ALTKEY,           XK_k,          togglescratch,          {.ui = 2 } },
	{ MODKEY|ALTKEY,           XK_l,          spawn,                  SHCMD("i3lock") },
	{ MODKEY|ALTKEY,           XK_o,          spawn,                  SHCMD("openboard") },
	{ MODKEY|ALTKEY,           XK_p,          spawn,                  SHCMD("system-config-printer") },
 	{ MODKEY|ALTKEY,           XK_r,          togglescratch,          {.ui = 1 } },
	{ MODKEY|ALTKEY,           XK_m,          togglescratch,          {.ui = 3 }  },
	{ MODKEY|ALTKEY,           XK_n,          spawn,                  SHCMD("dunstctl history-pop") }, 
	{ MODKEY|ALTKEY,           XK_s,          spawn,                  SHCMD("spotify") },
// { MODKEY|ALTKEY,           XK_t,          spawn,                  SHCMD("system-monitoring-center") },
	{ MODKEY|ALTKEY,           XK_a,          spawn,                  SHCMD("pavucontrol") },
	{ MODKEY|ALTKEY,           XK_v,          spawn,                  SHCMD("pavucontrol") },
	{ MODKEY|ALTKEY,           XK_w,          spawn,                  SHCMD("sxiv -t $HOME/Pictures/wallpapers") },
 	{ MODKEY,                  XK_z,          togglescratch,          {.ui = 0 } },

  //== Brightness and volume control
  { 0,                  XF86XK_AudioLowerVolume,  spawn,       SHCMD("vol_lower") },
  { 0,                  XF86XK_AudioRaiseVolume,  spawn,       SHCMD("vol_raise") },
  { 0,                  XF86XK_AudioMute,         spawn,       SHCMD("toggle_vol_mute") },
  { 0,                  XF86XK_MonBrightnessUp,   spawn,       SHCMD("mon_brightness_up") },
  { 0,                  XF86XK_MonBrightnessDown, spawn,       SHCMD("mon_brightness_down") },
  { 0,                  XF86XK_KbdBrightnessUp,   spawn,       SHCMD("kbd_brightness_up") },
  { 0,                  XF86XK_KbdBrightnessDown, spawn,       SHCMD("kbd_brightness_down") },
  // { 0,                  XF86XK_AudioPlay,         spawn,       SHCMD("audio_play_pause") },
  // { 0,                  XF86XK_AudioPrev,         spawn,       SHCMD("audio_prev") },
  // { 0,                  XF86XK_AudioNext,         spawn,       SHCMD("audio_next") },
  { 0,                  XF86XK_AudioPlay,         spawn,       SHCMD("playerctl --all-players play-pause") },
  { 0,                  XF86XK_AudioPrev,         spawn,       SHCMD("playerctl prev") },
  { 0,                  XF86XK_AudioNext,         spawn,       SHCMD("playerctl next") },


	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_h,      focusdir,       {.i = 0 } }, // left
	{ MODKEY,                       XK_l,      focusdir,       {.i = 1 } }, // right
	{ MODKEY,                       XK_Left,   focusdir,       {.i = 0 } }, // left
	{ MODKEY,                       XK_Right,  focusdir,       {.i = 1 } }, // right
	{ MODKEY,                       XK_Up,     focusdir,       {.i = 2 } }, // up
	{ MODKEY,                       XK_Down,   focusdir,       {.i = 3 } }, // down
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY|ShiftMask,             XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_j,      pushdown,       {0} },
	{ MODKEY|ShiftMask,             XK_k,      pushup,         {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
  { MODKEY,                       XK_m,      zoom,           {0} },
	{ MODKEY,                       XK_q,      killclient,     {0} },
	// { MODKEY|ShiftMask,             XK_q,          spawn,          SHCMD("logout_window") },
	{ MODKEY|ShiftMask,             XK_q,      spawn,          SHCMD("dmenu_logout") },
	// { MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	// { MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	// { MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	// { MODKEY,                       XK_u,      setlayout,      {.v = &layouts[3]} },
	// { MODKEY,                       XK_o,      setlayout,      {.v = &layouts[4]} },
	// { MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY,                       XK_space,      cyclelayout,    {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_space,      cyclelayout,    {.i = +1 } },
	{ MODKEY,                       XK_BackSpace,  togglefloating, {0} },
 	{ MODKEY|ShiftMask,             XK_f,          togglefullscr,  {0} },
	{ MODKEY,												XK_f,	   togglefullscreen, {0} },
 	{ MODKEY,                       XK_s,          togglesticky,   {0} },
	// { MODKEY,                       XK_0,          view,                   {.ui = ~SPTAGMASK } },
	// { MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	// { MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },

  //== Fn Keys.
  // { MODKEY,                       XK_F1,        spawn,            SHCMD("groff -mom -tbl $HOME/.local/share/dwm/system_help.mom -Tpdf | zathura -") },
  { MODKEY,                       XK_F1,        spawn,            SHCMD("toggle_help") },
  { MODKEY,                       XK_F2,        spawn,            SHCMD("toggle_lockscreen") },
  { MODKEY,                       XK_F3,        spawn,            SHCMD("blueman-manager") },
  { MODKEY,                       XK_F4,        spawn,            SHCMD("mpv --untimed --no-cache --no-osc --no-input-default-bindings --profile=low-latency --input-conf=/dev/null --title=webcam $(ls /dev/video[0,2,4,6,8] | tail -n 1)") },
  { MODKEY,                       XK_F5,        spawn,            SHCMD("dmenu_keymap") },
  { MODKEY,                       XK_F6,        spawn,            SHCMD("dmenu_displayselect") },
  { MODKEY,                       XK_F7,        spawn,            SHCMD("dmenu_networkmanager") },
  { MODKEY,                       XK_F8,        spawn,            SHCMD("toggle_dunst") },
  { MODKEY,                       XK_F9,        spawn,            SHCMD("toggle_wifi") },
  { MODKEY,                       XK_F10,       spawn,            SHCMD("toggle_bluetooth") },
  { MODKEY,                       XK_F11,       spawn,            SHCMD("toggle_screenkey") },
  { MODKEY,                       XK_F12,       spawn,            SHCMD("single_monitor") },

	{ MODKEY,                       XK_minus,  setgaps,        {.i = -2 } },
	{ MODKEY,                       XK_equal,  setgaps,        {.i = +2 } },
	{ MODKEY|ShiftMask,             XK_minus,  setgaps,        {.i = GAP_RESET } },
	{ MODKEY|ShiftMask,             XK_equal,  setgaps,        {.i = GAP_TOGGLE} },
	{ MODKEY|ALTKEY,                XK_q,          quit,           {0} },
	{ MODKEY|ControlMask|ShiftMask, XK_q,          quit,           {1} }, 

	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6) 
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY|ALTKEY,  Button1,        resizemouse,    {0} },
	{ ClkClientWin,         MODKEY|ShiftMask,Button1,       resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

static const char *ipcsockpath = "/tmp/dwm.sock";
static IPCCommand ipccommands[] = {
  IPCCOMMAND(  view,                1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  toggleview,          1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  tag,                 1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  toggletag,           1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  tagmon,              1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  focusmon,            1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  focusstack,          1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  zoom,                1,      {ARG_TYPE_NONE}   ),
  IPCCOMMAND(  incnmaster,          1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  killclient,          1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  togglefloating,      1,      {ARG_TYPE_NONE}   ),
  IPCCOMMAND(  setmfact,            1,      {ARG_TYPE_FLOAT}  ),
  IPCCOMMAND(  setlayoutsafe,       1,      {ARG_TYPE_PTR}    ),
  IPCCOMMAND(  quit,                1,      {ARG_TYPE_NONE}   )
};

