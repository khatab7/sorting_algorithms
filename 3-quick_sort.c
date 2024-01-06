#include "sort.h"
#include <stdio.h>

/**
 * quick_sort_recursion - sort the array using quick sort
 * @array: array to sort
 * @low: lowest point in the array
 * @high: highest point in the array
 * @size: size of the array
 */
void quick_sort_recursion(int *array, int low, int high, int size)
{
	int i = low - 1, j, tmp, piv = array[high];

	if (low >= high)
		return;

	for (j = low; j < high; j++)
	{
		if (array[j] < piv)
		{
			i++;
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			if (i != j)
				print_array(array, size);
		}
	}
	if (array[high] < array[i + 1])
	{
		array[high] = array[i + 1];
		array[i + 1] = piv;
		if (i + 1 != high)
			print_array(array, size);
	}
	quick_sort_recursion(array, low, i, size);
	quick_sort_recursion(array, i + 2, high, size);
}

/**
 * quick_sort - sort the array with the quick sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;
	quick_sort_recursion(array, 0, size - 1, size);
}
