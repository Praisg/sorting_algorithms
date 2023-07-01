#include "sort.h"

/**
 * swap - Swaps two elements in an array
 * @array: Ptr the array
 * @i: Index of first element
 * @j: Index of second element
 */
void swap(int *array, int i, int j)
{
    int tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;

    print_array(array, sizeof(array) / sizeof(array[0]));
}

/**
 * bitonic_merge - Merges two bitonic sequences in ascending order
 * @array: Pointer to the array
 * @low: Starting index of the first sequence
 * @cnt: Number of elements in the sequences
 * @dir: Direction of the sort (1 for ascending, 0 for descending)
 */
void bitonic_merge(int *array, int low, int cnt, int dir)
{
    if (cnt > 1) {
        int k = cnt / 2, i;

        for (i = low; i < low + k; i++)
            if (dir == (array[i] > array[i + k]))
                swap(array, i, i + k);

        bitonic_merge(array, low, k, dir);
        bitonic_merge(array, low + k, k, dir);
    }
}

/**
 * bitonic_sort_helper - Sorts a bitonic sequence recursively
 * @array: Pointer to the array
 * @low: Starting index of the sequence
 * @cnt: Number of elements in the sequence
 * @dir: Direction of the sort (1 for ascending, 0 for descending)
 */
void bitonic_sort_helper(int *array, int low, int cnt, int dir)
{
    if (cnt > 1) {
        int k = cnt / 2;

        bitonic_sort_helper(array, low, k, 1);
        bitonic_sort_helper(array, low + k, k, 0);
        bitonic_merge(array, low, cnt, dir);
    }
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order using the Bitonic sort algorithm
 * @array: Pointer to the array to sort
 * @size: Size of the array
 */
void bitonic_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    bitonic_sort_helper(array, 0, size, 1);
}
