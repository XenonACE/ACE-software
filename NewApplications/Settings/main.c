#include <ACE.h>
#include <stdio.h>

#define FONT "-misc-montserrat-bold-r-normal--0-0-0-0-p-0-ascii-0"

int main() {
#include "icon.xpm"
	hWindow *win = createWindow(0, 0, 405, 720, "Settings", 0x222222, 0xFFFFFF, 200, 200, 0, icon_xpm, NULL);
	addTextCentered(win, 0, 0, -2, 300, "Settings", 0xFFFFFF, FONT);

	addButton(win, 10, 300, 395, 30, "I am button", 0x222222, 0xFFFFFF, 0, 0, 1, FONT, NULL, NULL);

	eventLoop(win, NULL, NULL);
	destroyWindow(win);
	return 0;
}
