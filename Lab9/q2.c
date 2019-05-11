#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int info;
	struct node *rlink;
	struct node *llink;
}NODE;
NODE *insertq(NODE *first,int x){
	NODE *new,*temp;
	new = (NODE *)malloc(sizeof(NODE));
	if(new!=NULL){
	new->rlink=first;
	new->llink=NULL;
	new->info=x;
	}
	temp=first;
	while(temp->rlink!=first)
		temp=temp->rlink;
	new->llink=temp;
	temp->rlink=new;
	first->llink=new;
	(first->info)++;
	return first;
}
void display(NODE *first){
	NODE *temp;
	temp =first;
	if(first->rlink==first) {printf("Queue empty.\n");return;}
	while(temp->rlink!=first){
		printf("%d\t",temp->info);
		temp=temp->rlink;
	}
	printf("%d\t",temp->info);
}
void display_end(NODE *first){
	NODE *temp;
	temp=first;
	while(temp->rlink!=first) temp=temp->rlink;
	while(temp!=first){
		printf("%d",temp->info);
		temp=temp->llink;
	}
	printf("\n");
}
NODE *add_long(NODE *a,NODE *b,NODE *r){
	int c=0,rem,sum;
	NODE *num1=a;
	NODE *num2=b;
	while(num1->llink!=a && num2->llink!=b){
		sum = num1->info + num2->info +c;
		rem = sum%10;
		c = sum/10;
		r = insertq(r,rem);
		num1=num1->llink;
		num2=num2->llink;
	}
	while(num1->llink!=a){
		sum = num1->info +c;
		rem = sum%10;
		c = sum/10;
		r = insertq(r,rem);
		num1=num1->llink;
	}
	while(num2->llink!=b){
		sum = num2->info +c;
		rem = sum%10;
		c = sum/10;
		r = insertq(r,rem);
		num2=num2->llink;
	}
	if(c==1){
		r = insertq(r,c);
	}
	return r;
}
void main(){
	NODE *is;
	NODE *a;
	NODE *b;
	is=NULL;
	a=NULL;
	b=NULL;
	int ch;
	int n1,n2;
	int i=0;
	a = (NODE *)malloc(sizeof(NODE));
	a->rlink=a;
	a->llink=a;
	a->info=0;
	b= (NODE *)malloc(sizeof(NODE));
	b->rlink=b;
	b->llink=b;
	b->info=0;
	is= (NODE *)malloc(sizeof(NODE));
	is->rlink=is;
	is->llink=is;
	is->info=0;
	printf("Enter n1-\n");
	scanf("%d",&n1);
	printf("Enter first number with spaces-\n");
	for(i=0;i<n1;i++){
		scanf(" %d",&ch);
		a=insertq(a,ch);
	}
	printf("Enter n2-\n");
	scanf("%d",&n2);
	printf("Enter second number with spaces -\n");
	for(i=0;i<n2;i++){
		scanf("%d",&ch);
		b=insertq(b,ch);
	}
	NODE *bf,*af;
	bf=b;
	af=a;
	while(af->rlink!=a) af=af->rlink;
	while(bf->rlink!=b) bf=bf->rlink;
	is = add_long(af,bf,is);
	display_end(is);
}
