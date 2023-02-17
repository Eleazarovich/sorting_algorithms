#include "sort.h"

/**
 * swap - compares a and b if a < b it swaps b to be a and vice versa
 * @a: first integer
 * @b: second integer
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - sorts an array of integers in ascending order
 *                  using the selection sort algorithm
 * @array: points to array to be sorted
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;

	if (!array || size < 2)
		return;

	for (i = 0; i < (size - 1); i++)
	{
		int *min = array + i;

		for (j = i + 1; j < size; j++)
			min = (array[j] < *min) ? (array + j) : min;

		if ((array + i) != min)
		{
			swap(&array[i], min);
			print_array(array, size);
		}
	}
}
