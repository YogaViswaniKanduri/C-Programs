/*program to construct mirror of a tree*/
/*program to construct mirror of a tree*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node * left;
	struct node * right;
};
struct node * newNode(int data)
{
	struct node * temp=(struct node *)malloc(sizeof(struct node));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
struct node * ConstructMirror(struct node * curr)
{
	if(curr==NULL)
		return curr;
	struct node * temp = newNode(curr->data);
	temp->left=ConstructMirror(curr->right);
	temp->right=ConstructMirror(curr->left);
	return temp;
}
void displayTreeInorder(struct node * root)
{
	if (root!=NULL)
	{
		displayTreeInorder(root->left);
		printf("%d\t",root->data);
		displayTreeInorder(root->right);
	}
		
}
void displayTreePreorder(struct node * root)
{
	if (root!=NULL)
	{
		printf("%d\t",root->data);
		displayTreePreorder(root->left);
		displayTreePreorder(root->right);
	}
		
}
void displayTreePostorder(struct node * root)
{
	if (root!=NULL)
	{
		
		displayTreePostorder(root->left);
		displayTreePostorder(root->right);
		printf("%d\t",root->data);
	}
		
}
int main()
{
	struct node * root=newNode(20);
	root->left=newNode(8);
	root->right=newNode(22);
	root->left->left=newNode(4);
	root->left->right=newNode(12);
	root->left->right->left=newNode(10);
	root->left->right->right=newNode(14);
	root->right->right=newNode(32);
	printf("\ninorder of original tree:\n");
	displayTreeInorder(root);
	printf("\npreorder of original tree:\n");
	displayTreePreorder(root);
	printf("\npostorder of original tree:\n");
	displayTreePostorder(root);
	printf("\nConstructed new tree");
	struct node * newRoot=ConstructMirror(root);
	printf("\ninorder of constructed tree:\n");
	displayTreeInorder(newRoot);
    printf("\npreorder of constructed tree:\n");
	displayTreePreorder(newRoot);
	printf("\npostorder of constructed tree:\n");
	displayTreePostorder(newRoot);
	return 0;
}
/*
Output:
inorder of original tree:
4	8	10	12	14	20	22	32	
preorder of original tree:
20	8	4	12	10	14	22	32	
postorder of original tree:
4	10	14	12	8	32	22	20	
Constructed new tree
inorder of constructed tree:
32	22	20	14	12	10	8	4	
preorder of constructed tree:
20	22	32	8	12	14	10	4	
postorder of constructed tree:
32	22	14	10	12	4	8	20	
*/