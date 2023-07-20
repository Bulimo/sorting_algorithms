#include "sort.h"

/**
 * bubble_sort - sorts array of integers using bubblesort algorithm
 * @array: Array of integers
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0;
	size_t j;
	int swapped;
	int temp;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapped = 1;
				print_array(array, size);
			}
		}
		if (!swapped)
			break;
	}
}
