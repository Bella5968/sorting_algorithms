#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order
 *               using the Bubble sort algorithm.
 * @array: The array of integers to sort.
 * @size: The size of the array.
 */
void bubble_sort(int *array, size_t size)
{
size_t i, n;
int temp;
bool swapped;

if (size < 2)
return;

for (n = size; n > 1; n--)
{
swapped = false;
for (i = 1; i < n; i++)
{
if (array[i - 1] > array[i])
{
temp = array[i];
array[i] = array[i - 1];
array[i - 1] = temp;
swapped = true;
print_array(array, size); /* Print after each swap */
}
}
if (!swapped)
break;
}
}
