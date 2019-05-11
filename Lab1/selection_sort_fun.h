/* function to find the minimum value */
int findmin(int b[10], int k)
{
int min = 0, j;for (j = 1; j <= k; j++)
{
if (b[min] < b[j])
min = j;
}
return(min);
}
/* function to exchange the value */
void exchange(int b[10], int k)
{
int temp, small, j;
for (j = k - 1; j >= 1; j--)
{
small = findmin(b, j);
temp = b[small];
b[small] = b[j];
b[j] = temp;
}
return;
}