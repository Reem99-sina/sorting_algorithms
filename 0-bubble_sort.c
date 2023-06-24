#include "sort.h"
#include <stdbool.h>
/**
 *bubble_sort -  sorts an array of integers using the Bubble sort algorithm
 *@array:array point
 *@size:sizeof arrray
 *Return:no return
*/
void bubble_sort(int *array, size_t size)
{
int tmp;
size_t i = 0;
size_t j;
size_t k;
bool swapped;
if (array == NULL || size < 2)
{
return;
}
while (i < size - 1)
{
swapped = false;
for (j = 0; j < size - i - 1; j++)
{
if (array[j] > array[j + 1])
{
tmp = array[j];
array[j] = array[j + 1];
array[j + 1] = tmp;
swapped = true;
for (k = 0; k < size; k++)
{
if (k == size - 1)
{
printf("%d", array[k]);
}
else
{
printf("%d, ", array[k]);
}
}
printf("\n");
}
}

if (swapped == false)
{
break;
}
i++;
}
}
