#include "sort.h"

/**
 * swap - Swaps two integers.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * sift_down - Sift-down operation for the heapify process.
 * @array: The array to be sorted.
 * @size: The size of the array.
 * @start: The starting index for the sift-down process.
 * @end: The ending index for the sift-down process.
 */
void sift_down(int *array, size_t size, size_t start, size_t end)
{
	size_t root = start;

	while (2 * root + 1 <= end)
	{
		size_t child = 2 * root + 1;
		size_t swap_index = root;

		if (array[swap_index] < array[child])
			swap_index = child;

		if (child + 1 <= end && array[swap_index] < array[child + 1])
			swap_index = child + 1;

		if (swap_index == root)
			return;

		swap(&array[root], &array[swap_index]);
		print_array(array, size);
		root = swap_index;
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order
 * using the heap sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
	size_t i;

	for (i = size / 2; i > 0; i--)
		sift_down(array, size, i - 1, size - 1);

	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		sift_down(array, size, 0, i - 1);
	}
}
