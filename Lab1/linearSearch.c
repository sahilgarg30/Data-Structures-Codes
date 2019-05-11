#include <stdio.h>
void main(){
	int n,a[100];
	int check=0,i,find=0;
	printf("Enter total numbers to be searched - \n");
	scanf("%d",&n);
	printf("Enter the elements of the array - \n");
	for (i = 0; i < n; ++i)
	{
		scanf("%d",&a[i]);
	}
	printf("Enter the number to be searched - \n");
	scanf("%d",&find);
	for (i = 0; i < n; ++i)
	{
		if(find == a[i]){
			check=1;
			break;
		}
	}
	if(check==1){
		printf("Element exists at position - %d\n",i+1);
	}
	else{
		printf("Element does not exist.\n");
	}
}