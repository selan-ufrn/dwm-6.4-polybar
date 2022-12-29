static const char col_gray1[]       = "#1a1826";
static const char col_gray2[]       = "#45475a";
static const char col_gray3[]       = "#585b70";
static const char col_gray4[]       = "#45475a";
static const char selbordercolor[]  = "#a6e3a1";
static const char col_cyan[]        = "#f5c2e7";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray1 },
	[SchemeSel]  = { col_gray4, col_cyan,  selbordercolor  },
};
