static const char col_gray1[]       = "#2e3440";
static const char col_gray2[]       = "#434c5e";
static const char col_gray3[]       = "#4c566a";
static const char col_gray4[]       = "#d8dee9";
static const char selbordercolor[]  = "#cc241d";
static const char col_cyan[]        = "#5e81ac";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray1 },
	[SchemeSel]  = { col_gray4, col_cyan,  selbordercolor  },
};
