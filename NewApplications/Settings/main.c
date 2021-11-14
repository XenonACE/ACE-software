#include <ACE.h>
#include <stdio.h>

void hideWindowBtnCallback(hWidget *w, hWidget *scr) {
	printf("Hello, World!\n");
}

void recalculateScroll(hWidget *w, hWidget *scr) {
	printf("%f\n", scr->pos);
}

int main() {
#include "icon.xpm"

	int scrolloffset = 0;

	int bgColor = 0x222222;
	//int fgColor = getFgColor();

	hWindow *win = createWindow(50, 50, 405, 720, "Settings", 0x222222, 0xFFFFFF, 200, 200, 0, icon_xpm, NULL);
	addTextCentered(win, 0, 0, -2, 300, "Settings", 0xFFFFFF, DTFONT("40"));

	hWidget *scr = (hWidget*)addVScroll(win, -10, 0, 10, 720, 0x222222, 0x222222, 0x000000, 0, 0.5, recalculateScroll, NULL);

	addButton(win, 10, 300 - scrolloffset, 300, 30, "I am button", 0x222222, 0xFFFFFF, 0, 0, 1, DFONT("17"), hideWindowBtnCallback, scr);

	eventLoop(win, NULL, NULL);
	destroyWindow(win);
	return 0;
}
