#include "sort.h"

/**
 * swap - Swaps two integers.
 * @a: First integer.
 * @b: Second integer.
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bitonic_compare - Compares and swaps two integers based on the bitonic sequence.
 * @array: The array to sort.
 * @size: Size of the array.
 * @dir: The direction of sorting (1 for ascending, 0 for descending).
 * @i: Current index.
 */
void bitonic_compare(int *array, size_t size, int dir, size_t i)
{
	if (dir == (array[i] > array[i + size]))
		swap(&array[i], &array[i + size]);
}

/**
 * bitonic_merge - Merges two bitonic sequences.
 * @array: The array to sort.
 * @size: Size of the array.
 * @dir: The direction of sorting (1 for ascending, 0 for descending).
 */
void bitonic_merge(int *array, size_t size, int dir)
{
	size_t i;

	if (size > 1)
	{
		size_t mid = size / 2;
		for (i = 0; i < mid; i++)
			bitonic_compare(array, mid, dir, i);
		bitonic_merge(array, mid, dir);
		bitonic_merge(array + mid, mid, dir);
	}
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order using the
 * Bitonic sort algorithm.
 * @array: The array to sort.
 * @size: Size of the array (must be a power of 2).
 */
void bitonic_sort(int *array, size_t size)
{
	size_t step;
	size_t i;
	int dir;

	if (array == NULL || size < 2)
		return;

	printf("Original array: ");
	print_array(array, size);

	for (step = 2; step <= size; step *= 2)
	{
		for (i = 0; i < size; i += step)
		{
			dir = (i / step) % 2 == 0;
			bitonic_merge(array + i, step / 2, dir);
		}
		printf("Result [%lu/%lu] (%s):\n", step, size, (step == size) ? "UP" : "DOWN");
		print_array(array, size);
	}
	printf("Sorted array: ");
	print_array(array, size);
}
