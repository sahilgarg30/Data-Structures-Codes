#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	char info;
	struct node *link;
}NODE;
NODE *insertq(NODE *first,char x){
	NODE *new,*temp;
	new = (NODE *)malloc(sizeof(NODE));
	if(new!=NULL){
	new->link=NULL;
	new->info=x;
	}
	if(first==NULL){
		new->link=new;
		return new;
	}
	temp=first;
	while(temp->link!=first)
		temp=temp->link;
	new->link=first;
	temp->link=new;
	return first;
}
void display(NODE *first){
	NODE *temp;
	temp =first;
	if(first==NULL) {printf("Queue empty.\n");return;}
	while(temp->link!=first){
		printf("%c\t",temp->info);
		temp=temp->link;
	}
	printf("%c\t",temp->info);
}
void main(){
	NODE *first;
	NODE *a;
	NODE *b;
	char ch;
	first=NULL;
	a=NULL;
	b=NULL;
	int n1,n2;
	int i=0;
	printf("Enter n1-\n");
	scanf("%d",&n1);
	printf("Enter sorted elements-\n");
	for(i=0;i<n1;i++){
		scanf(" %c",&ch);
		a=insertq(a,ch);
	}
	printf("Enter n2-\n");
	scanf("%d",&n2);
	printf("Enter sorted elements-\n");
	for(i=0;i<n2;i++){
		scanf("%s",&ch);
		b=insertq(b,ch);
	}
	NODE *af;
	NODE *bf;
	af=a;
	bf=b;
	for(;af->link!=a && bf->link!=b;){
		i=1;
		if(af->info<bf->info){
			first =insertq(first,af->info);
			af=af->link;
		}
		else{
			first = insertq(first,bf->info);
			bf=bf->link;
		}
	}
	while(af!=a){
		first = insertq(first,af->info);
		af=af->link;
	}
	while(bf!=b){
		first = insertq(first,bf->info);
		bf=bf->link;
	}
	display(first);
}