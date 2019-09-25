#include <stdio.h>
#include <unistd.h> 

#define SIZE 30

int main(int argc, char const *argv[])
{
	char s1[SIZE] = "Message";
	char s2[SIZE]; 

	int fd[2];
	pipe(fd);

	write(fd[1], s1, SIZE);

	read(fd[0], s2, SIZE);

	printf("%s\n", s2);
	return 0;
}