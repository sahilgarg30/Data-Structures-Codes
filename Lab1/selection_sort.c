#include <stdio.h>
#include "selection_sort_fun.h"
void main()
{
int array[10];
int i, j, n, temp;
printf("Enter the value of n \n");
scanf("%d", &n);
printf("Enter the elements \n");
for (i = 0; i < n; i++)
scanf("%d", &array[i]);
/* Selection sorting begins */
exchange(array, n);
printf("The sorted list is (using selection sort): \n");
for (i = 0; i < n; i++)
printf("%d\t", array[i]);
}