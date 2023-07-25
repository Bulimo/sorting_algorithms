#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int array[] = {19, 7, 45, 9, 60, 40, 33, 42, 41, 51, 58, 59, 23, 85, 70, 27, 47, 1, 77, 66, 2, 36, 98, 21, 99, 92, 15, 3, 90, 75, 38, 32, 19, 20, 35, 50, 57, 4, 46, 43, 96, 68, 6, 65, 81, 22, 8, 24, 34, 97, 89, 94};
	size_t n = sizeof(array) / sizeof(array[0]);

	print_array(array, n);
	printf("\n");
	radix_sort(array, n);
	printf("\n");
	print_array(array, n);
	return (0);
}
