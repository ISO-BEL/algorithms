#include <stdio.h>
#include <stdlib.h>

int *smallest_subarray_sum(int *arr, int size, int key)
{
	int i = 0;
	int j = 0;
	int sum = arr[0];
	while(i < size && sum != key)
	{	if(sum > key && j < i)  	
		{	j++;
			sum -= arr[j - 1]; 
		}
		else if(sum < key || i == j)
		{	i++;
			sum += arr[i];
		}
	}
	if(sum != key)
	{	printf("no subarray with this sum\n");
		return NULL;
	}
	int sub_size = i - j + 1 + 1; 
	int *sub_array = malloc((sizeof *sub_array) * (sub_size));
	
	//0 index used for size
	sub_array[0] = sub_size;
	for(int k = 1; j <= i; j++, k++)
		sub_array[k] = arr[j];
	
	return sub_array;
}
int main(void)
{
	int arr[20] = {12, 31, 4, 4, 4, 6, 12, 6, 1, 4, 6, 32, 5, 2, 5, 1, 5, 1, 5, 7};	
	int *array;
	array = smallest_subarray_sum(arr, 20, 11);
	if(array == NULL) { printf("not preforming operations\n"); }
	else /* only use array inside else */
	{
		int sub_size = array[0];
		for(int i = 1; i < sub_size; i++)
		{	printf("%d,", array[i]);
		}
	}
	free(array);
	return 0;
}
