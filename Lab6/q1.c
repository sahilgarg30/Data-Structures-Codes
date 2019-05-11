#include <stdio.h>
#include <string.h>
#define MAX 3
typedef struct{
	int f;
	int r;
	char s[MAX][100];
}CQUEUE;

int isFull(CQUEUE q){
 if((q.r)+1 == q.f || (q.f==0 && q.r==MAX-1))
	return 1;
 return 0;
}

int isEmpty(CQUEUE q){
 if(q.f == -1)
	return 1;
 return 0;
}
void insertcq(CQUEUE *q,char a[100]){
	if(isFull(*q))
	printf("Queue is full.\n");	
	else{
		q->r = ((q->r)+1)%MAX;
		if(q->f==-1){
			q->f=0;
		}
		strcpy(q->s[q->r],a);
		printf("\nInserted.\n");	
	}
}
void deletecq(CQUEUE *q){
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
			q->f=(q->f+1)%MAX;
		}
	}
}
void displaycq(CQUEUE q){
	int i;
	for(i=q.f;i!=q.r;i=(i+1)%MAX){
		printf("%s.\t",q.s[i]);
	}
	printf("%s\n",q.s[i]);
}
void main(){
	CQUEUE cq;
	cq.f=-1;
	cq.r=-1;
	int choice=0;
    do{
	printf("\nPress 1 to insert, 2 to delete, 3 to display, 4 to exit.\n");
	scanf("%d",&choice);
    	char ele[100];	
	switch(choice){
		case 1 : printf("Enter element to be inserted -  \n");	
			 scanf("%s",ele);
			 insertcq(&cq,ele);
			 break;
		case 2 : deletecq(&cq);
			 break;
		case 3 : displaycq(cq);
			 break;		
	}
    }while(choice!=4);
}
