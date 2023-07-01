#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 *                      in ascending order using Cocktail shaker sort
 * @list: Pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
    listint_t *start = *list, *end = NULL, *node;

    while (start != end) {
        for (node = start; node->next != end; node = node->next) {
            if (node->n > node->next->n) {
                node->next->prev = node->prev;
                if (node->prev)
                    node->prev->next = node->next;
                else
                    *list = node->next;
                node->prev = node->next;
                node->next = node->next->next;
                node->prev->next = node;
                if (node->next)
                    node->next->prev = node;
                print_list(*list);
            }
        }
        end = node;
        for (node = end->prev; node != start->prev; node = node->prev) {
            if (node->n > node->next->n) {
                node->next->prev = node->prev;
                if (node->prev)
                    node->prev->next = node->next;
                else
                    *list = node->next;
                node->prev = node->next;
                node->next = node->next->next;
                node->prev->next = node;
                if (node->next)
                    node->next->prev = node;
                print_list(*list);
            }
        }
        start = node->next;
    }
}
