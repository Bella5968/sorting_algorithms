#ifndef SORT_H
#define SORT_H

#include <stddef.h> /* for size_t */
#include <stdbool.h> /* for bool */

/* Structure for doubly linked list node */
typedef struct listint_s
{
const int n;
struct listint_s *prev;
struct listint_s *next;
} listint_t;

/* Define deck_node_t if it's needed for other tasks */
typedef struct deck_node_s
{
int value; /* Example field */
struct deck_node_s *prev;
struct deck_node_s *next;
} deck_node_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
/*void sort_deck(deck_node_t **deck); Placeholder function if required */

#endif /* SORT_H */
