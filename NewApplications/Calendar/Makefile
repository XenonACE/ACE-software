CC = tcc

all: calendar

calendar: main.c
	$(CC) -o $@ `pkg-config gtk+-3.0 --cflags --libs` $^

.PHONY: clean

clean:
	rm -f shutdown
