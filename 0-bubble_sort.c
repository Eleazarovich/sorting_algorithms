#include "sort.h"
#include <stdio.h>

/**
 * swap - compares a and b if a > b it swaps b to be a and vice versa
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
 * bubble_sort - sorts an array of integers in ascending order
 *               using the Bubble sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void  bubble_sort(int *array, size_t size)
{
	unsigned long int i, j;

	for (i = 0; i < (size - 1); i++)
	{
		for (j = 0; j < (size - 1 - i); j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}
	}
}
