#include <stdio.h>
int len(char a[],int i){
	if(a[i]=='\0')
		return 0;
	return 1+len(a,++i);
}
void main(){
		char s[100];
		scanf("%s",s);
		printf("The length is %d\n",len(s,0));
}
