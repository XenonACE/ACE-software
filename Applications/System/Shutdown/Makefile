CC = tcc

all: xe-shutdown

xe-shutdown: main.c
	$(CC) -o $@ `pkg-config gtk+-3.0 --cflags --libs` $^

install: xe-shutdown
	mv $^ /usr/local/bin

.PHONY: clean

clean:
	rm -f shutdown
