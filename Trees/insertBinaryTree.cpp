#include<iostream>
#include<stdlib.h>
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

void insert(struct node **root,int data)
{
	if(*root==NULL)
	{
		*root=createNode(data);
		return;	
	}
	struct node * curr=root;
	queue<struct node *>q;
	q.push(curr);
	while(q.empty()==false)
	{
		curr=q.front();
		q.pop();
		if(curr->left)
		{
			q.push(curr);
		}
		else
		{
			curr->left=createNode(data);
			return;
		}
		if(curr->right)
		{
			q.push(curr>right);
		}
		else
		{
			curr->right=createNode(data);
			return;
		}
	
	}
}

void levelOrderTraversalIteration(struct node * root)
{
	if(root==NULL) return;
	queue<struct node*> l;
	struct node *curr=root;
	struct node *nullNode=NULL;
	l.push(curr);
	l.push(nullNode);
	while(l.empty()==false)
	{
		curr=l.front();
		l.pop();
		if(curr!=NULL)
		{
			cout<<curr->data<<" ";
			if(curr->left) l.push(curr->left);
			if(curr->right) l.push(curr->right);
		}
		else if(l.empty()==false)
		{
			cout<<endl;
			l.push(nullNode);
		}
	}
}

void preorder(struct node * root)
{
	if(root!=NULL)
	{
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}

int main()
{
	struct node * root=NULL;
	insert(&root,5);
	insert(&root,4);
	insert(&root,0);
	insert(&root,8);
	insert(&root,6);
	preorder(root);
	levelOrderTraversalIteration(root);
	return 0;
}