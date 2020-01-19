/* see LICENSE for copyright and license */

#ifndef CONFIG_H
#define CONFIG_H

/** modifiers **/
#define MOD1            Mod1Mask    /* ALT key */
#define MOD4            Mod4Mask    /* Super/Windows key */
#define CONTROL         ControlMask /* Control key */
#define SHIFT           ShiftMask   /* Shift key */

/** generic settings **/
#define MASTER_SIZE     0.52
#define SHOW_PANEL      False      /* show panel by default on exec */
#define TOP_PANEL       False      /* False means panel is on bottom */
#define PANEL_HEIGHT    0 /*18*/        /* 0 for no space for panel, thus no panel */
#define DEFAULT_MODE    MONOCLE      /* initial layout/mode: TILE MONOCLE BSTACK GRID FLOAT */
#define ATTACH_ASIDE    False     /* False means new window is master */
#define FOLLOW_WINDOW   False     /* follow the window when moved to a different desktop */
#define FOLLOW_MOUSE    False     /* focus the window the mouse just entered */
#define CLICK_TO_FOCUS  False      /* focus an unfocused window when clicked  */
#define FOCUS_BUTTON    Button3   /* mouse button to be used along with CLICK_TO_FOCUS */
#define BORDER_WIDTH    0         /* window border width */
#define FOCUS           "#ff950e" /* focused window border color    */
#define UNFOCUS         "#444444" /* unfocused window border color  */
#define MINWSZ          50        /* minimum window size in pixels  */
#define DEFAULT_DESKTOP 0         /* the desktop to focus initially */
#define DESKTOPS        1         /* number of desktops - edit DESKTOPCHANGE keys to suit */

/**
 * open applications to specified desktop with specified mode.
 * if desktop is negative, then current is assumed
 */
static const AppRule rules[] = { \
    /*  class     desktop  follow  float */
    { "fantasti",     0,    True,   False },
//    { "Gimp",        0,    False,  True  },
};

/* helper for spawning shell commands */
#define SHCMD(cmd) {.com = (const char*[]){"/bin/sh", "-c", cmd, NULL}}

/**
 * custom commands
 * must always end with ', NULL };'
 */
static const char *termcmd[] = { "xterm",     NULL };
static const char *menucmd[] = { "dmenu_run", NULL };

#define DESKTOPCHANGE(K,N) \
    {  MOD1,             K,              change_desktop, {.i = N}}, \
    {  MOD1|ShiftMask,   K,              client_to_desktop, {.i = N}},

/**
 * keyboard shortcuts
 */
static Key keys[] = {
    /* modifier          key            function           argument */
    {  MOD1,             XK_u,          quit,              {.i = 0}}, /* quit with exit value 0 */
    {  MOD1,             XK_k,          killclient,        {NULL}},
    {  MOD1,             XK_space,      next_win,          {NULL}},
    {  MOD1,             XK_Up,         spawn,             SHCMD("brightnessctl -d backlight s 1+") },
    {  MOD1,             XK_Down,       spawn,           SHCMD("brightnessctl -d backlight s 1-") },
    {  MOD1,             XK_Left,       spawn,           SHCMD("amixer set Master 5%-") },
    {  MOD1,             XK_Right,      spawn,           SHCMD("amixer set Master 5%+") }
};

/**
 * mouse shortcuts
 */
static Button buttons[] = {
//    {  MOD1,    Button1,     mousemotion,   {.i = MOVE}},
//    {  MOD1,    Button3,     mousemotion,   {.i = RESIZE}},
    {  MOD4,    Button3,     spawn,         {.com = menucmd}},
};
#endif

/* vim: set expandtab ts=4 sts=4 sw=4 : */
