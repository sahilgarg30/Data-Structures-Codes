#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int info;
	struct node *lchild,*rchild;
}NODE;
void inorder(NODE *ptr){
	if(ptr!=NULL){
		inorder(ptr->lchild);
		printf("%d\t",ptr->info);
		inorder(ptr->rchild);
	}
}
void preorder(NODE* root)
{
    while (root)
    {
        // If left child is null, print the current node data. Move to
        // right child.
        if (root->lchild == NULL)
        {
            printf( "%d\t", root->info );
            root = root->rchild;
        }
        else
        {
            // Find inorder predecessor
            NODE* current = root->lchild;
            while (current->rchild && current->rchild != root)
                current = current->rchild;
 
            // If the right child of inorder predecessor already points to
            // this node
            if (current->rchild == root)
            {
                current->rchild = NULL;
                root = root->rchild;
            }
 
            // If right child doesn't point to this node, then print this
            // node and make right child point to this node
            else
            {
                printf("%d\t", root->info);
                current->rchild = root;
                root = root->lchild;
            }
        }
    }
}
void main(){
	NODE *root;
	printf("Enter the tree - \n");
    root=create();
    int choice=0;
    do{
    printf("\n1-preorder,2-inorder,3-postorder,4-exit\n");
    scanf("%d",&choice);
    switch(choice){
    	case 1 : preorder(root);
    			 break;
    	case 2 : inorder(root);
    			 break;
    	case 3:  //postorder(root);
    			 break;
    }
	}while(choice!=4);
}
