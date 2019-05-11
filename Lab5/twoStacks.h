#include <stdio.h>

typedef struct{
int top1;
int top2;
char a[100];
}Stack;

int isFull(Stack p){
 if(p.top1 >= p.top2-1)
	return 1;
 return 0;
}

int isEmpty1(Stack p){
 if(p.top1 == -1)
	return 1;
 return 0;
}
 

int isEmpty2(Stack p){
 if(p.top2 == 100)
	return 1;
 return 0;
}

int pop1(Stack *p){
	if(isEmpty1(*p))
		{printf("Stack is empty. Underflow. \n"); return '1';}
	else
		return p->a[(p->top1)--];
}

void push1(Stack *p,char ele){
	if(isFull(*p))
		printf("Stack is full. Overflow. \n");
	else
		p->a[++(p->top1)]=ele;
} 


int pop2(Stack *p){
	if(isEmpty2(*p))
		{printf("Stack is empty. Underflow. \n"); return '1';}
	else
		return p->a[(p->top2)++];
}

void push2(Stack *p,char ele){
	if(isFull(*p))
		printf("Stack is full. Overflow. \n");
	else
		p->a[--(p->top2)]=ele;
} 
void display1(Stack *p){
	int i;
	for(i=0;i<=p->top1;i++)
		printf("%c\t",p->a[i]);
}
void display2(Stack *p){
	int i;
	for(i=100-1;i>=p->top2;i--)
		printf("%c\t",p->a[i]);
}
char top1(Stack *p){
	return p->a[p->top1];
}
char top2(Stack *p){
	return p->a[p->top2];
}