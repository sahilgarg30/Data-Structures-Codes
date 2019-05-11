#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int info;
	struct node *lchild,*rchild;
}NODE;
NODE *create(NODE *root, int x)
{
    if(root==NULL){
    root=(NODE*)malloc(sizeof(NODE));
    root->info=x;
    root->lchild=root->rchild=NULL;
    }
    else if(x>root->info)
    root->rchild=create(root->rchild,x);
 	else if(x<root->info)
    root->lchild=create(root->lchild,x);
    else{
    	printf("Duplicate node.\n");
     	return root;
    }
    return root;
}
NODE *minValueNode(NODE* node)
{
    NODE* current = node;
 
    /* loop down to find the leftmost leaf */
    while (current->lchild != NULL)
        current = current->lchild;
 
    return current;
}
NODE* delete(NODE* root, int x)
{
    // base case
    if (root == NULL) return root;
 
    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (x < root->info)
        root->lchild = delete(root->lchild, x);
 
    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (x > root->info)
        root->rchild = delete(root->rchild, x);
 
    // if key is same as root's key, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (root->lchild == NULL)
        {
            NODE *temp = root->rchild;
            free(root);
            return temp;
        }
        else if (root->rchild == NULL)
        {
            NODE *temp = root->lchild;
            free(root);
            return temp;
        }
 
        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        NODE *temp = minValueNode(root->rchild);
 
        // Copy the inorder successor's content to this node
        root->info = temp->info;
 
        // Delete the inorder successor
        root->rchild = delete(root->rchild, temp->info);
    }
    return root;
}
int height(NODE *root)
{
    if (root==NULL)
        return 0;
    else
    {
        /* compute the height of each subtree */
        int lheight = height(root->lchild);
        int rheight = height(root->rchild);
 
        /* use the larger one */
        if (lheight > rheight)
            return(lheight+1);
        else 
        	return(rheight+1);
    }
}
/* Print nodes at a given level */
void printLevel(NODE *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->info);
    else if (level > 1)
    {
        printLevel(root->lchild, level-1);
        printLevel(root->rchild, level-1);
    }
}

void levelorder(NODE *root)
{
    int h = height(root);
    int i;
    for (i=1; i<=h; i++)
    {
        printLevel(root, i);
        printf("\n");
    }
}
void main(){
	NODE *root;
	root=NULL;
	int ch=1;
	int x;
	while(ch!=4){
		printf("1.Insert 2.Delete 3.Level Order 4.Exit\n");
		scanf("%d",&ch);
		switch(ch){
			case 1: printf("Enter the node (no duplicates)-\n");
					scanf("%d",&x);
					root=create(root,x);
					break;

			case 2: printf("Enter the node to be deleted-\n");
					scanf("%d",&x);
					root=delete(root,x);
					break;

			case 3: levelorder(root);
					break;
		}
	}
}