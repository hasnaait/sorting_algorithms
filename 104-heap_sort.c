#include "sort.h"

/**
 * swa_i - Swap two integers in an arr.
 * @int1: The first integer to swap.
 * @int2: The second integer to swap.
 */

void swa_i(int *int1, int *int2)
{
	int tmp;

	tmp = *int1;
	*int1 = *int2;
	*int2 = tmp;
}

/**
 * max_heap - Turn int1 binary tree into int1 complete binary heap.
 * @arr: An array of integers representing int1 binary tree.
 * @len: The size of the array/tree.
 * @base: The index of the base row of the tree.
 * @root: The root node of the binary tree.
 */

void max_heap(int *arr, size_t len, size_t base, size_t root)
{
	size_t lt, rt, mmaaxx;

	lt = 2 * root + 1;
	rt = 2 * root + 2;
	mmaaxx = root;

	if (lt < base && arr[lt] > arr[mmaaxx])
	{
		mmaaxx = lt;
	}
	if (rt < base && arr[rt] > arr[mmaaxx])
	{
		mmaaxx = rt;
	}
	if (mmaaxx != root)
	{
		swa_i(arr + root, arr + mmaaxx);
		print_array(arr, len);
		max_heap(arr, len, base, mmaaxx);
	}
}

/**
 * heap_sort - Sort an array of integers in ascending
 *             order using the heap sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the sift-down heap sort
 * algorithm. Prints the array after each swap.
 */

void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
	{
		max_heap(array, size, size, i);
	}
	for (i = size - 1; i > 0; i--)
	{
		swa_i(array, array + i);
		print_array(array, size);
		max_heap(array, size, i, 0);
	}
}
