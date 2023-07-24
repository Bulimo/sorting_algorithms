#include "sort.h"

/**
 * merge_sort - sorts an array implementing Merge sort algorithm
 * @array: array to sort
 * @size: size of the array
*/
void merge_sort(int *array, size_t size)
{
	size_t start = 0;
	size_t stop = size - 1;
	int *b_array = NULL;

	if (!array || size < 2)
		return;

	b_array = malloc(sizeof(int) * size);
	if (!b_array)
		return;
	mergeSort(array, b_array, start, stop);
	free(b_array);
}

/**
 * mergeSort - recursive merge sort algorithm
 * @array: initial array to sort
 * @b_array: place holder for the sorted array
 * @start: starting index of the sub arrrays
 * @stop: stopping index of the sub arrays
*/
void mergeSort(int *array, int *b_array, size_t start, size_t stop)
{
	size_t part = 0, i = start, j = part + 1, k = start;

	if (!array || !b_array || start == stop)
		return;
	part = stop - start;
	part = part % 2 == 0 ? (part - 1) / 2 : part / 2;
	part += start;
	if (start < part)
		mergeSort(array, b_array, start, part);
	if ((part + 1) < stop)
		mergeSort(array, b_array, part + 1, stop);
	puts("Merging...");
	printf("[left]: ");
	print_merge(array, start, part);
	printf("[right]: ");
	print_merge(array, part + 1, stop);
	for (k = start, i = start, j = part + 1; k <= stop; k++)
	{
		if (i <= part && j <= stop)
		{
			if (array[i] < array[j])
				b_array[k] = array[i++];
			else
				b_array[k] = array[j++];
		}
		else if (i <= part)
			b_array[k] = array[i++];
		else
			b_array[k] = array[j++];
	}
	for (k = start; k <= stop; k++)
		array[k] = b_array[k];
	printf("[Done]: ");
	print_merge(array, start, stop);
}

/**
 * print_merge - prints the merged left and right sub arrays
 * @array: array to print
 * @start: starting index to print
 * @stop: last index to print
*/
void print_merge(int *array, size_t start, size_t stop)
{
	for (; start <= stop; start++)
	{
		printf("%d", array[start]);
		if ((start + 1) <= stop)
			printf(", ");
	}
	printf("%s", "\n");
}
