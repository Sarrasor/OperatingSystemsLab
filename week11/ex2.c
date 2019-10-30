#include <stdio.h>
#include <unistd.h>

// Buffer size
#define SIZE 128

int main(int argc, char const *argv[])
{
	// Create buffer
	char buf[SIZE];

	// Change stdout settings
	setvbuf(stdout, buf, _IOLBF, SIZE);

	// Write one character per second
	printf("%c", 'H');
	sleep(1);
	printf("%c", 'e');
	sleep(1);
	printf("%c", 'l');
	sleep(1);
	printf("%c", 'l');
	sleep(1);
	printf("%c", 'o');
	sleep(1);

	return 0;
}