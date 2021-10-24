#include <stdio.h>
#include <stdlib.h>
#include <X11/Xlib.h>

int main() {
	Display *dpy;
	int count_fonts;
	char **font_names;

	if (!(dpy = XOpenDisplay(NULL))) {
		printf("Can't open display\n");
		exit(1);
	}
	
	font_names = XListFonts(dpy, "*", 10000, &count_fonts);

	for (int i = 0; i < count_fonts; i++) {
		fprintf(stderr, "%s\n", *(font_names + i));
	}
	return 0;
}
