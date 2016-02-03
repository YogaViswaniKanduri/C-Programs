#include <iostream>
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


int findLeafCount(struct node * root)
{
	if(root==NULL) return 0;
	if(root->left==NULL && root->right ==NULL)
		return 1;
	return findLeafCount(root->left)+findLeafCount(root->right);

}

int main()
{
	struct node * root=createNode(5);
	root->left=createNode(6);
	root->right=createNode(7);
	root->left->left=createNode(8);
	root->right->left=createNode(9);
	root->left->right=createNode(1);
	root->right->right=createNode(0);
	root->left->left->left=createNode(2);	
	cout<<"Number of leaves in the tree is: "<<findLeafCount(root);
	return 0;
}
/*
output:
Number of leaves in the tree is: 4
*/