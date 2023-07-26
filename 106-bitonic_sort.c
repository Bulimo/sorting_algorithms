#include "sort.h"

/**
 * swap_elements - change two values in ascending or descending order
 * @arr: array
 * @index1: index of the first element to swap
 * @index2: index of the second element to swap
 * @ascending: flag to indicate ascending (1) or descending (0) order
 */
void swap_elements(int arr[], int index1, int index2, int ascending)
{
	int temp;

	if (ascending == (arr[index1] > arr[index2]))
	{
		temp = arr[index1];
		arr[index1] = arr[index2];
		arr[index2] = temp;
	}
}

/**
 * recursive_merge - sort bitonic sequences recursively in both orders
 * @arr: array
 * @low: starting index of the sequence
 * @nelemnt: number of elements in the sequence
 * @ascending: flag to indicate ascending (1) or descending (0) order
 */
void recursive_merge(int arr[], int low, int nelemnt, int ascending)
{
	int mid, i;

	if (nelemnt > 1)
	{
		mid = nelemnt / 2;
		for (i = low; i < low + mid; i++)
			swap_elements(arr, i, i + mid, ascending);
		recursive_merge(arr, low, mid, ascending);
		recursive_merge(arr, low + mid, mid, ascending);
	}
}

/**
 * bitonic_sort_recursive - bitonic sort
 * algorithm implementation (recursive version)
 * @arr: array
 * @low: starting index of the subarray to sort
 * @nelemnt: number of elements in the subarray
 * @ascending: flag to indicate ascending (1) or descending (0) order
 * @size: array length
 */
void bitonic_sort_recursive(int arr[], int low,
							int nelemnt, int ascending, int size)
{
	int mid;

	if (nelemnt > 1)
	{
		if (ascending == 1)
		{
			printf("Merging [%i/%i] (UP):\n", nelemnt, size);
			print_array(&arr[low], nelemnt);
		}
		else
		{
			printf("Merging [%i/%i] (DOWN):\n", nelemnt, size);
			print_array(&arr[low], nelemnt);
		}

		mid = nelemnt / 2;
		bitonic_sort_recursive(arr, low, mid, 1, size);
		bitonic_sort_recursive(arr, low + mid, mid, 0, size);
		recursive_merge(arr, low, nelemnt, ascending);

		if (ascending == 0)
		{
			printf("Result [%i/%i] (DOWN):\n", nelemnt, size);
			print_array(&arr[low], nelemnt);
		}
		if (ascending == 1)
		{
			printf("Result [%i/%i] (UP):\n", nelemnt, size);
			print_array(&arr[low], nelemnt);
		}
	}
}

/**
 * bitonic_sort - perform the bitonic sort algorithm
 * @array: array to be sorted
 * @size: number of elements in the array
 */
void bitonic_sort(int *array, size_t size)
{
	int ascending = 1;

	if (!array || size < 2)
		return;

	bitonic_sort_recursive(array, 0, size, ascending, size);
}
