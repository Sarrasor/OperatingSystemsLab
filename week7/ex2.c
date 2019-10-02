#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int N = 0;
	printf("Enter a positive number\n");
	scanf("%d",&N);

	if(N <= 0)
	{
		printf("I need a positive number\n");
		exit(0);
	}

	int *arr = (int*)malloc(N * sizeof(int));

	if (arr == NULL)
	{
		printf("No memory available\n");
		exit(0);
	}
	else
	{
		for (int i = 0; i < N; ++i)
		{
			arr[i] = i;
			printf("%d ", arr[i]);
		}
		printf("\n");
		free(arr);
	}
	return 0;
}