#include "sort.h"

/**
 * swap - Swaps two elements in an array.
 *
 * @array: The array containing the elements.
 * @idx1: Index of the first element to swap.
 * @idx2: Index of the second element to swap.
 */
void swap(int *array, int idx1, int idx2)
{
	int temp = array[idx1];

	array[idx1] = array[idx2];

	array[idx2] = temp;
}

/**
 * lomuto_partition - Lomuto partition scheme for Quick sort.
 *
 * @array: The array to be sorted.
 * @low: Lower index of the partition.
 * @high: Higher index of the partition.
 *
 * Return: Index of the pivot element.
 */
int lomuto_partition(int *array, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(array, i, j);
				print_array(array, high + 1);
			}
		}
	}

	if (array[i + 1] != array[high])
	{
		swap(array, i + 1, high);
		print_array(array, high + 1);
	}
	return (i + 1);
}

/**
 * quick_sort_recursive - Recursive helper function for Quick sort.
 *
 * @array: The array to be sorted.
 * @low: Lower index of the partition.
 * @high: Higher index of the partition.
 */
void quick_sort_recursive(int *array, int low, int high)
{
	int pivot_idx;

	if (low < high)
	{
		pivot_idx = lomuto_partition(array, low, high);

		quick_sort_recursive(array, low, pivot_idx - 1);
		quick_sort_recursive(array, pivot_idx + 1, high);

	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using Quick sort algorithm (Lomuto partition).
 *
 * @array: The array to be sorted.
 * @size: Number of elements in the array.
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1);
}

