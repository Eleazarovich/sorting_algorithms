#include "sort.h"

/**
 * swap2 - compares a and b and swaps them
 * @array: points to an array to be sorted
 * @size: size of the array
 * @a: first integer
 * @b: second integer
 */
void swap2(int *array, size_t size, int *a, int *b)
{
	int tmp;

	if (*a != *b)
	{
		tmp = *a;
		*a = *b;
		*b = tmp;
		print_array(array, size);
	}
}

/**
 * lomuto - takes last element as pivot, places the pivot element
 *             at its correct position in sorted array, and places
 *             all smaller (smaller than pivot) to the left of pivot
 *             and all greater elements to the right of pivot
 * @array: points to an array to be sorted
 * @low: first element of the array
 * @high: last element of the array
 * @size: size of the array
 *
 * Return: the pivot index
 *
 */
int lomuto(int *array, int low, int high, size_t size)
{
	int pivot_value = array[high];

	int i, j;

	i = low;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot_value)
		{
			swap2(array, size, &array[i], &array[j]);
			i++;
		}
	}
	swap2(array, size, &array[i], &array[high]);
	return (i);
}

/**
 * quicksort_recursion - partion scheme
 * @array: points to an array to be sorted
 * @low: first element of the array
 * @high: last element of the array
 * @size: size of the array
 */
void quicksort_recursion(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot_index = lomuto(array, low, high, size);

		quicksort_recursion(array, low, (pivot_index - 1), size);
		quicksort_recursion(array, (pivot_index + 1), high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 *              using the quick sort algorithm
 * @array: points to an array to be sorted
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quicksort_recursion(array, 0, (size - 1), size);
}
