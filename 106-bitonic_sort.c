#include "sort.h"

/**
 * check - print a range
 * @arr: The array to print
 * @r1: Less range
 * @r2: Final range
 * Return: Nothing
 */

void check(int *arr, int r1, int r2)
{
	int i;

	for (i = r1; i <= r2; i++)
	{
		if (i > r1)
		{
			printf(", ");
		}
		printf("%d", arr[i]);
	}
	printf("\n");
}

/**
 * swapp - swap two elements in an array
 * @arr: THe array to change the values
 * @i: A index
 * @j: Another index
 * @dir: Direction of the array
 * Return: Nothing
 */

void swapp(int *arr, int i, int j, int dir)
{
	int tempp;

	if (dir == (arr[i] > arr[j]))
	{
		tempp = arr[i];
		arr[i] = arr[j];
		arr[j] = tempp;
	}
}

/**
 * merge_bit - swap the elements to sort
 * @arr: Array to sort
 * @low: The low element in the range to sort
 * @size: The size of the range to sort
 * @dir: Indicate which half are manage
 * @r_size: The size of the all array
 * Return: Nothing
 */

void merge_bit(int *arr, int low, int size, int dir, const int r_size)
{
	int tmp = size, i = low;

	if (size > 1)
	{
		tmp = size / 2;

		for (i = low; i < low + tmp; i++)
		{
			swapp(arr, i, i + tmp, dir);
		}
		merge_bit(arr, low, tmp, dir, r_size);
		merge_bit(arr, low + tmp, tmp, dir, r_size);
	}
}

/**
 * sorrrt - segmentate the array
 * @arr: The array to sort
 * @low: The lowest element in each range
 * @size: Size of the range to sort
 * @dir: Indicate which half are manage
 * @r_size: The size of the all array
 * Return: Nothing
 */

void sorrrt(int *arr, int low, int size, int dir, const int r_size)
{
	int k = size;

	if (size > 1)
	{
		if (dir == 1)
		{
			printf("Merging [%d/%d] (UP):\n", size, r_size);
		}
		if (dir == 0)
		{
			printf("Merging [%d/%d] (DOWN):\n", size, r_size);
		}
		check(arr, low, low + k - 1);

		k = size / 2;
		sorrrt(arr, low, k, 1, r_size);

		sorrrt(arr, low + k, k, 0, r_size);

		merge_bit(arr, low, size, dir, r_size);
		if (dir == 1)
		{
			printf("Result [%d/%d] (UP):\n", size, r_size);
			check(arr, low, low + 2 * k - 1);
		}
		if (dir == 0)
		{
			printf("Result [%d/%d] (DOWN):\n", size, r_size);
			check(arr, low, low + 2 * k - 1);
		}
	}
}

/**
 * bitonic_sort - call the sort function
 * @array: The array to sort
 * @size: Size of the array
 * Return: Nothing
 */

void bitonic_sort(int *array, size_t size)
{
	int up = 1;
	const int r_size = (int)size;

	if (size < 2 || !array)
		return;

	sorrrt(array, 0, (int)size, up, r_size);
}
