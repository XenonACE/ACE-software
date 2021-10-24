CC = gcc

all: settings

settings: main.c
	$(CC) -o $@ -lace $^

.PHONY: clean install uninstall

clean:
	rm -f settings

install: settings
	cp -f settings /usr/local/bin

uninstall:
	rm -f /usr/local/bin/settings
