#include "sort.h"

/**
 * swap_array - swap two integers
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
 * haore_partition - partition the array using Hoare partitioning scheme
 * @array: array to sort
 * @low: lower bound index
 * @high: higher bound index
 * @size: size of the array
 * Return: the pivot index
 */
size_t haore_partition(int *array, size_t low, size_t high, size_t size)
{
	int pivot = array[high];
	size_t j = 0, i = 0, swapped = 0;

	i = low;
	j = high;
	while (i < j)
	{
		while (array[i] <= pivot)
			i++;
		while (array[j] > pivot)
			j--;
		if (i < j)
		{
			swap_array(&array[i], &array[j]);
			swapped++;
			print_array(array, size);
		}
	}
	if (!swapped && i < j)
	{
		j++;
		return (j);
	}
	else if (!swapped && i > j)
	{
		j--;
		return (j);
	}
	else
		return (j);
}

/**
 * quickSortHoare - recursively sort the array using quick sort algorithm
 * @array: array to sort
 * @low: lower bound index
 * @high: higher bound index
 * @size: size of the array
 */
void quickSortHoare(int *array, size_t low, size_t high, size_t size)
{
	size_t pivot_index = 0;

	if (low < high)
	{
		pivot_index = haore_partition(array, low, high, size);
		if (pivot_index > 0)
			quickSortHoare(array, low, pivot_index, size);
		if (pivot_index < size - 1)
			quickSortHoare(array, pivot_index + 1, high, size);
	}
}
/**
 * quick_sort_hoare - implements the quick sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quickSortHoare(array, 0, size - 1, size);
}
