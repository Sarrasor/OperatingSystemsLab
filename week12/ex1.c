#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define SIZE 20

int main(int argc, char const *argv[])
{
	// Create buffer for random string
	char buf[SIZE+1];
	buf[SIZE] = '\0';

	// Open the requred files
	int randomFile = open("/dev/random", O_RDONLY);
	FILE *out = fopen ("ex1.txt","w");

	if (out == NULL)
	{
		printf("Error when opening the output file\n");
		return -1;
	}

	if (randomFile < 0)
	{
		printf("Error when opening the /dev/random\n");
		return -1;
	}


	ssize_t length = read(randomFile, buf, SIZE);
	printf("%ld\n", length);
	printf("%s\n", buf);

	fputs(buf, out);

	fclose(out);

	return 0;
}