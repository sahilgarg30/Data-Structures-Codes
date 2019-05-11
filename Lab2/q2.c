#include <stdio.h>
int *pointerFunction(int *a,int *b){ //returns a pointer and takes in pointer
	int c = *a+*b;
	int *d = &c;
	return d;
}
int addPointer(int *a,int *b){
	int c = *a+*b;
	return c;
}
void main(){
	int a,b;
	printf("Enter 2 numbers - ");
	int *ptr = &a;
	int *ptr2 = &b;
	scanf("%d%d",ptr,ptr2);

	int f = addPointer(ptr,ptr2);
	printf("Using function taking in pointer, the sum is - %d\n",f);

	int *c = pointerFunction(ptr,ptr2);
	printf("Using function returning pointer, the sum is - %d\n",*c);

	int **d = &c;
	printf("Using pointer to pointer - %d\n",**d);
}
