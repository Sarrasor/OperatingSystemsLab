// Use "gcc ex3.c -o ex3 && ./ex3 <cmd>" to run <cmd> from shell  

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	if(argc == 2)
	{
		char *comands = "pwd,ls,top,pstree,";

		char *arg = malloc(strlen(argv[1])+2);
		strcpy(arg, argv[1]);
		strcat(arg, ",");

		if (strlen(argv[1]) != 1 && strstr(comands, arg))
		{
			system(argv[1]);
		}
		else
		{
			printf("Something went wrong. I need one argument from this list:\n");
			printf("pwd ls top pstree\n");
		}
		free(arg);
	}
	else
	{
		printf("Usage: %s <cmd-to-exec>\n", argv[0]);
	}

	return 0;
}