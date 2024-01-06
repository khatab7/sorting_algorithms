#include "sort.h"

/**
 * bubble_sort - Sorts an array using the Bubble sort algorithm
 *
 * @array: Array of int
 * @size: Size of the array
 */

void bubble_sort(int *array, size_t size)
{
	int check = 1, temp;
	size_t i;

	if (size < 2)
		return;

	while (check)
	{
		check = 0;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				check = 1;
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				print_array(array, size);
			}
		}
	}
}
