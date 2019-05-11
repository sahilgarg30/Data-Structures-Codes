#include <stdio.h>
void copys(char a[],char b[],int i){
	if(b[i]=='\0'){
		a[i]='\0';
		return;
	}
	else{
		a[i]=b[i];
		copys(a,b,++i);
	}
}
void main(){
	char s1[100],s2[100];
	scanf("%s",s2);
	copys(s1,s2,0);
	printf("The copied new string is - %s\n",s1);	
}
