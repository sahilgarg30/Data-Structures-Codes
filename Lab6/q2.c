#include <stdio.h>
#define MAX 6
typedef struct{
	int f1,f2;
	int r1,r2;
	int s[MAX];
}CQUEUE;
int isFull1(CQUEUE q){
 if((q.r1)+1 == q.f1 || (q.f1==0 && q.r1==MAX/2-1))
	return 1;
 return 0;
}
int isEmpty1(CQUEUE q){
 if(q.f1 == -1)
	return 1;
 return 0;
}
int isFull2(CQUEUE q){
 if((q.r2)+1 == q.f2 || (q.f2==MAX/2 && q.r2==MAX-1))
	return 1;
 return 0;
}
int isEmpty2(CQUEUE q){
 if(q.f2 == MAX/2-1)
	return 1;
 return 0;
}
void insertcq1(CQUEUE *q,int a){
	if(isFull1(*q))
	printf("Queue is full.\n");	
	else{
		q->r1 = ((q->r1)+1)%(MAX/2);
		if(q->f1==-1){
			(q->f1)++;
		}
		q->s[q->r1]=a;
		printf("\nInserted.\n");	
	}
}
void deletecq1(CQUEUE *q){
	if(isEmpty1(*q)){
		printf("Queue is empty.\n");	
	}
	else{
		if(q->r1==q->f1){
			printf("%d is deleted.\n",q->s[q->f1]);	
			q->r1=q->f1=-1;
		}
		else{
			printf("%d is deleted.\n",q->s[q->f1]);	
			q->f1=(q->f1+1)%(MAX/2);
		}
	}
}
void insertcq2(CQUEUE *q,int a){
	if(isFull2(*q))
	printf("Queue is full.\n");	
	else{
		if(q->r2!=MAX-1)
		q->r2 = ((q->r2)+1);
		else
		q->r2 = MAX/2;
		if(q->f2==MAX/2-1){
			(q->f2)++;
		}
		q->s[q->r2]=a;
		printf("\nInserted.\n");	
	}
}
void deletecq2(CQUEUE *q){
	if(isEmpty2(*q)){
		printf("Queue is empty.\n");	
	}
	else{
		if(q->r2==q->f2){
			printf("%d is deleted.\n",q->s[q->f2]);	
			q->r2=q->f2=MAX/2-1;
		}
		else{
			printf("%d is deleted.\n",q->s[q->f2]);
			if(q->f2!=MAX-1)
			q->f2 = ((q->f2)+1);
			else
			q->f2 = MAX/2;
		}
	}
}
void displaycq1(CQUEUE q){
	int i;
	for(i=q.f1;i!=q.r1;i=(i+1)%(MAX/2)){
		printf("%d \t",q.s[i]);
	}
	if(!isEmpty1(q))
	printf("%d\n",q.s[i]);
}
void displaycq2(CQUEUE q){
	int i;
	for(i=q.f2;i!=q.r2;){
		printf("%d \t",q.s[i]);
		if(i!=MAX-1)
			i++;
		else
			i = MAX/2;
	}
	if(!isEmpty2(q))
	printf("%d\n",q.s[i]);
}
void main(){
	int choice=0;
	CQUEUE cq;
	cq.f1 = cq.r1 = -1;
	cq.f2 = cq.r2 = MAX/2-1;
    do{
	printf("\nPress 1 to insert1, 2 to delete1, 3 to display1, 4 to insert2, 5 to delete2, 6 to diplay2, 7 to exit. \n");
	scanf("%d",&choice);
    	int ele;	
	switch(choice){
		case 1 : printf("Enter element to be inserted -  \n");	
			 scanf("%d",&ele);
			 insertcq1(&cq,ele);
			 break;
		case 2 : deletecq1(&cq);
			 break;
		case 3 : displaycq1(cq);
			 break;
		case 4 : printf("Enter element to be inserted -  \n");	
			 scanf("%d",&ele);
			 insertcq2(&cq,ele);
			 break;
		case 5 : deletecq2(&cq);
			 break;
		case 6 : displaycq2(cq);
			 break;		
	}
    }while(choice!=7);
}