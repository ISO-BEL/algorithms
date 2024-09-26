#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <unistd.h>

//check if min or max index is on the key?? //maybe for large data
//assume sorted
int binary_search(uint8_t *a, int key, int min, int max)
{
	while(min < max && max > 0)
	{
		int center = min + (max - min) / 2;
		if(a[center] == key)
			return center;

		if(a[center] > key){
			min = center + 1;
			continue;
		}
		else{
			min = center + 1; 
			continue;
		}
	}	
	return -1;
}
int binary_search_recursive(uint8_t *a int key, int min, int max)
{
	int center = min + (max - min) / 2;
	if(min > max) return -1;
	if(a[center] == key)
		return center;

	if(a[center] > key){
		min = center + 1;
		binary_search_recursive(a, key, min, max);
	}
	else{
		max = center - 1;
		binary_search_recursive(a, key, min, max);
	}
}
void insertion_sort(uint8_t *a, int size)
{
	int swap = 0;
	for(int i = 0; i < size - 1; i++)
		for(int j = i + 1; j < size; j++)
		{
			if(a[j] < a[i])
			{
				swap = a[j];
				a[j] = a[i];
				a[i] = swap;
			}
		}
}
int main(void)
{
	int i;
	int key = 12;
	int status;
	uint8_t arr[10];
	int size = sizeof arr / sizeof *arr;
	
	//generate random-ish array for fun
	for(i = 0; i < size; i++)
	{
		sleep(1);	
		srand(time(0) );
		arr[i] = rand() % 20; 
		if(i % 5 == 0)
			printf("\n[ %d ], ", arr[i]);
		else
			printf("[ %d ], ", arr[i]);
	}
	insertion_sort(arr, size);
	status = binary_search(arr, key, 0, size);
	if(status == -1){
		fprintf(stderr, "key:%d not found in random array\n", key); 
	}
	
	return 0;	
}
