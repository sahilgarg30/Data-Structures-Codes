#include <stdio.h>
void main(){
	int n,i,a[10000],freq[201],j;
	printf("Enter the number of random numbers to be generated - \n");
	scanf("%d",&n);

	for(i=0;i<n;i++){
		a[i] = rand()%201 - 100;
	}
	for(i=0;i<n;i++){
		for(j=-100;j<101;j++){
			if(a[i]==j){
				freq[j+101-1]++;
			}
		}
	}
	for(i=0;i<201;i++){
		printf("%d ",freq[i] );
	}
}
