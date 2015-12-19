/*program to print size of a tree*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node * left;
	struct node * right;
};
int sizeOfBinaryTree(struct node * curr)
{
	if(curr==NULL)
		return 0;
	return 1+ sizeOfBinaryTree(curr->left)+sizeOfBinaryTree(curr->right);
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
	struct node * root=newNode(20);
	root->left=newNode(8);
	root->right=newNode(22);
	root->left->left=newNode(4);
	root->left->right=newNode(12);
	root->left->right->left=newNode(10);
	root->left->right->right=newNode(14);
	root->right->right=newNode(32);
	printf("\nSize of a binary tree:%d",sizeOfBinaryTree(root));
	getchar();
	return 0;
}
/*
Output:
Size of a binary tree:8
*/