#include <stdio.h>
#include <stdlib.h>
//#include quicksort function
//
int partition(int *arr, int low, int high);
void quicksort(int *arr, int low, int high);
void swap(int *a, int *b);

int main(void)
{
	int arr[10] = {1, 3, 64, 2, 52, 12, 34, 43, 21, 14};
	int size = sizeof arr / sizeof *arr;
	
	quicksort(arr, 0, size - 1);
	for(int i = 0; i < size; i++)
	{
		printf("[%d] ", arr[i]);
	}

	exit(0);
}

int partition(int *arr, int low, int high)
{
	int pivot = arr[high];

	int i = low - 1;

	for(int j = low; j < high; j++)
		if(arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	
	swap(&arr[i + 1], &arr[high]);
	return i + 1; //return new pivot location
}
void quicksort(int *arr, int low, int high)
{
	if(low < high)
	{
		int pivot = partition(arr, low, high);						
		
		quicksort(arr, low, pivot - 1);
		quicksort(arr, pivot + 1, high);
	}
}
void swap(int *a, int *b)
{
	int swap = *a;
	*a = *b;
	*b = swap;
}
