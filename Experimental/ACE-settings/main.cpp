#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>

#include <iostream>
#include <stdlib.h>

#include <cstdio>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>

#include <sstream>

Display *dis;
int screen;
Window win;
GC gc;
unsigned long Black, White, Red, Green, Blue;

void init();
void close();
void draw();
unsigned long RGB(int r, int g, int b);

std::string splitString(char splitter, std::string input, int iterations) {
	std::istringstream iss(input);
	std::string token;

	for (int i = 0; i < iterations; i++) {
		std::getline(iss, token, splitter);
	}

	return token;
}

char* StringToCharArr(std::string inputString) {
	int stringlength = inputString.length();
	char stringArr[stringlength + 1];
	return strcpy(stringArr, inputString.c_str());
}

// C++11 only function
std::string exec(const char* cmd) {
	std::array<char, 128> buffer;
	std::string result;
	std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
	if (!pipe) {
		throw std::runtime_error("popen failed");
	}
	while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
		result += buffer.data();
	}
	return result;
}

void init() {
	dis = XOpenDisplay((char *)0);
	screen = DefaultScreen(dis);
	Black = BlackPixel(dis, screen);
	White = WhitePixel(dis, screen);
	Red = RGB(255, 0, 0);
	Green = RGB(0, 255, 0);
	Blue = RGB(0, 0, 255);
	win = XCreateSimpleWindow(dis, DefaultRootWindow(dis), 0, 0, 300, 300, 5, White, Black);
	XSetStandardProperties(dis, win, "Settings", "noicon", None, NULL, 0, NULL);
	XSelectInput(dis, win, ExposureMask | ButtonPressMask | ButtonReleaseMask | KeyPressMask);
	gc = XCreateGC(dis, win, 0, 0);
	XSetBackground(dis, gc, Black);
	XSetForeground(dis, gc, White);

	XClearWindow(dis, win);
	XMapRaised(dis, win);
}

void close() {
	XFreeGC(dis, gc);
	XDestroyWindow(dis, win);
	XCloseDisplay(dis);
	exit(0);
}

void draw() {
	XClearWindow(dis, win);
}

unsigned long RGB(int r, int g, int b) {
	return b + (g << 8) + (r << 16);
}

int main() {
	init();
	XEvent event;
	KeySym key;
	char text[255];
	while (1) {
		XNextEvent(dis, &event);
		if (event.type == Expose && event.xexpose.count == 0) {
			draw();
			XSetForeground(dis, gc, White);
			XFillRectangle(dis, win, gc, 10, 10, 200, 50);
			XSetForeground(dis, gc, Black);
			const char* msg = "Hello";
			XDrawString(dis, win, gc, 20, 20, msg, strlen(msg));
			XSetForeground(dis, gc, White);
			
			std::string rev = splitString(
					'\n',
					splitString(':', exec("cat /proc/cpuinfo"), 2),
					3
				);


			const char* cmdout = rev.c_str();
			XDrawString(dis, win, gc, 20, 120, cmdout, strlen(cmdout));

			const char* newcmd = exec("uname -r").c_str();
			XDrawString(dis, win, gc, 20, 150, newcmd, strlen(newcmd));
		}

		if (event.type == CreateNotify) {
			std::cout << "CREATION" << std::endl;
		}

		if (event.type == KeyPress && XLookupString(&event.xkey, text, 255, &key, 0) == 1) {
			if (text[0] == 'q') {
				close();
			}
			std::cout << "You pressed " << text[0] << std::endl;
		}

		if (event.type == ButtonPress) {
			int x = event.xbutton.x;
			int y = event.xbutton.y;

			XSetForeground(dis, gc, Red);
			XDrawLine(dis, win, gc, 100, 100, x, y);

			std::string arr[] = {"ha", "e"};
			for (unsigned int i = 0; i < sizeof arr / sizeof arr[0]; i++) {
				std::cout << arr[i] << std::endl;
			}

		}
	}
	return 0;
}
