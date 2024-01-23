#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * @array: element to be sorted
 * @size: size of array
 */

void selection_sort(int *array, size_t size)
{
	unsigned int first, last;

	if (size < 2)
		return;

	for (first = 0; first < size; first++)
	{
		unsigned int ll = first;
		int temp = array[first];

		for (last = first + 1; last < size; last++)
		{
			if (array[last] < temp)
				temp = array[last], ll = last;
		}
		if (ll != first)
		{
			array[ll] = array[first];
			array[first] = temp;
			print_array(array, size);
		}
	}
}
