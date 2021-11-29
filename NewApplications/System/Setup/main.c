#include <ACE.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

#define TEMPBGCOLOR 0xFFFFFF
#define TEMPFGCOLOR 0x222222

#include "lightvdark.xpm"

hWindow *win;

void themeWin() {
	//hideWindow(win);

	hWindow *themeWin = createSubWindow(win, 0, 0, -1, -1, "theme", 0xFFFFFF, 0x000000);

	addTextCentered(themeWin, 0, 10, -1, 40, "Choose a Theme", 0x000000, DFONT("20"));

	addButton(themeWin, -100, -40, 90, 30, "Next", 0x448AFF, 0xFFFFFF, 0, 1, 0, DFONT("20"), NULL, NULL);

	addXPM(themeWin, 0, 40, _a1cb07e80804801de6c52dd4a1bb315Zmh6yxbTGC6MiRyN, 0xFFFFFF, NULL, NULL);

	eventLoop(themeWin, NULL, NULL);
	destroyWindow(themeWin);
}

void nextCallback() {
	//Create a new thread here
	pthread_t thread;
	int err = pthread_create(&thread, NULL, themeWin, NULL);

	if (err) {
		fprintf(stderr, "Error making new thread\n");
		exit(1);
	}
}

int main() {

	char welcomeString[128] = "Hey, ";
	char phoneowner[32];
	putFileInString("/opt/Xenon/phoneowner", phoneowner);
	strcat(welcomeString, phoneowner);
	strcat(welcomeString, "!");
	// Final string should look like: Hey, NAME!

#include "icon.xpm"
	win = createWindow(50, 50, 405, 720, "Settings", TEMPBGCOLOR, TEMPFGCOLOR, 200, 200, 0, icon_xpm, NULL);

	addRectFill(win, 0, 0, -1, 100, 0xEEEEEE);
	addTextCentered(win, 0, 0, -2, 200, "Xenon Setup", TEMPFGCOLOR, DTFONT("40"));

	addTextCentered(win, 0, 200, -1, 250, welcomeString, 0x000000, DFONT("20"));
	addTextBlock(win, 10, 250, -1, 750, "Welcome to your new phone, the phone you recieved is in a beta state so don't expect everything to be perfect. There will be crashes, errors, problems, the whole nine yards. If you have any issues, use the feedback app in your application drawer and I'll get on it as fast as I can. You could also just scream at me on Snapchat but I prefer the feedback app. Sorry that the font looks like garbage right now, this is just an inherint issue with the rendering system of this phone. It'll be fixed soon, and it shouldn't affect Android apps, Just a few things to setup before the phone is yours.", 0x000000, ' ', DTFONT("18"));

	addButton(win, -100, -40, 90, 30, "Next", 0x448AFF, 0xFFFFFF, 0, 1, 0, DFONT("20"), nextCallback, NULL);

	//addButton(win, 10, 300 - scrolloffset, 300, 30, "I am button", TEMPFGCOLOR, TEMPBGCOLOR, 0, 0, 1, DFONT("17"), hideWindowBtnCallback, scr);

	eventLoop(win, NULL, NULL);
	destroyWindow(win);
	return 0;
}
