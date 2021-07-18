static const Bool wmborder = True;
static int fontsize = 22;
static double overlay_delay = 1.0; //in seconds
static double repeat_delay = 0.75; //in seconds, will not work on keys with overlays
static int scan_rate = 50; //scan rate in microseconds, affects key repetition rate
static int heightfactor = 14; //one row of keys takes up 1/x of the screen height
static const char *defaultfonts[] = {
	"CaskaydiaCove Nerd Font Mono:bold:size=22"
};
static const char *defaultcolors[SchemeLast][2] = {
				/*    fg          bg     */
	[SchemeNorm] =           { "#ffffff", "#00bcd5" },
	[SchemeNormShift] =      { "#ffffff", "#00bcd5" },
	[SchemeNormABC] =        { "#ffffff", "#00bcd5" }, // done
	[SchemeNormABCShift] =   { "#ffffff", "#007e8e" }, // done
	[SchemePress] =          { "#ffffff", "#007e8e" },
	[SchemePressShift] =     { "#ffffff", "#007e8e" },
	[SchemeHighlight] =      { "#ffffff", "#007e8e" },
	[SchemeHighlightShift] = { "#ffffff", "#007e8e" },
	[SchemeOverlay] =        { "#ffffff", "#007e8e" },
	[SchemeOverlayShift] =   { "#ffffff", "#007e8e" },
};

