#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order
 * using the Counting sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
	int *counting_array, *output_array;
	int max_value = 0;
	size_t i;

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		if (array[i] > max_value)
			max_value = array[i];
	}

	counting_array = malloc((max_value + 1) * sizeof(int));
	output_array = malloc(size * sizeof(int));
	if (counting_array == NULL || output_array == NULL)
	{
		free(counting_array);
		free(output_array);
		return;
	}
	for (i = 0; i <= (size_t)max_value; i++)
		counting_array[i] = 0;
	for (i = 0; i < size; i++)
		counting_array[array[i]]++;
	printf("0");
	for (i = 1; i <= (size_t)max_value; i++)
		printf(", %d", counting_array[i]);
	printf("\n");
	for (i = 1; i <= (size_t)max_value; i++)
		counting_array[i] += counting_array[i - 1];
	for (i = 0; i < size; i++)
	{
		output_array[counting_array[array[i]] - 1] = array[i];
		counting_array[array[i]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = output_array[i];
	free(counting_array);
	free(output_array);
}
