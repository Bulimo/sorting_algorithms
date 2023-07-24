#include "sort.h"
#include <stdio.h>

/**
 * counting_sort - sorts an array of integers in
 * ascending order using the Counting sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	int max = 0, j = 0;
	size_t i = 0, index = 0;
	int *count_array, *cum_array;

	if (!array || size < 2)
		return;
	while (i < size)
	{
		if (array[i] > max)
			max = array[i];
		i++;
	}
	count_array = malloc(sizeof(int) * (max + 1));
	if (count_array == NULL)
		return;
	cum_array = malloc(sizeof(int) * (max + 1));
	if (cum_array == NULL)
	{
		free(count_array);
		return;
	}
	while (j <= max)
		count_array[j++] = 0;
	i = 0;
	while (i < size)
		count_array[array[i++]]++;
	for (j = 0; j <= max; j++)
		cum_array[j] = cum_array[j - 1] + count_array[j];
	print_array(cum_array, max + 1);
	for (j = 0; j <= max; j++)
	{
		while (count_array[j] > 0)
		{
			array[index++] = j;
			count_array[j]--;
		}
	}
	free(count_array);
	free(cum_array);
}
