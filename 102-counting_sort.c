#include "sort.h"


/**
 * max_integer - returns the maximum integer in an array of positive integers
 * @array: points to the first element of the array
 * @size: size of the array
 *
 * Return: the maximum integer
 *
 */
int max_integer(int *array, int size)
{
	int max_num, i;

	for (max_num = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max_num)
			max_num = array[i];
	}
	return (max_num);
}

/**
 * counting_sort - sorts an array of integers in ascending order
 *                 using the counting sort algorithm
 * @array: points to an array to be be sorted
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *count, *arr;
	int k, i;

	if (!array || size < 2)
		return;

	arr = malloc(sizeof(int) * size);
	if (arr == NULL)
		return;

	/* key */
	k = max_integer(array, size);
	count = malloc(sizeof(int) * (k + 1));
	if (count == NULL)
	{
		free(arr);
		return;
	}
	for (i = 0; count[i]; i++)
		count[i] = 0;

	for (i = 0; i < (int)size; i++)
		count[array[i]]++;

	for (i = 0; i < k + 1; i++)
		count[i] += count[i - 1];

	print_array(count, k + 1);

	for (i = 0; i < (int)size; i++)
	{
		arr[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = arr[i];

	free(arr);
	free(count);
}
