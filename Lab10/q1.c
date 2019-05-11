#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int info;
	struct node *lchild,*rchild;
}NODE;
void postorder(NODE *ptr){
	if(ptr!=NULL){
		postorder(ptr->lchild);
		postorder(ptr->rchild);
		printf("%d\t",ptr->info);
	}
}
void preorder(NODE *ptr){
	if(ptr!=NULL){
		printf("%d\t",ptr->info);
		preorder(ptr->lchild);
		preorder(ptr->rchild);
	}
}
int search(NODE *ptr,int x){
	if(ptr!=NULL){
		if(ptr->info==x)
			return 1;
		if(search(ptr->lchild,x))
			return 1;
		if(search(ptr->rchild,x))
			return 1;
	}
	return 0;
}
void inorder(NODE *root)
{
  NODE *current,*pre;
 
  if(root == NULL)
     return; 
 
  current = root;
  while(current != NULL)
  {                 
    if(current->lchild == NULL)
    {
      printf("%d\t", current->info);
      current = current->rchild;      
    }    
    else
    {
      /* Find the inorder predecessor of current */
      pre = current->lchild;
      while(pre->rchild != NULL && pre->rchild != current)
        pre = pre->rchild;
 
      /* Make current as right child of its inorder predecessor */
      if(pre->rchild == NULL)
      {
        pre->rchild = current;
        current = current->lchild;
      }
             
      /* Revert the changes made in if part to restore the original 
        tree i.e., fix the right child of predecssor */   
      else 
      {
        pre->rchild = NULL;
        printf("%d\t",current->info);
        current = current->rchild;      
      } /* End of if condition pre->right == NULL */
    } /* End of if condition current->left == NULL*/
  } /* End of while */
}

NODE *create()
{
    NODE *p;
    int x;
    printf("Enter data(-1 for no data):");
    scanf("%d",&x);
    
    if(x==-1)
        return NULL;
    
    p=(NODE*)malloc(sizeof(NODE));
    p->info=x;
    
    printf("Enter left child of %d:\n",x);
    p->lchild=create();
 
    printf("Enter right child of %d:\n",x);
    p->rchild=create();
    
    return p;
}
void main(){
	NODE *root;
	printf("Enter the tree - \n");
    root=create();
    int choice=0;
    do{
    printf("\n1-search,2-inorder,3-preorder,4-postorder,5-exit\n");
    scanf("%d",&choice);
    switch(choice){
    	case 1 : printf("Enter element to be searched - \n");
    			 int ele;-                                                                             
    			 scanf("%d",&ele);
    			 if(search(root,ele)) printf("Found.\n");
    			 else printf("Does not exist.\n");
    			 break;
    	case 2 : inorder(root);
    			 break;
    	case 3: preorder(root);
    			break;
    	case 4: postorder(root);
    			break;
    }
	}while(choice!=5);
}
