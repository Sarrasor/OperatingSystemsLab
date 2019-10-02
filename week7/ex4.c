#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* my_realloc(void *ptr, size_t size);

int main(int argc, char const *argv[])
{
	int N1 = 12, N2 = 10;

	int* arr = (int*)my_realloc(NULL, N1 * sizeof(int));
	
	for (int i = 0; i < N1; ++i)
	{
		arr[i] = i;
		printf("%d ", arr[i]);
	}
	printf("\n");

	arr = (int*)my_realloc((void*)arr, sizeof(int) * N2);

	for (int i = 0; i < N2; ++i)
	{	
		printf("%d ", arr[i]);
	}
	printf("\n");

	my_realloc((void*)arr, 0);
	return 0;
}

void* my_realloc(void *ptr, size_t size)
{
	if (ptr == NULL)
	{
		return malloc(size);
	}
	if (size == 0)
	{
		free(ptr);
		return NULL;
	}

	void* new_ptr = malloc(size);
	if(new_ptr == NULL) return ptr;

	size_t old_size = ((size_t*)ptr)[-1];

	if(size < old_size)
	{
		old_size = size;
	}

	memcpy(new_ptr, ptr, old_size);
	free(ptr);

	return new_ptr;
}
