#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node{
	char info[100];
	struct node *rlink;
	struct node *llink;
}NODE;
NODE *insertq(NODE *first,char x[100]){
	NODE *new,*temp;
	new = (NODE *)malloc(sizeof(NODE));
	if(new!=NULL){
	new->rlink=NULL;
	new->llink=NULL;
	strcpy(new->info,x);
	}
	if(first==NULL) return new;
	temp=first;
	while(temp->rlink!=NULL)
		temp=temp->rlink;
	new->llink=temp;
	temp->rlink=new;
	return first;
}
void display(NODE *first){
	NODE *temp;
	temp =first;
	if(first==NULL) {printf("Queue empty.\n");return;}
	while(temp->rlink!=NULL){
		printf("%s\t",temp->info);
		temp=temp->rlink;
	}
	printf("%s\n",temp->info);
}
NODE *reverse(NODE *first){
	NODE *start = first;
	NODE *last = first;
	while(last->rlink != NULL) last=last->rlink;
	while(start != last){
		char a[100];
		strcpy(a,start->info);
		strcpy(start->info,last->info);
		strcpy(last->info,a);
		start = start->rlink;
		if(start==last) break;
		last = last->llink;
	}
	return first;
}
void main(){
	NODE *a;
	a = NULL;
	int n1,i;
	char ch[100];
	printf("Enter n1-\n");
	scanf("%d",&n1);
	printf("Enter first number with spaces-\n");
	for(i=0;i<n1;i++){
		scanf("%s",ch);
		a=insertq(a,ch);
	}
	display(a);
	a = reverse(a);
	display(a);
}