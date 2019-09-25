// If we run the program, then it will 
// waitpid for the Child2 even if SIGSTOP is sent.  
// If we change the line 61 to kill(pid_c2, SIGTERM);
// then waitpid will return with code 15.
// This means that the description is not true.

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int pid1 = 0;

	// Create pipe between Parent and Child1
	int fd[2];
	pipe(fd);

	printf("Hey, it is Parent. I'm creating Child1\n");
	if(pid1 = fork())
	{
		// Parent
		int pid2 = 0;

		printf("Hey, it is Parent. Child1 id is: %d\n", pid1);
		printf("Hey, it is Parent. I'm creating Child2\n");
		if (pid2 = fork())
		{
			// Parent
			printf("Hey, it is Parent. I'm sending the message via pipe.\n");
			// Write Child2 id to the pipe
			write(fd[1], &pid2, sizeof(pid2));
			int status = -999;
			printf("Hey, it is Parent. I'm starting to wait for any child\n");
			waitpid(pid2, &status, 0);
			printf("Hey, it is Parent. Something happened with Child2. Status is: %d\n", status);
			exit(0);
		}
		else
		{
			// Child2
			printf("Hey, it is Child2. My id is: %d\n", getpid());
			// Do nothing
			while(1)
			{
				printf("Hey, it is Child2. I'm waiting.\n");
				sleep(1);
			}
		}
	}
	else
	{
		// Child1
		printf("Hey, it is Child1. My id is: %d. I'll wait for 2 seconds.\n", getpid());
		sleep(2);
		int pid_c2 = 0;
		// Read message from the pipe
		read(fd[0], &pid_c2, sizeof(pid_c2));
		printf("Hey, it is Child1. I received Child2 id. It is: %d. I'm sending SIGSTOP now. \n", pid_c2);
		// Send SIGSTOP to Child2
		kill(pid_c2, SIGSTOP);		
		exit(0);
	}

	return 0;
}