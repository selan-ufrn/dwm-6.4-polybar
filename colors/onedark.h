static const char sel_fg[]          = "#282C34"; // gray4
static const char sel_bg[]          = "#E06C75"; // cyan
static const char norm_fg[]         = "#ABB2BF"; // gray3
static const char norm_bg[]         = "#282C34"; // gray1

static const char norm_border[]     = "#ABB2BF"; // gray2
static const char sel_border[]      = "#cc241d"; // selbordercolor
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm]  = { norm_fg,   norm_bg,   norm_border},
	[SchemeSel]   = { sel_fg,    sel_bg,    sel_border },
};

// static const char col_gray1[]       = "#222222";
// static const char col_gray2[]       = "#444444";
// static const char col_gray3[]       = "#bbbbbb";
// static const char col_gray4[]       = "#eeeeee";
// static const char col_cyan[]        = "#005577";
// static const char *colors[][3]      = {
// 	/*               fg         bg         border   */
// 	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
// 	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
// };
