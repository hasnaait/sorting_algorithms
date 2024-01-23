#include "sort.h"

/**
 * merge_sub - Sort a subarray of integers.
 * @sub: A subarray of an array of integers to sort.
 * @buff: A buffer to store the sorted subarray.
 * @fr: The front index of the array.
 * @mid: The middle index of the array.
 * @ba: The back index of the array.
 */

void merge_sub(int *sub, int *buff, size_t fr, size_t mid,
			   size_t ba)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(sub + fr, mid - fr);

	printf("[right]: ");
	print_array(sub + mid, ba - mid);

	for (i = fr, j = mid; i < mid && j < ba; k++)
	{
		buff[k] = (sub[i] < sub[j]) ? sub[i++] : sub[j++];
	}
	for (; i < mid; i++)
	{
		buff[k++] = sub[i];
	}
	for (; j < ba; j++)
	{
		buff[k++] = sub[j];
	}
	for (i = fr, k = 0; i < ba; i++)
	{
		sub[i] = buff[k++];
	}
	printf("[Done]: ");
	print_array(sub + fr, ba - fr);
}

/**
 * merge_recur - Implement the merge sort algorithm through recursion.
 * @sub: A subarray of an array of integers to sort.
 * @buff: A buffer to store the sorted result.
 * @fr: The front index of the subarray.
 * @ba: The back index of the subarray.
 */

void merge_recur(int *sub, int *buff, size_t fr, size_t ba)
{
	size_t mid;

	if (ba - fr > 1)
	{
		mid = fr + (ba - fr) / 2;
		merge_recur(sub, buff, fr, mid);
		merge_recur(sub, buff, mid, ba);
		merge_sub(sub, buff, fr, mid, ba);
	}
}

/**
 * merge_sort - Sort an array of integers in ascending
 *              order using the merge sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the top-down merge sort algorithm.
 */

void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	merge_recur(array, buff, 0, size);

	free(buff);
}
