#include <signal.h>
#include <stdio.h>
#include <unistd.h>
int flag = 1;

void handler(int i)
{
	printf("Received %d. Shutting down.\n", i);
	flag = 0;
}

int main(int argc, char const *argv[])
{
	signal(SIGINT, handler);
	while(flag)
	{
		printf("Doing something\n");
		sleep(2);
	}
	return 0;
}