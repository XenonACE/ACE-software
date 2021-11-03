CC = gcc

all: toast

toast: main.c
	$(CC) -o $@ $^ -lX11

.PHONY: clean

clean:
	rm -f toast
