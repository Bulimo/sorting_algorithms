#include "sort.h"

/**
 * selection_sort - sort array in using selection sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j = 0, min = 0;
	int temp = 0;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[min] > array[j])
				min = j;
		}
		 if (min == i)
			continue;
		temp = array[i];
		array[i] = array[min];
		array[min] = temp;
		print_array(array, size);
	}
}
