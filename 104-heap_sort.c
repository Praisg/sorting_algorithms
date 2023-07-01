#include "sort.h"

/**
 * sift_down - Repair th heap whose root element is at index 'start',
 *             assume th heaps rooted at its children are valid
 * @array: Ptr to the array
 * @start: Index of th root element
 * @end: Index of the last element in the heap
 */
void sift_down(int *array, size_t start, size_t end)
{
    size_t root, child, swap;
    int tmp;

    root = start;

    while ((root * 2) + 1 <= end) {
        child = (root * 2) + 1;
        swap = root;

        if (array[swap] < array[child])
            swap = child;
        if (child + 1 <= end && array[swap] < array[child + 1])
            swap = child + 1;
        if (swap == root)
            return;

        tmp = array[root];
        array[root] = array[swap];
        array[swap] = tmp;

        print_array(array, end + 1);

        root = swap;
    }
}

/**
 * heap_sort - Sorts an array of integers in ascending order
 *             using the sift-down heap sort algorithm
 * @array: Pointer to the array to sort
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
    size_t start, end;
    int tmp;

    if (!array || size < 2)
        return;

    end = size - 1;

    for (start = (end - 1) / 2; (int)start >= 0; start--) {
        sift_down(array, start, end);
    }

    while (end > 0) {
        tmp = array[end];
        array[end] = array[0];
        array[0] = tmp;

        print_array(array, size);

        end--;

        sift_down(array, 0, end);
    }
}
