#include <ACE.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

#define TEMPBGCOLOR 0xFFFFFF
#define TEMPFGCOLOR 0x222222

// This will later be the PID of the child.
pid_t storage;

void child() {
	// Only executed when child of fork()
	
	char *args[] = { "xclock", "-digital", "-update", "1", NULL };
        execvp(args[0], args);

	// Not required because exec replaces process anyways
	exit(0);
}

void killCallback() {
	kill(storage, SIGTERM);
}

void stopCallback() {
	kill(storage, SIGSTOP);
}

void contCallback() {
	kill(storage, SIGCONT);
}

int main() {

	pid_t c_pid = fork();

	if (c_pid == -1) {
		fprintf(stderr, "Failed to fork process\n");
		exit(1);
	}

	if (c_pid == 0)
		child();
	
	storage = c_pid;

#include "icon.xpm"
	hWindow *win = createWindow(50, 50, 405, 720, "Launcher", TEMPBGCOLOR, TEMPFGCOLOR, 200, 200, 0, icon_xpm, NULL);

	addRectFill(win, 0, 0, 405, 720, 0xff4500);
	//addTextCentered(win, 0, 0, -2, 200, "Xenon Setup", fgColor, DTFONT("40"));

	addButton(win, 10, 10, 200, 100,  "Kill", TEMPFGCOLOR, TEMPBGCOLOR, 0, 1, 0, DFONT("30"), killCallback, NULL);
	addButton(win, 10, 120, 200, 100, "Stop", TEMPFGCOLOR, TEMPBGCOLOR, 0, 1, 0, DFONT("30"), stopCallback, NULL);
	addButton(win, 10, 240, 200, 100, "Cont", TEMPFGCOLOR, TEMPBGCOLOR, 0, 1, 0, DFONT("30"), contCallback, NULL);

	//addButton(win, 10, 300 - scrolloffset, 300, 30, "I am button", TEMPFGCOLOR, TEMPBGCOLOR, 0, 0, 1, DFONT("17"), hideWindowBtnCallback, scr);

	eventLoop(win, NULL, NULL);
	destroyWindow(win);
	return 0;
}
