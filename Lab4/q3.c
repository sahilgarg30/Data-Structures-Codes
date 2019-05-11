#include <stdio.h>
#include </home/student/sahilgarg_058/week4/stack.h>

void main(){
	int x;
	printf("Enter the decimal number - \n");
	scanf("%d",&x);
	Stack s;
	s.top=-1;
	while(x>0){
		push(&s,48+(x%2));
		x = x/2;
	}
	while(!isEmpty(s))
		printf("%c",pop(&s));
	printf("\n");
}
