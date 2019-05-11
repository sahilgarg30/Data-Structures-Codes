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
		printf("%d\t",temp->info);
		temp=temp->link;
	}
	printf("%d\t",temp->info);
}
NODE *delete(NODE *first,int ele){
	NODE *temp = first;
	NODE *prev = NULL;
	NODE *last = first;
	while(last->link!=first){
		last=last->link;
	}
	if(temp->info == ele){
		first = first->link;
		last->link=first;
		free(temp);
		temp=NULL;
		return first;
	}
	while(temp->link!=first && temp->info!=ele){
		prev=temp;
		temp=temp->link;
	}
	if(prev!=NULL){
		prev->link=temp->link;
		free(temp);
		temp=NULL;
		return first;
	} 
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
	printf("Enter n1-\n");
	scanf("%d",&n1);
	printf("Enter elements-\n");
	for(i=0;i<n1;i++){
		scanf(" %d",&ch);
		a=insertq(a,ch);
	}
	printf("Enter n2-\n");
	scanf("%d",&n2);
	printf("Enter elements-\n");
	for(i=0;i<n2;i++){
		scanf("%d",&ch);
		b=insertq(b,ch);
	}
	NODE *af;
	NODE *bf;
	af=a;
	bf=b;
	while(af->link != a){
		while(bf->link != b){
			if(af->info == bf->info){
				is = insertq(is,af->info);
				b = delete(b,bf->info);
				break;
			}
			else{
				bf=bf->link;
			}
		}
		if(af->info == bf->info){
			is = insertq(is,af->info);
			b = delete(b,bf->info);
		}
		af=af->link;
		bf=b;		
	}
	if(af->info == bf->info){
			is = insertq(is,af->info);
			b = delete(b,bf->info);
	}
	printf("The union is - \n");
	display(a);
	display(b);
	printf("\nThe intersection is - \n");
	display(is);
}