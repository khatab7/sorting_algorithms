#include "sort.h"

/**
 * bitonic_merge - Merges a partition during bitonic sort
 *
 * @array: Array of integers
 * @low: Start of partition
 * @part_size: Size of partition
 * @dir: Order to sort in (1 is ascending, 0 is descending)
 * @size: Size of entire array
 */
void	bitonic_merge(int *array, size_t low, size_t part_size, int dir,
						size_t size)
{
	size_t	i;
	size_t	halfpart_size;
	int		tmp;

	if (part_size < 2)
		return;
	halfpart_size = part_size / 2;
	for (i = low; i < low + halfpart_size; i++)
	{
		if (dir == (array[i] > array[i + halfpart_size]))
		{
			tmp = array[i];
			array[i] = array[i + halfpart_size];
			array[i + halfpart_size] = tmp;
		}
	}
	bitonic_merge(array, low, halfpart_size, dir, size);
	bitonic_merge(array, low + halfpart_size, halfpart_size, dir, size);
}

/**
 * bitonic_split - Performs bitonic operations on a partition of an array
 *
 * @array: Array of integers
 * @low: Start of partition
 * @part_size: size of partition
 * @dir: Order to sort in (1 is ascending, 0 is descending)
 * @size: Size of entire array
 */

void	bitonic_split(int *array, size_t low, size_t part_size, int dir,
						size_t size)
{
	if (part_size < 2)
		return;
	printf("Merging [%lu/%lu] (%s):\n", part_size, size,
		(dir == 1) ? "UP" : "DOWN");
	print_array(array + low, part_size);
	bitonic_split(array, low, part_size / 2, 1, size);
	bitonic_split(array, low + part_size / 2, part_size / 2, 0, size);
	bitonic_merge(array, low, part_size, dir, size);
	printf("Result [%lu/%lu] (%s):\n", part_size, size,
		(dir == 1) ? "UP" : "DOWN");
	print_array(array + low, part_size);
}

/**
 * bitonic_sort - Sorts an array using Bitonic Sort method
 * @array: Array of integers
 * @size: Size of array. Must be a power of 2
 */
void	bitonic_sort(int *array, size_t size)
{
	if (size < 2 || size % 2)
		return;
	bitonic_split(array, 0, size, 1, size);
}
