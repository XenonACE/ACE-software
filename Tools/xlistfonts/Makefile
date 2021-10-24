CC = gcc

all: xlistfonts

xlistfonts: main.c
	$(CC) -o $@ -lX11 $^

.PHONY: clean install uninstall

clean:
	rm -f xlistfonts

install: xlistfonts
	cp -f xlistfonts /usr/local/bin

uninstall:
	rm -f /usr/local/bin/xlistfonts
