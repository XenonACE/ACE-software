#define KEYS 44
static Key keys_en[KEYS] = {
	{ 0, 0, XK_q, 1 },
	{ 0, 0, XK_w, 1 },
	{ 0, 0, XK_e, 1 },
	{ 0, 0, XK_r, 1 },
	{ 0, 0, XK_t, 1 },
	{ 0, 0, XK_y, 1 },
	{ 0, 0, XK_u, 1 },
	{ 0, 0, XK_i, 1 },
	{ 0, 0, XK_o, 1 },
	{ 0, 0, XK_p, 1 },

	{ 0 }, // New row

	{ "", 0, XK_Shift_L|XK_bar, 1 }, // Blank
	{ 0, 0, XK_a, 1 },
	{ 0, 0, XK_s, 1 },
	{ 0, 0, XK_d, 1 },
	{ 0, 0, XK_f, 1 },
	{ 0, 0, XK_g, 1 },
	{ 0, 0, XK_h, 1 },
	{ 0, 0, XK_j, 1 },
	{ 0, 0, XK_k, 1 },
	{ 0, 0, XK_l, 1 },
	{ "", 0, XK_Shift_L|XK_bar, 1 }, // Blank

	{ 0 }, // New row

	{ "ﰶ", 0, XK_Shift_L, 2 },
	{ 0, 0, XK_z, 1 },
	{ 0, 0, XK_x, 1 },
	{ 0, 0, XK_c, 1 },
	{ 0, 0, XK_v, 1 },
	{ 0, 0, XK_b, 1 },
	{ 0, 0, XK_n, 1 },
	{ 0, 0, XK_m, 1 },
	{ "", 0, XK_BackSpace, 2 },

	{ 0 }, // New row

	{ "", 0, XK_Cancel, 1 }, // Cycle Layer
	{ ",", 0, XK_comma, 1 },
	{ "", 0, XK_space, 3 },
	{ ".", 0, XK_period, 1 },
	{ "↲", 0, XK_Return, 1  },

};

static Key keys_symbols[KEYS] = {
	{ "1", 0, XK_1, 1 },
	{ "2", 0, XK_2, 1 },
	{ "3", 0, XK_3, 1 },
	{ "4", 0, XK_4, 1 },
	{ "5", 0, XK_5, 1 },
	{ "6", 0, XK_6, 1 },
	{ "7", 0, XK_7, 1 },
	{ "8", 0, XK_8, 1 },
	{ "9", 0, XK_9, 1 },
	{ "0", 0, XK_0, 1 },

	{ 0 }, // New row

	{ "@", 0, XK_at, 1 },
	{ "#", 0, XK_numbersign, 1 },
	{ "$", 0, XK_dollar, 1 },
	{ "&", 0, XK_Shift_L|XK_ampersand, 1 },
	{ "_", 0, XK_underscore, 1},
	{ "-", 0, XK_minus, 1},
	{ "(", 0, XK_parenleft, 1 },
	{ ")", 0, XK_parenright, 1},
	{ "=", 0, XK_equal, 1 },
	{ "%", 0, XK_percent, 1 },

	{ 0 }, // New row

	{ "", 0, XK_Shift_L|XK_bar, 1 }, // Blank
	{ "\"", 0, XK_quotedbl, 1 },
	{ "*", 0, XK_asterisk, 1 },
	{ "'", 0, XK_apostrophe, 1 },


};
static Key keys_extras[KEYS] = {};

Buttonmod buttonmods[] = {
	{ XK_Shift_L, Button2 },
	{ XK_Alt_L, Button3 },
};

#define OVERLAYS 1
static Key overlay[OVERLAYS] = {
	{ 0, 0, XK_Cancel },
};

#define LAYERS 2
static char* layer_names[LAYERS] = {
	"en",
	"symbols",
	//"extras",
};

static Key* available_layers[LAYERS] = {
	keys_en,
	keys_symbols,
	//keys_extras,
};
