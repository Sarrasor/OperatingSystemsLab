#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define true 1
#define false 0

void bubble_sort(int arr[], int size);

int main(int argc, char const *argv[])
{
	int arr_size = 15;
	int arr[15] = {1, 3, 2, 4, 7, 2, 1, 3, 6, 7, 0, 120, 1, -10, 2};

	for (int i = 0; i < arr_size; ++i) printf("%d ", arr[i]);
	printf("\n");

	bubble_sort(arr, arr_size);

	for (int i = 0; i < arr_size; ++i) printf("%d ", arr[i]);
	printf("\n");
	return 0;
}

void bubble_sort(int arr[], int size)
{
    int swapped, temp;
    for(int i = 0; i < size; ++i)
    {
        swapped = false;
        for(int j = 0; j < size - i - 1; ++j)
        {
            if(arr[j] > arr[j+1]) 
            {
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}