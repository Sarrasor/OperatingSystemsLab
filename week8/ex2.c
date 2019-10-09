#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#define N 10
#define TEN_MB (10*1024*1024)

int main(int argc, char const *argv[])
{
	// Create an array in order not to loose memory
	int *mem[N];

	// Allocate memory
	for (int i = 0; i < N; ++i)
	{
		// printf("Allocating memory #%d\n", i+1);
		mem[i] = (int*)malloc(TEN_MB);
		memset(mem[i], 0, TEN_MB);
		sleep(1);
	}

	// printf("Freeing memory\n");
	// Free memory
	for (int i = 0; i < N; ++i)
	{
		free(mem[i]);
	}

	return 0;
}