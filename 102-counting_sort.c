#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order
 *                 using the Counting sort algorithm.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
	int *counting_array, *output_array;
	size_t i, max_element = 0;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size; i++)
	{
		if ((size_t)array[i] > max_element)
			max_element = array[i];
	}
	counting_array = malloc((max_element + 1) * sizeof(int));

	if (counting_array == NULL)
		return;

	for (i = 0; i <= max_element; i++)
		counting_array[i] = 0;

	for (i = 0; i < size; i++)
		counting_array[array[i]]++;

	for (i = 1; i <= max_element; i++)
		counting_array[i] += counting_array[i - 1];

	output_array = malloc(size * sizeof(int));

	if (output_array == NULL)
	{
		free(counting_array);
		return;
	}

	for (i = size - 1; (int)i >= 0; i--)
	{
		output_array[counting_array[array[i]] - 1] = array[i];
		counting_array[array[i]]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output_array[i];

	free(counting_array);
	free(output_array);
}
