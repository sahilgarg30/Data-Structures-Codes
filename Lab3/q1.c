#include <stdio.h>
void mult(int a[][100],int b[][100],int c[][100],int r1,int c1,int r2,int c2){
	static int i=0,j=0,k=0;
	if(i>=r1)
		return;
	if(i<r1){
		if(j<c2){
			if(k<c1){
				c[i][j] += a[i][k]*b[k][j];
				k++;
				mult(a,b,c,r1,c1,r2,c2);
			}	
			k=0;
			j++;
			mult(a,b,c,r1,c1,r2,c2);
		}
		j=0;
		i++;
		mult(a,b,c,r1,c1,r2,c2);
	} 
}
void main(){
	int a[100][100],b[100][100],c[100][100];
	int r1,c1,r2,c2;
	printf("Enter the number of rows and columns in each matrix - \n");
	scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
	int i,j;
	printf("Enter the values of matrix 1 - \n");
	for(i=0;i<r1;i++){
		for(j=0;j<c1;j++)
			scanf("%d",&a[i][j]);
	}
	printf("Enter the values of matrix 2 - \n");
	for(i=0;i<r2;i++){
		for(j=0;j<c2;j++)
			scanf("%d",&b[i][j]);
	}
	if(c1==r2){
		mult(a,b,c,r1,c1,r2,c2);
		printf("Enter the values of matrix 2 - \n");
		for(i=0;i<r1;i++){
			for(j=0;j<c2;j++)
			printf("%d\t",c[i][j]);
			printf("\n");
		}
	}
	else if(c2==r1){
		mult(b,a,c,r2,c2,r1,c1);
		for(i=0;i<r2;i++){
			for(j=0;j<c1;j++)
			printf("%d\t",c[i][j]);
			printf("\n");
		}
	}
	else
		printf("Can't be multiplied.\n");
}
