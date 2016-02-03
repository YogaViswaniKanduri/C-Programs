/* program to find the maximum element in a binary tree */
#include <iostream>
#include <climits>
#include <queue>
using namespace std;

struct node
{
	int data;
	struct node * left;
	struct node * right;
};

int findMax(int a,int b,int c)
{
	if(a>b&&a>c) return a;
	else if(b>a&&b>c) return b;
	else return c;
}

struct node * createNode(int data)
{
	struct node * newNode=(struct node *)malloc(sizeof(struct node));
	newNode->data=data;
	newNode->left=NULL;
	newNode->right=NULL;
	return newNode;
}

int findMaxElementWithRecursion(struct node * root)
{
	int leftMax,rightMax,max;
	leftMax=rightMax=max=INT_MIN;
	if(root!=NULL)
	{
		leftMax=findMaxElementWithRecursion(root->left);
		rightMax=findMaxElementWithRecursion(root->right);
		max=findMax(leftMax,rightMax,root->data);
	}
	return max;	
}

void findMaxElementWithRecursion2(struct node * root, int *max)
{
	if(root!=NULL)
	{
		if(*max<root->data)
			*max=root->data;
		findMaxElementWithRecursion2(root->left,max);
		findMaxElementWithRecursion2(root->right,max);
	}
}

int findMaxElementWithoutRecursion(struct node * root)
{
	if(root==NULL) return INT_MIN;
	struct node * curr=root;
	int max=INT_MIN;
	queue<struct node *>q;
	q.push(curr);
	while(q.empty()==false)
	{
		curr=q.front();
		q.pop();
		if(max<curr->data)
			max=curr->data;
		if(curr->left) q.push(curr->left);
		if(curr->right) q.push(curr->right);
	}
	return max;	
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
	int max=INT_MIN;
	cout<<"Max Element in the tree using recursion is: "<<findMaxElementWithRecursion(root)<<endl;
	cout<<"Find max element using another approach: ";
	findMaxElementWithRecursion2(root,&max);
	cout<<max<<endl;
	cout<<"Max element in the tree without using recursion is: "<<findMaxElementWithoutRecursion(root)<<endl;
	return 0;
}
/*Output:
Max Element in the tree using recursion is: 9
Find max element using another approach: 9
Max element in the tree without using recursion is: 9
*/
