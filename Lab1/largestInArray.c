#include <stdio.h>
int largest(int a[],int n){
	int large=a[0];
	int i;
	for (i = 0; i < n; ++i)
	{
	 	if(a[i]>large){
	 		large=a[i];
	 	}
	}
	return large;
}
void main(){
	int n,array[100];
	int large=0,i;
	printf("Enter total numbers to be input - \n");
	scanf("%d",&n);
	printf("Enter the elements of the array - \n");
	for (i = 0; i < n; ++i)
	{
		scanf("%d",&array[i]);
	}
	large = largest(array,n);
	printf("The largest of numbers is - \n%d.\n",large);
} 