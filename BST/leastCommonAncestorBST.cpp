/* program to find least common ancestor of two nodes in a binary search tree
T=O(h) h=height of tree
*/
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

bool searchBST(struct node * root, int key)
{
	if(root==NULL) return 0;
	if(root->data==key)  return 1;
	if(root->data<key) return searchBST(root->right,key);
	if(root->data>key) return searchBST(root->left,key);
}

struct node * leastCommonAncestorUtil(struct node* root, int node1Value,int node2Value)
{
	
	if(root!=NULL)
	{
		int rootValue=root->data;
		if(node1Value<rootValue && node2Value<rootValue) return leastCommonAncestorUtil(root->left,node1Value,node2Value);
		if(node1Value>rootValue && node2Value>rootValue) return leastCommonAncestorUtil(root->right,node1Value,node2Value);
	}
	return root;		
}


int leastCommonAncestor(struct node * root,int node1Value,int node2Value)
{
	if(searchBST(root,node1Value) && searchBST(root,node2Value))
	return leastCommonAncestorUtil(root,node1Value,node2Value)->data;
	return -1;	
}

int main()
{
	struct node *root        = createNode(20);
    root->left               = createNode(8);
    root->right              = createNode(22);
    root->left->left         = createNode(4);
    root->left->right        = createNode(12);
    root->left->right->left  = createNode(10);
    root->left->right->right = createNode(14);
 
    int n1 = 10, n2 = 14;
    int t = leastCommonAncestor(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t);
 
    n1 = 14, n2 = 8;
    t = leastCommonAncestor(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t);
 
    n1 = 10, n2 = 32;
    t = leastCommonAncestor(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t);
 
    getchar();
    return 0;
}
/*
output:
LCA of 10 and 14 is 12 
LCA of 14 and 8 is 8 
LCA of 10 and 32 is -1
*/