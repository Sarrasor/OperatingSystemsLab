#include <signal.h>
#include <stdio.h>
#include <unistd.h>


int main(int argc, char const *argv[])
{
	int pid = 0;
	if(pid = fork())
	{
		// Parent
		printf("Hey, it is parent. I'll wait for 10 seconds.\n");
		sleep(10);
		kill(pid ,SIGTERM);
		printf("Ok, child is dead now. I'm terminating.	\n");
	}
	else
	{
		// Child
		while(1)
		{
			printf("I'm alive\n");
			sleep(1);	
		} 
	}

	return 0;
}