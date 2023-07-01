#include "sort.h"

/**
 * merge - Merges two sub-arrays 
 * @array: Ptr to the array
 * @left: Ptr to the left sub-array
 * @left_size: Size of the left sub-array
 * @right: Ptr to the right sub-array
 * @right_size: Size of the right sub-array
 */
void merge(int *array, int *left, size_t left_size, int *right, size_t right_size)
{
    size_t i = 0, j = 0, k = 0;
    int *tmp = malloc(sizeof(*tmp) * (left_size + right_size));

    if (!tmp)
        return;

    printf("Merging...\n");
    printf("[left]: ");
    print_array(left, left_size);
    printf("[right]: ");
    print_array(right, right_size);

    while (i < left_size && j < right_size) {
        if (left[i] <= right[j]) {
            tmp[k] = left[i];
            i++;
        } else {
            tmp[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < left_size) {
        tmp[k] = left[i];
        i++;
        k++;
    }

    while (j < right_size) {
        tmp[k] = right[j];
        j++;
        k++;
    }

    for (i = 0; i < left_size + right_size; i++) {
        array[i] = tmp[i];
    }

    printf("[Done]: ");
    print_array(array, left_size + right_size);

    free(tmp);
}

/**
 * merge_sort - Sorts an array of innts in asc order
 *              using the merge sort algorithm
 * @array: Pointer to the array to sort
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
    size_t middle, i;
    int *left, *right;

    if (size < 2)
        return;

    middle = size / 2;

    left = array;
    right = array + middle;

    merge_sort(left, middle);
    merge_sort(right, size - middle);

    merge(array, left, middle, right, size - middle);
}
