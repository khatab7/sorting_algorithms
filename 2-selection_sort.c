#include "sort.h"

/**
 * selection_sort - Sorts a list using the Selection sort algorithm
 *
 * @array: Array of integers
 * @size: Size of the array
 */

void selection_sort(int *array, size_t size)
{
	int min, tmp, place;
	size_t i, j;

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		min = array[i];
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < min)
			{
				min = array[j];
				place = j;
			}
		}
		if (min != array[i])
		{
			tmp = array[i];
			array[i] = min;
			array[place] = tmp;
			print_array(array, size);
		}
	}
}
