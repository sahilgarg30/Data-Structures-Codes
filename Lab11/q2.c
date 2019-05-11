#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char info;
    struct node* lchild, *rchild;
}NODE;
 
int isOperator(char c)
{
    if (c == '+' || c == '-' ||
            c == '*' || c == '/' ||
            c == '^')
        return 1;
    return 0;
}
 
NODE* newNode(int v)
{
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    temp->lchild = temp->rchild = NULL;
    temp->info = v;
    return temp;
}
void inorder(NODE *t)
{
    if(t)
    {
        inorder(t->lchild);
        printf("%c ", t->info);
        inorder(t->rchild);
    }
}
NODE* create(char postfix[])
{
    NODE *stack[100];
    int top=-1;
    NODE *t, *t1, *t2;
    int i;
    for (i=0;postfix[i]!='\0'; i++)
    {
        if (!isOperator(postfix[i]))
        {
            t = newNode(postfix[i]);
            stack[++top]=t;
        }
        else
        {
            t = newNode(postfix[i]);
 
            t1 = stack[top]; 
            top--;     
            t2 = stack[top];
            top--;
 
            t->rchild = t1;
            t->lchild = t2;
 
            stack[++top]=t;
        }
    }
    t = stack[top];
    top--;
    return t;
}
int eval(NODE* root)
{
    // empty tree
    if (root==NULL)
        return 0;
 
    // leaf node i.e, an integer
    if (root->lchild==NULL && root->rchild==NULL)
        return root->info-48;

    int l_val = eval(root->lchild);
    int r_val = eval(root->rchild);
 
    // Check which operator to apply
    if (root->info=='+')
        return l_val+r_val;
 
    if (root->info=='-')
        return l_val-r_val;
 
    if (root->info=='*')
        return l_val*r_val;
 
    return l_val/r_val;
}
void main()
{
    char postfix[100];// = "ab+ef*g*-";
    NODE *root = NULL;
    scanf("%s",postfix);
    root = create(postfix);
    printf("infix expression is \n");
    inorder(root);
    printf("\nEval is %d",eval(root));
}