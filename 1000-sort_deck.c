#include "deck.h"
#include <stdlib.h>
#include <string.h>
#include "sort.h"

/**
 * compare_cards - Compares two cards for sorting
 * @card1: Pointer to the first card
 * @card2: Pointer to the second card
 *
 * Return: Negative if card1 should come before card2, positive if card2 should
 * come before card1, 0 if they are equal.
 */
int compare_cards(const void *card1, const void *card2)
{
    const card_t *c1 = ((const deck_node_t *)card1)->card;
    const card_t *c2 = ((const deck_node_t *)card2)->card;

    if (c1->kind != c2->kind)
        return (c1->kind - c2->kind);
    return (strcmp(c1->value, c2->value));
}

/**
 * sort_deck - Sorts a deck of cards
 * @deck: Pointer to a pointer to the head of the deck
 */
void sort_deck(deck_node_t **deck)
{
    size_t deck_size = 0;
    deck_node_t *node;

    if (!*deck || !(*deck)->next)
        return;

    /* Calculate the size of the deck */
    for (node = *deck; node; node = node->next)
        deck_size++;

    /* Convert the deck to an array */
    deck_node_t **deck_array = malloc(sizeof(*deck_array) * deck_size);
    if (!deck_array)
        return;

    size_t i;
    for (i = 0, node = *deck; i < deck_size; i++, node = node->next)
        deck_array[i] = node;

    /* Sort the array */
    qsort(deck_array, deck_size, sizeof(*deck_array), compare_cards);

    /* Rebuild the deck from the sorted array */
    for (i = 0; i < deck_size - 1; i++)
        deck_array[i]->next = deck_array[i + 1];

    deck_array[deck_size - 1]->next = NULL;
    *deck = deck_array[0];

    /* Update the prev pointers of the new deck */
    for (node = *deck; node->next; node = node->next)
        node->next->prev = node;

    free(deck_array);
}
