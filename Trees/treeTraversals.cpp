/* program to print inorder, post order and preorder traversals in iterative fashion */

#include <iostream>
#include <stdlib.h>
#include <stack>
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

void preorderRecursion(struct node * root)
{
	if(root!=NULL)
	{
		cout<<root->data<<" ";
		preorderRecursion(root->left);
		preorderRecursion(root->right);
	}
}

void preorderWithoutRecursion(struct node * root)
{
	if(root==NULL) return;
	stack<struct node*> s;	
	struct node * curr=root;
	
	while(curr!=NULL || !s.empty())
	{
		if(curr!=NULL)
		{
			cout<<curr->data<<" ";
			s.push(curr);
			curr=curr->left;			
		}
		else if(!s.empty())
		{
			curr=s.top();
			s.pop();
			curr=curr->right;
		}
	}	
}

void inorderRecursion(struct node * root)
{
	if(root!=NULL)
	{
		inorderRecursion(root->left);
		cout<<root->data<<" ";
		inorderRecursion(root->right);
	}
}

void inorderWithoutRecursionUsingStack(struct node * root)
{
	if(root==NULL) return;
	stack<struct node *> in;
	struct node * curr=root;
	while(curr!=NULL||in.empty()==false)
	{
		if(curr!=NULL)
		{
			in.push(curr);
			curr=curr->left;
		}
		else if(in.empty()==false)
		{
			curr=in.top();
			in.pop();
			cout<<curr->data<<" ";
			curr=curr->right;
		}
	}
	
}

void inorderMorrisTraversal(struct node * root)
{
	if(root==NULL) return;	
	struct node * curr=root;
	struct node * pre=NULL;
	while(curr!=NULL)
	{
		if(curr->left!=NULL)
		{
			pre=curr->left;
			while(pre->right!=NULL && pre->right!=curr)
			{
				pre=pre->right;
			}
			if(pre->right==NULL)
			{
				pre->right=curr;
				curr=curr->left;
			}
			else
			{
				pre->right=NULL;
				cout<<curr->data<<" ";
				curr=curr->right;
			}
				
		}
		else
		{
			cout<<curr->data<<" ";
			curr=curr->right;
		}
	}
}


void postorderRecursion(struct node * root)
{
	if(root!=NULL)
	{
		postorderRecursion(root->left);		
		postorderRecursion(root->right);
		cout<<root->data<<" ";
	}
}

void postorderWithoutRecursion(struct node * root)
{
	if(root==NULL) return;
	stack<struct node *>post;
	struct node * curr=root;
		
	while(curr!=NULL||post.empty()==false)
	{
		if(curr!=NULL)
		{
			post.push(curr);
			curr=curr->left;
		}
		
		else if(post.empty()==false)
		{
			curr=post.top();			
			if(curr->right)
			{
				curr=curr->right;
			}
			else
			{				
				post.pop();
				cout<<curr->data<<" ";
				if(post.empty()==false && (post.top())->right==curr)
				{
					curr=post.top();
					post.pop();
					cout<<curr->data<<" ";
					curr=NULL;
				}
				else
				{
					//cout<<curr->data<<" ";
					curr=NULL;
				}
			}
		}
	}
}

void levelOrderTraversalIteration(struct node * root)
{
	if(root==NULL) return;
	queue<struct node*> q;
	struct node *curr=root;
	struct node *nullNode=NULL;
	q.push(curr);
	q.push(nullNode);
	while(q.empty()==false)
	{
		curr=q.front();
		q.pop();
		if(curr!=NULL)
		{
			cout<<curr->data<<" ";
			if(curr->left) q.push(curr->left);
			if(curr->right) q.push(curr->right);
		}
		else if(q.empty()==false)
		{
			cout<<endl;
			q.push(nullNode);
		}
	}
}

int max(int a,int b)
{
	return a>b?a:b;
}

int findHeight(struct node * root)
{
	if(root==NULL) return -1;
	return 1+max(findHeight(root->left),findHeight(root->right));	
}

void printNodesAtKDistance(struct node * root, int k)
{
	if(root==NULL) return;
	if(k==0) 
	{
		cout<<root->data<<" ";
		return;
	}
	printNodesAtKDistance(root->left,k-1);
	printNodesAtKDistance(root->right,k-1);	
}

//Time complexity=O(n^2) in worst case. consider left skew trees.
void levelOrderTraversalUsingRecursion(struct node * root)
{
	if(root==NULL) return;
	int height=findHeight(root);
	for(int i=0;i<=height;i++)
	{
		printNodesAtKDistance(root,i);
		cout<<endl;
	}	
}

int main()
{
	struct node * root= createNode(5);
    root->left        = createNode(2);
    root->right       = createNode(3);
    root->left->left  = createNode(4);
    root->left->right = createNode(5);
	cout<<"preorder recusrion"<<endl;
	preorderRecursion(root);
	cout<<endl<<"without recursion"<<endl;
	preorderWithoutRecursion(root);
	cout<<endl<<"inorder recursion"<<endl;
	inorderRecursion(root);
	cout<<endl<<"inorder iterative using stack"<<endl;
	inorderWithoutRecursionUsingStack(root);
	cout<<endl<<"Morris Traversal"<<endl;
	inorderMorrisTraversal(root);
	cout<<endl<<"postorder recursion"<<endl;
	postorderRecursion(root);
	cout<<endl<<"postorder Without Recursion"<<endl;
	postorderWithoutRecursion(root);
	cout<<endl<<"Iterative level order traversal"<<endl;
	levelOrderTraversalIteration(root);
	cout<<endl<<"Level order traversal using recursion"<<endl;
	levelOrderTraversalUsingRecursion(root);
	return 0;
}
/*output:
preorder recusrion
5 2 4 5 3 
without recursion
5 2 4 5 3 
inorder recursion
4 2 5 5 3 
inorder iterative using stack
4 2 5 5 3 
Morris Traversal
4 2 5 5 3 
postorder recursion
4 5 2 3 5 
postorder Without Recursion
4 5 2 3 5 
Iterative level order traversal
5 
2 3 
4 5 
Level order traversal using recursion
5 
2 3 
4 5 
*/
