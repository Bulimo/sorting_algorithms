#include "sort.h"

/**
 * swap_heap - Swaps two integers
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap_heap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * sift_down - Heapify the heap and maintain the max heap property
 * @array: Array to be sorted
 * @size: Size of the array
 * @idx: Index to start the sift-down process
 * @orig_size: Original size of the array (for printing)
 */
void sift_down(int *array, size_t size, size_t idx, size_t orig_size)
{
	size_t largest = idx;
	size_t left_child = 2 * idx + 1;
	size_t right_child = 2 * idx + 2;

	if (left_child < size && array[left_child] > array[largest])
		largest = left_child;

	if (right_child < size && array[right_child] > array[largest])
		largest = right_child;

	if (largest != idx)
	{
		swap_heap(&array[idx], &array[largest]);
		print_array(array, orig_size);
		sift_down(array, size, largest, orig_size);
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap sort
 * @array: Array to be sorted
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
		sift_down(array, size, i, size);

	for (i = size - 1; i > 0; i--)
	{
		swap_heap(&array[0], &array[i]);
		print_array(array, size);
		sift_down(array, i, 0, size);
	}
}
