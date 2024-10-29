#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: double pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
listint_t *current, *temp;

if (list == NULL || *list == NULL || (*list)->next == NULL)
return;

current = (*list)->next;
while (current)
{
temp = current;
while (temp->prev && temp->n < temp->prev->n)
{
/* Swap nodes */
temp->prev->next = temp->next;
if (temp->next)
temp->next->prev = temp->prev;

temp->next = temp->prev;
temp->prev = temp->next->prev;
temp->next->prev = temp;

if (temp->prev)
temp->prev->next = temp;
else
*list = temp;

print_list(*list); /* Print list after each swap */
}
current = current->next;
}
}