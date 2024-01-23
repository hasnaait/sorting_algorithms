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
 * hoare_part - Order a subset of an array of integers
 *                   according to the hoare partition scheme.
 * @arr: The array of integers.
 * @size: The size of the array.
 * @lt: The starting index of the subset to order.
 * @rt: The ending index of the subset to order.
 *
 * Return: The final partition index.
 *
 * Description: Uses the last element of the partition as the pivot.
 * Prints the array after each swap of two elements.
 */

int hoare_part(int *arr, size_t size, int lt, int rt)
{
	int pivot, abo, bel;

	pivot = arr[rt];
	for (abo = lt - 1, bel = rt + 1; abo < bel;)
	{
		do {
			abo++;
		} while (arr[abo] < pivot);
		do {
			bel--;
		} while (arr[bel] > pivot);

		if (abo < bel)
		{
			swa_i(arr + abo, arr + bel);
			print_array(arr, size);
		}
	}

	return (abo);
}

/**
 * hoare_sort - Implement the quicksort algorithm through recursion.
 * @arr: An array of integers to sort.
 * @size: The size of the array.
 * @lt: The starting index of the array partition to order.
 * @rt: The ending index of the array partition to order.
 *
 * Description: Uses the Hoare partition scheme.
 */

void hoare_sort(int *arr, size_t size, int lt, int rt)
{
	int par;

	if (rt - lt > 0)
	{
		par = hoare_part(arr, size, lt, rt);
		hoare_sort(arr, size, lt, par - 1);
		hoare_sort(arr, size, par, rt);
	}
}

/**
 * quick_sort_hoare - Sort an array of integers in ascending
 *                    order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Hoare partition scheme. Prints
 * the array after each swap of two elements.
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
