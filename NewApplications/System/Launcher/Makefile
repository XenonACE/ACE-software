CC = gcc

all: launcher

launcher: main.c
	$(CC) -o $@ $^ -lace -lpthread

.PHONY: clean install uninstall

clean:
	rm -f launcher

install: launcher
	cp -f launcher /usr/local/bin

uninstall:
	rm -f /usr/local/bin/launcher
