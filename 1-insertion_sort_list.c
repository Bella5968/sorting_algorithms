#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order
 *                        using the Insertion sort algorithm.
 *
 * @list: Pointer to a pointer to the head of the doubly linked list.
 *
 * This function swaps the nodes themselves and prints the list after each swap.
 */
void insertion_sort_list(listint_t **list) {
    listint_t *current, *temp, *next;

    if (list == NULL || *list == NULL)
        return;

    current = (*list)->next; /** Start with the second element */
    while (current != NULL) {
        temp = current; /** Store the current node to move */
        next = current->next; /** Store the next node */

        /** Move to the left and swap if the current node is less than the previous */
        while (temp->prev != NULL && temp->n < temp->prev->n) {
            /** Swap nodes temp and temp->prev */
            if (temp->prev->prev)
                temp->prev->prev->next = temp; /** Link to node before temp->prev */
            if (temp->next)
                temp->next->prev = temp->prev; /** Link next node to temp->prev */

            temp->prev->next = temp->next; /** Link temp->prev to the next node */
            temp->next = temp->prev; /** Move temp to where temp->prev was */
            temp->prev = temp->prev->prev; /** Move temp->prev back */

            /** Fix the links */
            if (temp->prev) {
                temp->prev->next = temp; /** Link previous node to current temp */
            } else {
                *list = temp; /** Update head if temp is the new head */
            }
            temp->next->prev = temp; /** Link the original next node back to temp */
            print_list(*list); /** Print after every swap */
        }
        current = next; /** Move to the next element in the original list */
    }
}

