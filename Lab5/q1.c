#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include </home/student/sahilgarg_058/week4/stack.h>

int evaluate(char x,int a,int b){
	switch(x){
		case '+': return a+b;
		case '-': return a-b;
		case '*': return a*b;
		case '/': return a/b;
		case '%': return a%b;
	}
}
void main(){
	Stack s;
	s.top = -1;
	char x[100];
	char a;
	printf("Enter the prefix expression - \n");
	scanf("%s",x);
	int i,op1,op2,val;
	int len = strlen(x);
	for(i=len-1;i>=0;i--){
		a=x[i];
		if(isdigit(a))
			push(&s,a);
		else{
			op1 = pop(&s)-48;
			op2 = pop(&s)-48;
			val = evaluate(a,op1,op2);
			push(&s,val+48);
		}
	}
	val = pop(&s)-48;
	printf("Value of expression is %d\n",val);
}