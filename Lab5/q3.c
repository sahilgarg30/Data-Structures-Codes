#include <stdio.h>
#include </home/student/sahilgarg_058/week5/twoStacks.h>

void main(){
	int choice=0;
	Stack s;
	s.top1 = -1;
	s.top2 = 100;
    do{
	printf("\nPress 1 to push1, 2 to pop1, 3 to display1, 4 to push2, 5 to pop2, 6 to diplay2, 7 to exit. \n");
	scanf("%d",&choice);
    	char ele;	
	switch(choice){
		case 1 : printf("Enter element to be inserted -  \n");	
			 scanf("%s",&ele);
			 push1(&s,ele);
			 break;
		case 2 : ele = pop1(&s);
			 if(ele!='1') printf("The value %c is popped out.\n",ele);
			 break;
		case 3 : display1(&s);
			 break;
		case 4 : printf("Enter element to be inserted -  \n");	
			 scanf("%s",&ele);
			 push2(&s,ele);
			 break;
		case 5 : ele = pop2(&s);
			 if(ele!='1') printf("The value %c is popped out.\n",ele);
			 break;
		case 6 : display2(&s);
			 break;		
	}
    }while(choice!=7);
}
