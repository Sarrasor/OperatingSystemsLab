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