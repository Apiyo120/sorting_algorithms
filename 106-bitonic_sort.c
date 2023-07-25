#include "sort.h"
#include <stdio.h>

/**
 * print_bitonic - Print the bitonic array.
 * @array: The array to print.
 * @start: The start index.
 * @end: The end index.
 */
void print_bitonic(int *array, size_t start, size_t end)
{
	size_t i;

	for (i = start; i < end; i++)
		printf("%d, ", array[i]);

	printf("%d\n", array[i]);
}

/**
 * bitonic_compare - Compare and swap elements in the bitonic sequence.
 * @array: The array to sort.
 * @size: The size of the array.
 * @dir: The direction to sort (1: ascending, 0: descending).
 */
void bitonic_compare(int *array, size_t size, int dir)
{
	size_t distance = size / 2;
	size_t i;

	for (i = 0; i < distance; i++)
	{
		if ((array[i] > array[i + distance]) == dir)
		{
			int temp = array[i];

			array[i] = array[i + distance];
			array[i + distance] = temp;
			print_bitonic(array, 0, size - 1);
		}
	}
}

/**
 * bitonic_sort_recursive - Recursive function to perform bitonic sort.
 * @array: The array to sort.
 * @size: The size of the array.
 * @dir: The direction to sort (1: ascending, 0: descending).
 */
void bitonic_sort_recursive(int *array, size_t size, int dir)
{
	if (size > 1)
	{
		size_t mid = size / 2;

		bitonic_sort_recursive(array, mid, 1);
		bitonic_sort_recursive(array + mid, mid, 0);
		bitonic_compare(array, size, dir);
	}
}

/**
 * bitonic_sort - Sort an array of integers in ascending order
 * using the Bitonic sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array (must be a power of 2).
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	printf("Original array: ");
	print_bitonic(array, 0, size - 1);

	bitonic_sort_recursive(array, size, 1);

	printf("Sorted array: ");
	print_bitonic(array, 0, size - 1);
}
