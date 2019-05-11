#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include </home/student/sahilgarg_058/week4/stack.h>

int priority(char x){
	switch(x){
		case ')': return 0;
		case '+':
		case '-': return 1;
		case '*': 
		case '/':
		case '%': return 2;
		default : return 3;
	}
}

	void main(){
	Stack s;
	s.top = -1;
	char x[100];
	char a,b;
	int i,j=0;
	printf("Enter the infix expression - \n");
	scanf("%s",x);
	char prefix[100];

	for(i=strlen(x)-1;i>=0;i--){
		a = x[i];
		if(isalnum(a)){
			prefix[j++]=a;
		}
		else if(a==')'){
			push(&s,')');
		}
		else if(a=='('){
			while(b=pop(&s)!=')')
				prefix[j++]=b;
		}
		else if(a=='^' && top(&s)=='^'){
				b=pop(&s);
				prefix[j++]=b;
				push(&s,a);
		}
		else{
			while(priority(a)<priority(top(&s)) && !isEmpty(s)){
				b=pop(&s);
				prefix[j++]=b;
			}
			push(&s,a);
		}
	}

	while(!isEmpty(s)){
		a = pop(&s);
		prefix[j++]=a;
	}
	for(i=0;i<j/2;i++){
		char temp = prefix[i];
		prefix[i]=prefix[j-i-1];
		prefix[j-i-1]=temp;
	}
	prefix[j++]='\0';
	printf("The prefix expression is - %s\n",prefix);
}