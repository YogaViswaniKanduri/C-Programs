/*program to convert a tree into mirror inplace*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node * left;
	struct node * right;
};
//Top down approach
void convertMirrorInPlace(struct node * curr)
{
	if (curr==NULL)
	{
		return;
	}
	if(curr->left!=NULL || curr->right!=NULL)
	{
		struct node * temp;
		temp=curr->left;
		curr->left=curr->right;
		curr->right=temp;
	}
	convertMirrorInPlace(curr->left);
	convertMirrorInPlace(curr->right);	
}
//Bottom up approach
void convertMirrorInPlaceBottomUp(struct node * curr)
{
	if (curr==NULL)
	{
		return;
	}
	convertMirrorInPlaceBottomUp(curr->left);
	convertMirrorInPlaceBottomUp(curr->right);
	struct node * temp;
	temp=curr->left;
	curr->left=curr->right;
	curr->right=temp;	
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
	convertMirrorInPlaceBottomUp(root);
	printf("\ninorder of constructed tree:\n");
	displayTreeInorder(root);
    printf("\npreorder of constructed tree:\n");
	displayTreePreorder(root);
	printf("\npostorder of constructed tree:\n");
	displayTreePostorder(root);
	return 0;
	
}