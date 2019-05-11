#include <stdio.h>
int add(int a[],int n){
	int sum=0;
	int i;
	for (i = 0; i < n; ++i)
	{
		sum += a[i];
	}
	return sum;
}
void main(){
	int n,array[100];
	int sum=0,i;
	printf("Enter total numbers to be added - \n");
	scanf("%d",&n);
	printf("Enter the elements of the array - \n");
	for (i = 0; i < n; ++i)
	{
		scanf("%d",&array[i]);
	}
	sum = add(array,n);
	printf("The sum of numbers is - \n%d.\n",sum);
} 