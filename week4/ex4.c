// Use "gcc ex4.c -o ex4 && ./ex4 ex3 pwd" to run ex3 from ex4
// Use "gcc ex4.c -o ex4 && ./ex4 ex1" to run ex1 from ex4

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	if (argc >= 2)
	{
		char* const *newargv = (argv+1);
        char *newenviron[] = {NULL};
			
		if(fork() == 0)
		{
			execve(argv[1], newargv, newenviron);	
		}
	}
	else
	{
		printf("Usage: %s <cmd-to-exec> <args>\n", argv[0]);
	}
	return 0;
}