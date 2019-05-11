#include <stdio.h>
#include </home/student/sahilgarg_058/week4/stack.h>

void main(){
	char a[100];
	printf("Enter the string - \n");
	scanf("%s",a);
	int len =0;
	int i;
	int check =0;
	Stack s;
	s.top=-1;
	for(len=0;a[len]!='\0';len++);
	for(i=0;i<len;i++)
		push(&s,a[i]);
	for(i=0;i<len;i++)
		if(pop(&s)!=a[i]){ check =1 ; break;}
	
	if(check==0)
		printf("Is a palindrome.\n");
	else
		printf("Not a palindrome.\n");
}
