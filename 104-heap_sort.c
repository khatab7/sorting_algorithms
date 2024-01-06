#include "sort.h"

/**
 * get_parent - Get the parent
 *
 * @i: integer
 * Return: The place of the parent
 */

int get_parent(int i)
{
	return ((i - 1) / 2);
}

/**
 * get_child - Get the child
 *
 * @i: integer
 * @is_right: integer
 * Return: The place of the child
 */

int get_child(int i, int is_right)
{
	return (2 * i + 1 + (is_right != 0));
}

/**
 * siftdown - shifting down
 *
 * @array: Array to sort
 * @i: integer
 * @size: size of the array for comparaison
 * @print_size: size of the array for print
 */

void	siftdown(int *array, int i, int size, int print_size)
{
	int	left, right, max, tmp;

	left = get_child(i, 0);
	right = get_child(i, 1);
	if (left < size && array[left] > array[i])
		max = left;
	else
		max = i;
	if (right < size && array[right] > array[max])
		max = right;
	if (max != i)
	{
		tmp = array[i];
		array[i] = array[max];
		array[max] = tmp;
		print_array(array, print_size);
		siftdown(array, max, size, print_size);
	}
}

/**
 * heap_sort - Sorts an array using the Heap Sort method
 *
 * @array: Array to sort
 * @size: size fo the array
 */

void	heap_sort(int *array, size_t size)
{
	int	i, tmp;

	i = get_parent(size - 1);
	while (i >= 0)
	{
		siftdown(array, i, size, size);
		i--;
	}
	i = size - 1;
	while (i > 0)
	{
		tmp = array[0];
		array[0] = array[i];
		array[i] = tmp;
		print_array(array, size);
		i--;
		siftdown(array, 0, i + 1, size);
	}
}
