#include <stdio.h>
#include <unistd.h> 

#define SIZE 30

int main(int argc, char const *argv[])
{
	int pid = 0;

	int fd[2];
	pipe(fd);

	if(pid = fork())
	{
		// Parent
		char s1[SIZE] = "Message";
		write(fd[1], s1, SIZE);
	}
	else
	{
		// Child
		char s2[SIZE]; 
		read(fd[0], s2, SIZE);
		printf("%s\n", s2);
	}

	return 0;
}