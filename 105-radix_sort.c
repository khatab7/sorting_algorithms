#include "sort.h"

/**
 * sort_unit - Sort an array
 *
 * @array: The array to sort
 * @new_array: Result of the sort
 * @size: Size of the array
 * Return: The max value
 */

int sort_unit(int *array, int *new_array, size_t size)
{
	int i, j, k, max = 0;

	for (i = 0, k = 0; i < 10; i++)
	{
		for (j = 0; j < (int)size; j++)
		{
			if (array[j] % 10 == i)
			{
				new_array[k] = array[j];
				k++;
			}
			if (i == 0 && array[j] > max)
				max = array[j];
		}
	}

	return (max);
}

/**
 * copy_array - Copy an array
 *
 * @array: The array
 * @new_array: The array copied
 * @size: Size of the array
 */

void copy_array(int *array, int *new_array, size_t size)
{
	int i;

	for (i = 0; i < (int)size; i++)
		array[i] = new_array[i];
}

/**
 * radix_sort - Sorts a list using the Radix sort algorithm
 *
 * @array: Array of integers
 * @size: Size of the array
 */

void radix_sort(int *array, size_t size)
{
	int *new_array, i, j, k, l = 10, max, nb = -1;

	if (size < 2)
		return;

	new_array = malloc(size * sizeof(int));
	if (!new_array)
		return;

	max = sort_unit(array, new_array, size);
	print_array(new_array, size);
	while (max)
	{
		max /= 10;
		nb++;
	}
	while (nb)
	{
		copy_array(array, new_array, size);
		for (i = 0, k = 0; i < 10; i++)
		{
			for (j = 0; j < (int)size; j++)
			{
				if ((array[j] / l) % 10 == i)
				{
					new_array[k] = array[j];
					k++;
				}
			}
		}
		nb--;
		l *= 10;
		print_array(new_array, size);
	}
	copy_array(array, new_array, size);
	free(new_array);
}
