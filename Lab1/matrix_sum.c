#include <stdio.h>
int add(int a[100][100],int m,int n,int b[100][100],int r,int col,int c[100][100]){
	int i,j;
	if(n!=col || m!=r){
		return 0;
	}
	else{
		for(i=0;i<m;i++){
			for(j=0;j<n;j++){
				c[i][j]=a[i][j]+b[i][j];
			}
		}
		return 1;
	}
}
void main(){
	int m,r,col,n,a[100][100],b[100][100],c[100][100];
	int sum=0,i,j;
	printf("Enter number of rows in matrix 1 - \n");
	scanf("%d",&m);
	printf("Enter number of columns in matrix 1 - \n");
	scanf("%d",&n);
	printf("Enter the elements of the matrix 1 - \n");
	for (i = 0; i < m; ++i)
	{
		for(j=0;j<n;j++)
		scanf("%d",&a[i][j]);
	}
	printf("Enter number of rows in matrix 2 - \n");
	scanf("%d",&r);
	printf("Enter number of columns in matrix 2 - \n");
	scanf("%d",&col);
	printf("Enter the elements of the matrix 2 - \n");
	for (i = 0; i < r; ++i)
	{
		for(j=0;j<col;j++)
		scanf("%d",&b[i][j]);
	}
	
	sum = add(a,m,n,b,r,col,c);
	if(sum==1){
	printf("The sum of matrices is -\n");
	for (i = 0; i < m; ++i)
	{
		for(j=0;j<n;j++)
		printf("%d\t",c[i][j]);
		printf("\n");
	}
}
	else
	printf("Matrices cannot be added.\n");
} 