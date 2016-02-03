/* program to find inorder sucessor of a node in BST */

#include<iostream>
using namespace std;

struct node{
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

struct node * insert(struct node * root, int value)
{
	if(root==NULL)
		return createNode(value);
	if(root->data>value)
	{
		root->left=insert(root->left,value);
	}
	else
	{
		root->right=insert(root->right,value);
	}
	return root;
}

void inorder(struct node * root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}

struct node * minimum(struct node * root)
{
	if(root==NULL) return NULL;
	while(root->left!=NULL)
	{
		root=root->left;
	}
	return root;
}

struct node * maximum(struct node * root)
{
	if(root==NULL) return NULL;
	while(root->right!=NULL)
	{
		root=root->right;
	}
	return root;
}

struct node * findInorderSuccessorBST(struct node * root,struct node * givenNode)
{
	if(root==NULL||givenNode==NULL) return NULL;
	if(givenNode->right) return minimum(givenNode->right);
	struct node * curr=root;
	struct node * succ=NULL;
	while(curr!=NULL)
	{
		if(curr==givenNode) return succ;
		if(curr->data > givenNode->data)
		{
			succ=curr;
			curr=curr->left;
		}
		else
			curr=curr->right;
	}
	return succ;
}

struct node * findInorderPredecessorBST(struct node * root,struct node * givenNode)
{
	if(root==NULL||givenNode==NULL) return NULL;
	if(givenNode->left) return maximum(givenNode->left);
	struct node * pred=NULL;
	struct node * curr=root;
	while(curr!=NULL)
	{
		if(curr==givenNode) return pred;
		if(curr->data < givenNode->data)
		{
			pred=curr;
			curr=curr->right;
		}
		else
			curr=curr->left;
	}
	return pred;
}


int main()
{
	struct node *root = insert(root,20);
    insert(root,8);
    insert(root,22);
    insert(root,4);
    insert(root,12);
    insert(root,10);
    insert(root,14);
	inorder(root);
	cout<<"successor of 12: "<<findInorderSuccessorBST(root,root->left->right)->data;
	//cout<<"predecessor of 12: "<<findInorderPredecessorBST(root,root->left->right);
	return 0;
}