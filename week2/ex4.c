#include <stdio.h>

void swap(int *a, int *b);

int main(int argc, char const *argv[])
{
	int a, b;
	
	printf("Enter the first int: ");
	scanf("%d", &a);
	printf("Enter the second int: ");
	scanf("%d", &b);

	swap(&a, &b);

	printf("First: %d Second: %d\n", a, b);
	return 0;
}

void swap(int *a, int *b)
{
	int temp = *a; 
	*a = *b;
	*b = temp;
}