#include <stdio.h>

void main(){
	int a[10];
	int n;
	printf("Enter the number of elements - \n");
	scanf("%d",&n);
	int i;
	printf("Enter the elements - \n");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int *p = a;
	printf("The elements in forward are - \n");
	for(i=0;i<n;i++){
		printf("%d\t",*(p++));
	}
	printf("\n");
	p--;
	printf("The elements in backward are - \n");
	for(i=n-1;i>=0;i--){
		printf("%d\t",*(p--));
	}
}