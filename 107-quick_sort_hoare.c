#include "sort.h"
#include <stdlib.h>

/**
 * swap_ints - Swaps two integers in an array
 * @a: Pointer 1st integer
 * @b: Pointer  second integer
 */
void swap_ints(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * hoare_partition - Partitions an array using the Hoare scheme
 * @array: Pointer to the array
 * @lo: Lower bound of the partition to sort
 * @hi: Upper bound of the partition to sort
 *
 * Return: The final position of the pivot
 */
int hoare_partition(int *array, int lo, int hi)
{
    int pivot = array[hi];
    int i = lo - 1;
    int j = hi + 1;

    while (1)
    {
        do {
            i++;
        } while (array[i] < pivot);

        do {
            j--;
        } while (array[j] > pivot);

        if (i >= j)
            return (j);

        swap_ints(&array[i], &array[j]);
        print_array(array, hi - lo + 1);
    }
}

/**
 * quicksort_hoare - Sorts a partition of an array using the Hoare scheme
 * @array: Pointer to the array
 * @lo: Lower bound of the partition to sort
 * @hi: Upper bound of the partition to sort
 */
void quicksort_hoare(int *array, int lo, int hi)
{
    if (lo < hi)
    {
        int p = hoare_partition(array, lo, hi);
        quicksort_hoare(array, lo, p);
        quicksort_hoare(array, p + 1, hi);
    }
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order using the
 *                    Quick sort algorithm with the Hoare partition scheme
 * @array: Pointer to the array
 * @size: Size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    quicksort_hoare(array, 0, size - 1);
}
