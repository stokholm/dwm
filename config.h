/* See LICENSE file for copyright and license details. */
#include <X11/XF86keysym.h>

/* appearance */
static const char font[]            = "-*-terminus-medium-r-*-*-16-*-*-*-*-*-*-*";
static const char normbordercolor[] = "gray20";
static const char normbgcolor[]     = "black";
static const char normfgcolor[]     = "gray50";
static const char selbordercolor[]  = "red";
static const char selbgcolor[]      = "black";
static const char selfgcolor[]      = "white";
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 10;       /* snap pixel */
static const Bool showbar           = True;     /* False means no bar */
static const Bool topbar            = True;     /* False means bottom bar */

/* tagging */
static const char *tags[] = { "hack", "surf", "chat", "dump" };

static const Rule rules[] = {
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Chromium", NULL,       NULL,       1 << 1,       False,       -1 },
	{ "Gimp",     NULL,       NULL,       1 << 3,       True,        -1 },
	{ "MPlayer",  NULL,       NULL,       ~0,           True,        -1 },
	{ NULL,       NULL,       "irssi",    1 << 2,       False,       -1 },
	{ NULL,       NULL,       "ncmpcpp",  1 << 0,       False,       -1 },
	{ NULL,       NULL,       "rtorrent", 1 << 3,       False,       -1 },
};

/* layout(s) */
static const float mfact      = 0.70;  /* factor of master area size [0.05..0.95] */
static const int nmaster      = 1;     /* number of clients in master area */
static const Bool resizehints = False; /* True means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[T]",      tile },    /* first entry is default */
	{ "[F]",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
        { MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} },

/* commands */
static const char *dmenu[]     = { "dmenu_run", "-fn", font, "-nb", normbgcolor, "-nf", \
                                   normfgcolor, "-sb", selbgcolor, "-sf", selfgcolor, NULL };
static const char *term[]      = { "urxvt", NULL };
static const char *halt[]      = { "sudo", "halt", NULL };
static const char *hdmi[]      = { "hdmi", NULL };
static const char *lvds[]      = { "lvds", NULL };
static const char *voldown[]   = { "volset", "5%-", "unmute", NULL };
static const char *volup[]     = { "volset", "5%+", "unmute", NULL };
static const char *voltoggle[] = { "volset", "toggle", NULL };

static Key keys[] = {
	/* modifier         key                      function        argument */
	{ MODKEY,           XK_p,                    spawn,          {.v = dmenu } },
	{ MODKEY|ShiftMask, XK_Return,               spawn,          {.v = term } },
	{ 0,                XF86XK_PowerOff,         spawn,          {.v = halt } },
	{ MODKEY|ShiftMask, XK_h,                    spawn,          {.v = hdmi } },
	{ MODKEY|ShiftMask, XK_l,                    spawn,          {.v = lvds } },
	{ 0,                XF86XK_AudioLowerVolume, spawn,          {.v = voldown } },
	{ 0,                XF86XK_AudioRaiseVolume, spawn,          {.v = volup } },
	{ 0,                XF86XK_AudioMute,        spawn,          {.v = voltoggle } },
	{ MODKEY,           XK_k,                    focusstack,     {.i = -1 } },
	{ MODKEY,           XK_j,                    focusstack,     {.i = +1 } },
        { MODKEY,           XK_d,                    incnmaster,     {.i = -1 } },
        { MODKEY,           XK_i,                    incnmaster,     {.i = +1 } },
	{ MODKEY,           XK_h,                    setmfact,       {.f = -0.05} },
	{ MODKEY,           XK_l,                    setmfact,       {.f = +0.05} },
	{ MODKEY,           XK_Return,               zoom,           {0} },
	{ MODKEY,           XK_Tab,                  view,           {0} },
	{ MODKEY|ShiftMask, XK_BackSpace,            killclient,     {0} },
	{ MODKEY,           XK_t,                    setlayout,      {.v = &layouts[0]} },
	{ MODKEY,           XK_f,                    setlayout,      {.v = &layouts[1]} },
	{ MODKEY,           XK_m,                    setlayout,      {.v = &layouts[2]} },
	{ MODKEY,           XK_space,                togglefloating, {0} },
	TAGKEYS(            XK_1,                                    0)
	TAGKEYS(            XK_2,                                    1)
	TAGKEYS(            XK_3,                                    2)
	TAGKEYS(            XK_4,                                    3)
	{ MODKEY|ShiftMask, XK_q,                    quit,           {0} },
};

/* button definitions */
/* click can be ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
};
