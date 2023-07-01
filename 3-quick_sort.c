#include "sort.h"

/**
 * swap - interchangee ints
 * @a: int
 * @b: int
 * Return: 0 for suuccess
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
/**
 * partition - Part of arrray pivoting
 * @array: Array
 * @low: low int 
 * @high: top int
 * @size: size
 * Return: x for successs
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int x = low - 1, y;

	for (y = low; y <= high; y++)
	{
		if (array[y] <= pivot)
		{
			x++;
			if (x != y)
			{
				swap(&array[x], &array[y]);
				print_array(array, size);
			}
		}
	}
	return (x);
}
/**
 * lomuto_qsort - recursive soerting function
 * @array: Array to be sorted
 * @low: low value
 * @high: top
 * @size: Size
 * Return: 0 alwasy for success
 */
void lomuto_qsort(int *array, int low, int high, size_t size)
{
	int i;

	if (low < high)
	{
		i = partition(array, low, high, size);
		lomuto_qsort(array, low, i - 1, size);
		lomuto_qsort(array, i + 1, high, size);
	}
}
/**
 * quick_sort - quick sortt using lomuto
 * @array: array
 * @size: Size 4 aray
 * Return: 0 always for success
 */
void quick_sort(int *array, size_t size)
{
	lomuto_qsort(array, 0, size - 1, size);
}
