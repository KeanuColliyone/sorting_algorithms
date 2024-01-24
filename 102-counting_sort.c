#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order
 *                 using the Counting sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void counting_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;

	int max = array[0];
	
	for (size_t i = 1; i < size; ++i)
	{
		if (array[i] > max)
			max = array[i];
	}

	int *count = malloc((max + 1) * sizeof(int));
	if (count == NULL)
		return;

	for (int i = 0; i <= max; ++i)
		count[i] = 0;

	for (size_t i = 0; i < size; ++i)
		count[array[i]]++;

	print_array(count, max + 1);
    
	size_t i = 0;
	for (int j = 0; j <= max; ++j)
	{
		while (count[j] > 0)
		{
			array[i++] = j;
			count[j]--;
		}
	}

	free(count);
}

