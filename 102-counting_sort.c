#include "sort.h"

/**
 * mmax - Get the maximum value in an array of integers.
 * @arr: An array of integers.
 * @len: The size of the array.
 *
 * Return: The maximum integer in the array.
 */

int mmax(int *arr, int len)
{
	int maxx, i;

	for (maxx = arr[0], i = 1; i < len; i++)
	{
		if (arr[i] > maxx)
			maxx = arr[i];
	}

	return (maxx);
}

/**
 * counting_sort - Sort an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the counting array after setting it up.
 */

void counting_sort(int *array, size_t size)
{
	int *co, *sortt, maxx, i;

	if (array == NULL || size < 2)
		return;

	sortt = malloc(sizeof(int) * size);
	if (sortt == NULL)
		return;

	maxx = mmax(array, size);
	co = malloc(sizeof(int) * (maxx + 1));

	if (co == NULL)
	{
		free(sortt);
		return;
	}

	for (i = 0; i < (maxx + 1); i++)
		co[i] = 0;
	for (i = 0; i < (int)size; i++)
	{
		co[array[i]] += 1;
	}
	for (i = 0; i < (maxx + 1); i++)
		co[i] += co[i - 1];
	print_array(co, maxx + 1);

	for (i = 0; i < (int)size; i++)
	{
		sortt[co[array[i]] - 1] = array[i];
		co[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sortt[i];

	free(sortt);
	free(co);
}
