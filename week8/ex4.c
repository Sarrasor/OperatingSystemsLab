#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/resource.h>

#define N 10
#define TEN_MB (10*1024*1024)

struct rusage usage;

int main(int argc, char const *argv[])
{
	// Create an array in order not to loose memory
	int *mem[N];

	// Allocate memory
	for (int i = 0; i < N; ++i)
	{
		printf("Allocating memory #%d\n", i+1);
		mem[i] = (int*)malloc(10*1024*1024);
		memset(mem[i], 0, 10*1024*1024);
		getrusage(RUSAGE_SELF, &usage);
		printf("%ld\n", usage.ru_maxrss);
		sleep(1);
	}

	printf("Freeing memory\n");
	// Free memory
	for (int i = 0; i < N; ++i)
	{
		free(mem[i]);
	}
	
	return 0;
}