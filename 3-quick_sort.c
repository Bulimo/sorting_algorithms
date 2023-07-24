#include "sort.h"

/**
 * swap - swap two integers
 * @a: first integer
 * @b: second integer
 */
void swap_array(int *a, int *b)
{
	int temp = 0;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition - partition the array using Lomuto partitioning scheme
 * @array: array to sort
 * @low: lower bound index
 * @high: higher bound index
 * @size: size of the array
 * Return: the pivot index
 */
size_t partition(int *array, size_t low, size_t high, size_t size)
{
	int pivot = array[high];
	size_t j = low, i = 0;

	for (i = low; i < high; i++)
	{
		if (array[i] <= pivot)
		{
			if (i != j)
			{
				swap_array(&array[i], &array[j]);
				print_array(array, size);
			}
			j++;
		}
	}
	if (j != high)
	{
		swap_array(&array[j], &array[high]);
		print_array(array, size);
	}
	return (j);
}

/**
 * quickSort - recursively sort the array using quick sort algorithm
 * @array: array to sort
 * @low: lower bound index
 * @high: higher bound index
 * @size: size of the array
 */
void quickSort(int *array, size_t low, size_t high, size_t size)
{
	size_t pivot_index = 0;

	if (low < high)
	{
		pivot_index = partition(array, low, high, size);

		if (pivot_index > 0)
			quickSort(array, low, pivot_index - 1, size);
		if (pivot_index < size - 1)
			quickSort(array, pivot_index + 1, high, size);
	}
}
/**
 * quick_sort - implements the quick sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size <= 1)
		return;

	quickSort(array, 0, size - 1, size);
}
