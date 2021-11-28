CC = gcc

all: setup

setup: main.c
	$(CC) -o $@ $^ -lace -lpthread

.PHONY: clean install uninstall

clean:
	rm -f setup

install: setup
	cp -f setup /usr/local/bin

uninstall:
	rm -f /usr/local/bin/setup
