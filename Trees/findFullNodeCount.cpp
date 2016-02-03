#include <iostream>
#include <queue>
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


int findFullNodeCount(struct node * root)
{
	if (root==NULL) return 0;
	int leftCount=findFullNodeCount(root->left);
	int rightCount=findFullNodeCount(root->right);
	if(root->left!=NULL && root->right!=NULL)
		return 1+leftCount+rightCount;
	return leftCount+rightCount;
	
}

int findFullNodeCountIterative(struct node * root)
{
	if (root==NULL) return 0;
	queue<struct node *>q;
	struct node * curr=root;
	q.push(root);
	int count=0;
	while(q.empty()==false)
	{
		curr=q.front();
		q.pop();
		if(curr->left!=NULL &&curr->right!=NULL)
			count++;
		if(curr->left)
			q.push(curr->left);
		if(curr->right)
			q.push(curr->right);			
	}
	return count;	
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
	cout<<"Number of full nodes in the binary tree is: "<<findFullNodeCount(root)<<endl;
	cout<<"Iterative solution, Number of full nodes in the binary tree is: "<<findFullNodeCountIterative(root);
	return 0;
}
/*
output:
Number of full nodes in the binary tree is: 3
Iterative solution, Number of full nodes in the binary tree is: 3
*/