#include <stdio.h>
#include <string.h>
#define MAX 10
typedef struct{
	int f;
	int r;
	char s[MAX][100];
}QUEUE;

int isFull(QUEUE q){
 if(q.r==MAX-1)
	return 1;
 return 0;
}

int isEmpty(QUEUE q){
 if(q.f == -1)
	return 1;
 return 0;
}
void insert_front(QUEUE *q,char a[100]){
	if(q->f <= 0) printf("Queue is full.\n");	
	else{
		q->f = (q->f)-1;
		strcpy(q->s[q->f],a);
		printf("\nInserted.\n");	
	}
}
void insert_rear(QUEUE *q,char a[100]){
	if(isFull(*q))
	printf("Queue is full.\n");	
	else{
		q->r = (q->r)+1;
		if(q->f==-1){
			q->f=0;
		}
		strcpy(q->s[q->r],a);
		printf("\nInserted.\n");	
	}
}
void delete_front(QUEUE *q){
	if(isEmpty(*q)){
		printf("Queue is empty.\n");	
	}
	else{
		if(q->r==q->f){
			printf("%s is deleted.\n",q->s[q->f]);	
			q->r=q->f=-1;
		}
		else{
			printf("%s is deleted.\n",q->s[q->f]);	
			q->f=q->f+1;
		}
	}
}
void displayq(QUEUE q){
	int i;
	if(isEmpty(q)){
		printf("Queue is empty.\n");
		return;	
	}
	for(i=q.f;i<=q.r;i++){
		printf("%s\t",q.s[i]);
	}
}
void main(){
	QUEUE q;
	q.f=-1;
	q.r=-1;
	int choice=0;
    do{
	printf("\nPress 1 to insert rear, 2 to insert front, 3 to delete, 4 to display, 5 to exit.\n");
	scanf("%d",&choice);
    	char ele[100];	
	switch(choice){
		case 1 : printf("Enter element to be inserted -  \n");	
			 scanf("%s",ele);
			 insert_rear(&q,ele);
			 break;
		case 2: printf("Enter element to be inserted -  \n");	
			 scanf("%s",ele);
			 insert_front(&q,ele);
			 break;
		case 3 : delete_front(&q);
			 break;
		case 4 : displayq(q);
			 break;		
	}
    }while(choice!=5);
}
