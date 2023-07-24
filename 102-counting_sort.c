#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - Sorts an array of integers using Counting sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *output, *counting;
	int max_value, i, j;

	if (array == NULL || size < 2)
		return;

	max_value = array[0];
	for (i = 1; i < (int)size; i++)
	{
		if (array[i] > max_value)
			max_value = array[i];
	}

	counting = malloc(sizeof(int) * (max_value + 1));
	if (counting == NULL)
		return;
	for (i = 0; i <= max_value; i++)
		counting[i] = 0;
	for (i = 0; i < (int)size; i++)
		counting[array[i]]++;
	for (i = 1; i <= max_value; i++)
		counting[i] += counting[i - 1];

	output = malloc(sizeof(int) * size);
	if (output == NULL)
	{
		free(counting);
		return;
	}
	for (i = size - 1; i >= 0; i--)
	{
		j = counting[array[i]] - 1;
		output[j] = array[i];
		counting[array[i]]--;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = output[i];

	free(counting);
	free(output);
}
