/*program to print Lowest Common Ancestor*/
#include<stdio.h>
#include<stdlib.h>
struct node * lowestCommonAncestorUtil(struct node * temp, int a, int b);
struct node
{
	int data;
	struct node * left;
	struct node * right;
};
//function to tell whether inputs are in bst are not
int search(struct node * root, int key)
{
	if (root==NULL)
		return 0;
	if (root->data==key)
		return 1;
	if(root->data<=key)
		return search(root->right,key);
	else return search(root->left,key);
	
}
struct node * lowestCommonAncestor(struct node * root, int a, int b)
{
	if(root!=NULL&&search(root,a)&&search(root,b))
	{
		if(a<=b)
		return lowestCommonAncestorUtil(root,a,b);
		else return lowestCommonAncestorUtil(root,b,a);
	}
	
}
struct node * lowestCommonAncestorUtil(struct node * root, int a, int b)
{
	if(root==NULL)
		return NULL;
	int key=root->data;
	if(a<=key && key <=b) //a<=key<=b
		return root;
	else if(a<=b && b<=key) //a<=b<=key
		return lowestCommonAncestorUtil(root->left,a,b);
	else //key<=a<=b
		return lowestCommonAncestorUtil(root->right,a,b);
}
struct node * newNode(int data)
{
	struct node * temp=(struct node *)malloc(sizeof(struct node));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
int main()
{
	struct node *root        = newNode(20);
    root->left               = newNode(8);
    root->right              = newNode(22);
    root->left->left         = newNode(4);
    root->left->right        = newNode(12);
    root->left->right->left  = newNode(10);
    root->left->right->right = newNode(14);
	int n1 = 10, n2 = 14;
    struct node *t = lowestCommonAncestor(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);
 
    n1 = 14, n2 = 8;
    t = lowestCommonAncestor(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);
 
    n1 = 10, n2 = 22;
    t = lowestCommonAncestor(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data); 
    
    n1 = 10, n2 = 12;
    t = lowestCommonAncestor(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data); 
    
    n1 = 4, n2 = 14;
    t = lowestCommonAncestor(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data); 
    
    n1 = 4, n2 = 12;
    t = lowestCommonAncestor(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data); 
    
    n1 = 4, n2 = 15;
    t = lowestCommonAncestor(root, n1, n2);
    if(t!=NULL)
    {
    printf("LCA of %d and %d is %d \n", n1, n2, t->data); 
    }
    else printf("LCA of %d and %d is NULL",n1, n2);
    
    return 0;
}
/*
Output:
LCA of 10 and 14 is 12 
LCA of 14 and 8 is 8 
LCA of 10 and 22 is 20 
LCA of 10 and 12 is 12 
LCA of 4 and 14 is 8 
LCA of 4 and 12 is 8 
LCA of 4 and 15 is NULL
*/