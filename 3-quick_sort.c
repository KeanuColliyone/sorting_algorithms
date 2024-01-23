#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order using
 *              the Quick sort algorithm with Lomuto partition scheme
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;

	recursive_quick_sort(array, 0, size - 1, size);
}

/**
 * recursive_quick_sort - Recursive function to perform Quick sort
 * @array: Pointer to the array to be sorted
 * @low: Lower bound index of the partition
 * @high: Upper bound index of the partition
 * @size: Size of the array
 */
void recursive_quick_sort(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = lomuto_partition(array, low, high, size);

		recursive_quick_sort(array, low, pivot - 1, size);
		recursive_quick_sort(array, pivot + 1, high, size);
	}
}

/**
 * lomuto_partition - Lomuto partition scheme for Quick sort
 * @array: Pointer to the array to be sorted
 * @low: Lower bound index of the partition
 * @high: Upper bound index of the partition
 * @size: Size of the array
 *
 * Return: The index of the pivot element after partitioning
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j, temp;

	pivot = array[high];
	i = low - 1;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;

			print_array(array, size);
		}
	}

	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;

	print_array(array, size);

	return (i + 1);
}

