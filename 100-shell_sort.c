#include "sort.h"

/**
 * sort_with_gap - Insertion sort with a defined gap
 * @array: Array to sort
 * @gap: Gap between values to swap
 * @size: Size of array
 */
void	sort_with_gap(int *array, int gap, int size)
{
	int		i = 0, j = 0, tmp;

	while (i + gap < size)
	{
		if (array[i] > array[i + gap])
		{
			j = i;
			while (j >= 0 && array[j] > array[j + gap])
			{
				tmp = array[j];
				array[j] = array[j + gap];
				array[j + gap] = tmp;
				j -= gap;
			}
		}
		i++;
	}
}

/**
 * knuth_sequence - Returns the number of the Knuth sequence
 * @i: Index of the number
 * Return: Number at index @i of the Knuth squence
 */
size_t		knuth_sequence(int i)
{
	size_t	n = 1;

	while (i--)
		n = n * 3 + 1;
	return (n);
}

/**
 * shell_sort - Sorts an array using Shell Sort method
 * @array: Array to sort
 * @size: size of @array
 */
void	shell_sort(int *array, size_t size)
{
	int i = 0;

	if (size < 2)
		return;

	while (knuth_sequence(i + 1) < size)
		i++;
	while (i >= 0)
	{
		sort_with_gap(array, knuth_sequence(i), size);
		print_array(array, size);
		i--;
	}
}
