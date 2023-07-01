#include "sort.h"
#include <stdlib.h>

/**
 * radix_sort - Sortsan array of ints in ascending order using LSD Radix sort
 * @array: Ptr to the array to sort
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
    int *tmp_array;
    size_t i, j, k, radix, divisor = 1;

    if (!array || size < 2)
        return;

    tmp_array = malloc(sizeof(int) * size);
    if (!tmp_array)
        return;

    /* Find the maximum number in the array */
    radix = array[0];
    for (i = 1; i < size; i++)
        if (array[i] > radix)
            radix = array[i];

    /* Perform LSD Radix sort on each digit */
    while (radix / divisor > 0)
    {
        int count[10] = {0};

        /* Count the number of elements with each digit */
        for (i = 0; i < size; i++)
            count[(array[i] / divisor) % 10]++;

        /* Compute the starting position of each digit in the output array */
        for (i = 1; i < 10; i++)
            count[i] += count[i - 1];

        /* Move the elements to the output array in sorted order */
        for (i = size - 1; i != (size_t)-1; i--)
        {
            j = (array[i] / divisor) % 10;
            tmp_array[--count[j]] = array[i];
        }

        /* Copy the output array back to the original array */
        for (i = 0; i < size; i++)
            array[i] = tmp_array[i];

        /* Print the array after sorting each digit */
        print_array(array, size);

        /* Update the divisor for the next digit */
        divisor *= 10;
    }

    free(tmp_array);
}
