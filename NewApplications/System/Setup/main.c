#include <ACE.h>
#include <stdio.h>

#define TEMPBGCOLOR 0xFFFFFF
#define TEMPFGCOLOR 0x222222

int main() {
#include "icon.xpm"
	hWindow *win = createWindow(50, 50, 405, 720, "Settings", TEMPFGCOLOR, TEMPBGCOLOR, 200, 200, 0, icon_xpm, NULL);

	addRect(win, 0, 0, 405, 100, 0xEEEEEE);
	addTextCentered(win, 0, 0, -2, 200, "Xenon Setup", TEMPBGCOLOR, DTFONT("40"));

	//addButton(win, 10, 300 - scrolloffset, 300, 30, "I am button", TEMPFGCOLOR, TEMPBGCOLOR, 0, 0, 1, DFONT("17"), hideWindowBtnCallback, scr);

	eventLoop(win, NULL, NULL);
	destroyWindow(win);
	return 0;
}
