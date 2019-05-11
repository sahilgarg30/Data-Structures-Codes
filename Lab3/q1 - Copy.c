#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int info;
	struct node *link;
}NODE;

NODE *insertq(NODE *first,int x){
	NODE *new,*temp;
	new = (NODE *)malloc(sizeof(NODE));
	if(new!=NULL){
	new->link=NULL;
	new->info=x;
	}
	if(first==NULL){
		return new;
	}
	temp=first;
	while(temp->link!=NULL)
		temp=temp->link;
	temp->link=new;
	return first;
}
NODE *deleteq(NODE *first){
	NODE *temp;
	temp=first;
	if(first==NULL)
		return first;
	first=first->link;
	free(temp);
	return first;
}
void display(NODE *first){
	NODE *temp;
	temp =first;
	if(first==NULL) {printf("Queue empty.\n");return;}
	while(temp!=NULL){
		printf("%d\t",temp->info);
		temp=temp->link;
	}
}
void main(){
	NODE *first;
	int x,ch;
	first=NULL;
	do{
		printf("1-insert 2-delete 3-display 4-exit\n");
		scanf("%d",&ch);
		switch(ch){
			case 1: printf("Enter the value -\n");
					scanf("%d",&x);
					first=insertq(first,x);
					break;
			case 2: first=deleteq(first);
					break;
			case 3: display(first);
					break;
		}
	}while(ch!=4);
}