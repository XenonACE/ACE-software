#include <ACE.h>
#include <stdio.h>
#include <pthread.h>

#define TEMPBGCOLOR 0xFFFFFF
#define TEMPFGCOLOR 0x222222

int main() {

	printf("%i\n", getFgColor());

	//int fgColor = getFgColor();
	//int bgColor = getBgColor();

//#include "icon.xpm"
	//hWindow *win = createWindow(50, 50, 405, 720, "Settings", bgColor, fgColor, 200, 200, 0, icon_xpm, NULL);

	//addRect(win, 0, 0, 405, 100, 0xEEEEEE);
	//addTextCentered(win, 0, 0, -2, 200, "Xenon Setup", fgColor, DTFONT("40"));

	//addButton(win, 10, 10, 50, 20, "RIP BOZO", TEMPFGCOLOR, TEMPBGCOLOR, 0, 1, 0, DFONT("10"), NULL, NULL);

	//addButton(win, 10, 300 - scrolloffset, 300, 30, "I am button", TEMPFGCOLOR, TEMPBGCOLOR, 0, 0, 1, DFONT("17"), hideWindowBtnCallback, scr);

	//eventLoop(win, NULL, NULL);
	//destroyWindow(win);
	return 0;
}
