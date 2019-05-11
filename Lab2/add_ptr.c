#include <stdio.h>
void main(){
	int a,b;
	printf("Enter 2 numbers - ");
	int *ptr = &a;
	int *ptr2 = &b;
	scanf("%d%d",ptr,ptr2);
	int c = *ptr+*ptr2;
	printf("The sum is - %d\n",c);
}