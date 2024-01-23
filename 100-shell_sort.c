#include "sort.h"

/**
 * shell_sort -Sort an array using shell_sort algorithm
 * @array: array
 * @size: size of the array
 * Return: NULL
 **/

void shell_sort(int *array, size_t size)
{
	unsigned int gap = 1, he, ta;
	int del;

	if (array == NULL)
		return;

	if (size < 2)
		return;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (he = gap; he < size; he++)
		{
			del = array[he];
			ta = he;
			while (ta >= gap && array[ta - gap] > del)
			{
				array[ta] = array[ta - gap];
				ta -= gap;
			}
			array[ta] = del;
		}

		print_array(array, size);
		gap /= 3;
	}
}
