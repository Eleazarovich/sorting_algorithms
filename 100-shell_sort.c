#include "sort.h"

/**
 * gap_size - implements the knuth sequence in the shell sort algorithm
 * @size: size of the array
 *
 * Return: gap size
 */
size_t gap_size(size_t size)
{
	size_t h = 1;

	while (h < size)
		h = ((h * 3) + 1);
	return ((h - 1) / 3);
}

/**
 * shell_sort -  sorts an array of integers in ascending order
 *               using the shell sort algorithm, using knuth sequence
 * @array: points to an array  to be sorted
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int tmp;

	if (!array || !size)
		return;

	for (gap = gap_size(size); gap; gap = (gap - 1) / 3)
	{
		for (i = gap; i < size; i++)
		{
			tmp = array[i];

			for (j = i; j > gap - 1 && array[j - gap] > tmp; j -= gap)
				array[j] = array[j - gap];
			array[j] = tmp;
		}
		print_array(array, size);
	}
}
