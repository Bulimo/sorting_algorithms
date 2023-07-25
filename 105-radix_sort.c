#include "sort.h"

/**
 * radix_sort - function that sorts an array using Radix sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max = 0, k = 1, n = 0, j = 0;
	int *counter = NULL, *b_array = NULL;
	size_t count_size = 9, i = 0;

	if (!array || size < 2)
		return;
	counter = malloc(sizeof(int) * (count_size + 1));
	if (!counter)
		return;
	b_array = malloc(sizeof(int) * size);
	if (!b_array)
	{
		free(counter);
		return;
	}
	max = array[0];
	for (i = 0; i < size; i++)
		max = (array[i] > max) ? array[i] : max;
	for (k = 1; (max / k) > 0; k *= 10)
	{
		for (i = 0; i <= count_size; i++)
			counter[i] = 0;
		for (i = 0; i < size; i++)
		{
			n = (array[i] / k) % 10;
			counter[n]++;
		}
		for (i = 1; i <= count_size; i++)
			counter[i] += counter[i - 1];
		for (j = size - 1; j >= 0; j--)
		{
			n = (array[j] / k) % 10;
			b_array[--counter[n]] = array[j];
		}
		for (i = 0; i < size; i++)
			array[i] = b_array[i];
		print_array(array, size);
	}
	free(counter);
	free(b_array);
}
