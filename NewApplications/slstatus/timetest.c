#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "util.h"

char timebuf[80];

const char *
datetime(const char *fmt)
{
	//printf("%i", sizeof(buf));

	time_t t;

	t = time(NULL);
	if (!strftime(timebuf, sizeof(timebuf), fmt, localtime(&t))) {
		printf("strftime: Result string exceeds buffer size\n");
		return NULL;
	}

	return timebuf;
}

int main() {

	//const char * mytime = datetime("%T");
	const char* mytime = "9:20:20";
	char parsedtime[3] = { mytime[0], mytime[1], '\0' };
	int hour = atoi(parsedtime);

	char *halfofday = "AM";

	if (hour > 12) {
		hour = hour - 12;
		halfofday = "PM";
	}

	printf("%i %s", hour, halfofday);

	//printf("%b", );
}
