#include "sort.h"

/**
 * sw - sorts an array of integers in ascending order
 * @arr: elements to be sorted
 * @i: left element
 * @j: right element
 * @size: size of array
 */

void sw(int *arr, int i, int j, int size)
{
	int aux;

	if (arr[i] == arr[j])
		return;
	aux = arr[i];
	arr[i] = arr[j];
	arr[j] = aux;
	print_array(arr, size);
}

/**
 * part - sort array partition
 * @arr: elements to be sorted
 * @st: left side
 * @end: right side
 * @size: size of array
 * Return: pivot sorted
 */

int part(int *arr, int st, int end, int size)
{
	int pivot = arr[end];
	int split = st;
	int j;

	for (j = st; j < end; j++)
		if (arr[j] < pivot)
			sw(arr, split++, j, size);
	sw(arr, split, end, size);
	return (split);
}

/**
 * recur - quick_sort core
 * @arr: elements to be sorted
 * @start: left side
 * @end: right side
 * @size: size of array
 */

void recur(int *arr, int start, int end, int size)
{
	if (start < end)
	{
		int pivot_pos = part(arr, start, end, size);

		recur(arr, start, pivot_pos - 1, size);
		recur(arr, pivot_pos + 1, end, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * @array: elements to be sorted
 * @size: size of array
 */

void quick_sort(int *array, size_t size)
{
	recur(array, 0, size - 1, size);
}
