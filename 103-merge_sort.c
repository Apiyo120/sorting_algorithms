#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * merge - Merges two sub-arrays into a sorted array.
 *
 * @array: The original array.
 * @left: Pointer to the left sub-array.
 * @left_size: Size of the left sub-array.
 * @right: Pointer to the right sub-array.
 * @right_size: Size of the right sub-array.
 */
void merge(int *array, int *left, size_t left_size,
		int *right, size_t right_size)
{
	size_t i = 0, j = 0, k = 0;
	int *temp_array;

	printf("Merging...\n[left]: ");
	print_array(left, left_size);
	printf("[right]: ");
	print_array(right, right_size);

	temp_array = malloc((left_size + right_size) * sizeof(int));
	if (temp_array == NULL)
		return;

	while (i < left_size && j < right_size)

	{
		if (left[i] <= right[j])
			temp_array[k++] = left[i++];
		else
			temp_array[k++] = right[j++];
	}

	while (i < left_size)
		temp_array[k++] = left[i++];

	while (j < right_size)
		temp_array[k++] = right[j++];

	for (i = 0; i < left_size + right_size; i++)
		array[i] = temp_array[i];

	printf("[Done]: ");
	print_array(array, left_size + right_size);

	free(temp_array);
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 *              using the Merge sort algorithm.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
	size_t mid = size/2;
	int *left_half;
	int *right_half = array + mid;

	if (size < 2)
		return;

	left_half = array;
	right_half = array + mid;

	merge_sort(left_half, mid);
	merge_sort(right_half, size - mid);

	merge(array, left_half, mid, right_half, size - mid);
}
