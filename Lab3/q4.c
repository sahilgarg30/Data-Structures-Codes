#include <stdio.h>
int palin(char a[],int l,int r){
	if(l>r) return 1;
	if(a[l]==a[r]) return palin(a,++l,--r);
	return 0;
}
void main(){
	char a[100];
	scanf("%s",a);
	int len =0,i;
	for(i=0;a[i]!='\0';i++) len++;
	int check = palin(a,0,len-1);
	if(check==0)
		printf("Not a palindrome.\n");	
	else
		printf("Is a palindrome.\n");
}
