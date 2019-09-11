#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
	int n = 3;
	for (int i = 0; i < n; ++i)
	{
		fork();
		sleep(5);
	}
	return 0;
}