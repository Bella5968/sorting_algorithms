#include "sort.h"

/**
 * swap - Swaps two elements in an array
 * @a: First element to swap
 * @b: Second element to swap
 */
void swap(int *a, int *b)
{
int temp = *a;
*a = *b;
*b = temp;
}

/**
 * partition - Lomuto partition scheme for Quick sort
 * @array: Array to sort
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of the array (used for printing)
 *
 * Return: The final index of the pivot
 */
int partition(int *array, int low, int high, size_t size)
{
int pivot = array[high];
int i = low - 1;

for (int j = low; j < high; j++)
{
if (array[j] < pivot)
{
i++;
if (i != j)
{
swap(&array[i], &array[j]);
print_array(array, size);
}
}
}
/* Ensure to print even if the pivot swap does not change elements */
swap(&array[i + 1], &array[high]);
print_array(array, size);

return (i + 1);
}

/**
 * quick_sort_recursive - Recursive function for Quick sort
 * @array: Array to sort
 * @low: Starting index of the array
 * @high: Ending index of the array
 * @size: Size of the array (used for printing)
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
if (low < high)
{
int pi = partition(array, low, high, size);
quick_sort_recursive(array, low, pi - 1, size);
quick_sort_recursive(array, pi + 1, high, size);
}
}

/**
 * quick_sort - Sorts an array using the Quick sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;

quick_sort_recursive(array, 0, size - 1, size);
}

