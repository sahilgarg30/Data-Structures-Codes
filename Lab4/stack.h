#include <stdio.h>

typedef struct{
int top;
char a[100];
}Stack;

int isFull(Stack p){
 if(p.top >= 100)
	return 1;
 return 0;
}

int isEmpty(Stack p){
 if(p.top == -1)
	return 1;
 return 0;
}
 
int pop(Stack *p){
	if(isEmpty(*p))
		{printf("Stack is empty. Underflow. \n"); return '1';}
	else
		return p->a[(p->top)--];
}

void push(Stack *p,char ele){
	if(isFull(*p))
		printf("Stack is full. Overflow. \n");
	else
		p->a[++(p->top)]=ele;
} 

void display(Stack *p){
	int i;
	for(i=0;i<=p->top;i++)
		printf("%c\t",p->a[i]);
}

