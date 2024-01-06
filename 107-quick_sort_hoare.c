#include "sort.h"

/**
 * partition - Parition used: Hoare
 *
 * @arr: array to sort
 * @low: start of the segment
 * @high: end of the segment
 * @size: size of the array
 * Return: pivot for the next partition
 */

int partition(int *arr, int low, int high, size_t size)
{
	int pivot = arr[high], tmp;

	while (1)
	{
		while (arr[low] < pivot)
			low++;

		while (arr[high] > pivot)
			high--;

		if (low > high)
			return (high);

		tmp = arr[low];
		arr[low] = arr[high];
		arr[high] = tmp;
		if (low != high)
			print_array(arr, size);
		low++;
		high--;
	}
}

/**
 * quicksort - Sort using recursion
 *
 * @array: Array to sort
 * @low: start of the segment
 * @high: end of the segment
 * @size: size of the array
 */

void quicksort(int *array, int low, int high, size_t size)
{
	int p;

	if (low < high)
	{
		p = partition(array, low, high, size);
		quicksort(array, low, p, size);
		quicksort(array, p + 1, high, size);
	}
}

/**
 * quick_sort_hoare - Sorts a list using the Quick sort algorithm
 *
 * @array: Array to sort
 * @size: size of the array
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}
