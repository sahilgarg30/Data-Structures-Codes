#include <stdio.h>
#include </home/student/sahilgarg_058/week4/stack.h>

void main(){
	int choice=0;
	Stack s;
	s.top = -1;
    do{
	printf("\nPress 1 to push, 2 to pop, 3 to display and 4 to exit. \n");
	scanf("%d",&choice);
    	char ele;	
	switch(choice){
		case 1 : printf("Enter element to be inserted -  \n");	
			 scanf("%s",&ele);
			 push(&s,ele);
			 break;
		case 2 : ele = pop(&s);
			 if(ele!='1') printf("The value %c is popped out.\n",ele);
			 break;
		case 3 : display(&s);
			 break;	
	}
    }while(choice!=4);
}
