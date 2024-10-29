#include "sort.h"
#include <stdio.h>

/**
 * shell_sort - Sorts an array of integers in ascending order using
 *              the Shell sort algorithm with the Knuth sequence.
 * @array: The array of integers to sort.
 * @size: The size of the array.
 */
void shell_sort(int *array, size_t size)
{
size_t gap = 1, i, j;
int temp;

if (array == NULL || size < 2)
return;

/* Find initial gap using Knuth's sequence */
while (gap < size / 3)
gap = gap * 3 + 1;

/* Start sorting with decreasing gap intervals */
while (gap > 0)
{
for (i = gap; i < size; i++)
{
temp = array[i];
for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
{
array[j] = array[j - gap];
}
array[j] = temp;

/* Print array after each gap reduction */
print_array(array, size);

/* Decrease gap */
gap = (gap - 1) / 3;
}
}
