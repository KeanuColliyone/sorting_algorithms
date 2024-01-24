#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * merge_sort - Sorts an array of integers in ascending order using
 *              the Merge sort algorithm
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	divide_and_merge(array, size);
}

/**
 * divide_and_merge - Recursively divides and merges the array
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */
void divide_and_merge(int *array, size_t size)
{
	size_t mid, i;
	int *left, *right;

	if (size < 2)
		return;

	mid = size / 2;

	left = array;
	right = array + mid;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, mid);
	printf("[right]: ");
	print_array(right, size - mid);

	divide_and_merge(left, mid);
	divide_and_merge(right, size - mid);

	merge(array, mid, size);
	printf("[Done]: ");
	print_array(array, size);
}

/**
 * merge - Merges two sorted arrays
 * @array: Pointer to the array to be merged
 * @mid: Index marking the start of the right array
 * @size: Size of the array
 */
void merge(int *array, size_t mid, size_t size)
{
	size_t i, j, k;
	size_t left_size = mid;
	size_t right_size = size - mid;
	int *left, *right;

	left = malloc(left_size * sizeof(int));
	right = malloc(right_size * sizeof(int));

	if (!left || !right)
	{
		free(left);
		free(right);
		return;
	}

	for (i = 0; i < left_size; i++)
		left[i] = array[i];

	for (j = 0; j < right_size; j++)
		right[j] = array[mid + j];

	i = j = 0;
	k = 0;

	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
			array[k++] = left[i++];
		else
			array[k++] = right[j++];
	}

	while (i < left_size)
		array[k++] = left[i++];

	while (j < right_size)
		array[k++] = right[j++];

	free(left);
	free(right);
}

