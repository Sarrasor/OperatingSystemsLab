#include <stdio.h>
#include <unistd.h> 

int main(int argc, char const *argv[])
{
	int n = 0;
	int pid = 0;

	if(pid = fork())
	{
		printf("Hello from parent [%d-%d]\n", pid, n);
	}
	else
	{
		printf("Hello from child [%d-%d]\n", pid, n);
	}

	return 0;
}