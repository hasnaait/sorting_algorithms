#include "sort.h"

/**
 * mmax - Get the maximum value in an array of integers.
 * @arr: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */

int mmax(int *arr, int size)
{
	int ma, i;

	for (ma = arr[0], i = 1; i < size; i++)
	{
		if (arr[i] > ma)
		{
			ma = arr[i];
		}
	}

	return (ma);
}

/**
 * radix_sort_count - Sort the significant digits of an array of integers
 *                       in ascending order using the counting sort algorithm.
 * @arr: An array of integers.
 * @size: The size of the array.
 * @sig: The significant digit to sort on.
 * @buff: A buffer to store the sorted array.
 */

void radix_sort_count(int *arr, size_t size, int sig, int *buff)
{
	int co[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
	{
		co[(arr[i] / sig) % 10] += 1;
	}
	for (i = 0; i < 10; i++)
	{
		co[i] += co[i - 1];
	}
	for (i = size - 1; (int)i >= 0; i--)
	{
		buff[co[(arr[i] / sig) % 10] - 1] = arr[i];
		co[(arr[i] / sig) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
	{
		arr[i] = buff[i];
	}
}

/**
 * radix_sort - Sort an array of integers in ascending
 *              order using the radix sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */

void radix_sort(int *array, size_t size)
{
	int ma, sig, *buf;

	if (array == NULL || size < 2)
		return;

	buf = malloc(sizeof(int) * size);
	if (buf == NULL)
		return;

	ma = mmax(array, size);
	for (sig = 1; ma / sig > 0; sig *= 10)
	{
		radix_sort_count(array, size, sig, buf);
		print_array(array, size);
	}

	free(buf);
}
