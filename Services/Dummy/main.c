#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {

	system("startx");

	while(1) {
		printf("Hello, Services!\n");
		sleep(5);
	}

	return 0;

}
