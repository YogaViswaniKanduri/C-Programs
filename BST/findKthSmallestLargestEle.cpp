/* Program to find kth largest and smallest element in binary search tree 
T=O(k)
*/

#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node * left;
	struct node * right;
};

struct node * createNode(int data)
{
	struct node * newNode=(struct node *)malloc(sizeof(struct node));
	newNode->data=data;
	newNode->left=NULL;
	newNode->right=NULL;
	return newNode;
}

struct node * findKthSmallestElement(struct node *root, int *k)
{
	if(root==NULL) return root;
	struct node * left=findKthSmallestElement(root->left,k);
	if(left) return left;
	if(*k==1) return root;
	*k-=1;
	struct node * right=findKthSmallestElement(root->right,k);
	if(right) return right;
	return NULL;
}

struct node * findKthLargestElement(struct node *root, int *k)
{
	if(root==NULL) return root;
	struct node * right=findKthLargestElement(root->right,k);
	if(right) return right;
	if(*k==1) return root;
	else *k-=1;
	struct node * left=findKthLargestElement(root->left,k);
	if(left) return left;
	return NULL;
}

int main()
{
	struct node * root=createNode(10);
	root->left=createNode(8);
	root->right=createNode(13);
	root->left->left=createNode(7);
	root->left->right=createNode(9);
	root->left->left->left=createNode(6);
	root->right->left=createNode(11);
	root->right->right=createNode(14);
	int k=5;
	struct node * element=findKthSmallestElement(root,&k);
	cout<<" Kth smallest element is: "<<(element?element->data:-1);
	k=10;
	element=findKthLargestElement(root,&k);
	cout<<" Kth largest element is: "<<(element?element->data:-1);
	return 0;
}
/*
output:
Kth smallest element is: 10 Kth largest element is: 9
for k=10
Kth smallest element is: 10 Kth largest element is: -1
 */