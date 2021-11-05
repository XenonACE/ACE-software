CC = gcc
VERSION = 0.1

all: test

test: main.c
	$(CC) -lace `pkg-config --cflags --libs freetype2` -o $@ $<

.PHONY: clean

clean:
	rm -f test
