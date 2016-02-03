/* program to insert a node into binary search tree */

#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node * left;
    struct node * right;
};

struct node* createNode(int key)
{
    struct node * newNode=(struct node *)malloc(sizeof(node));
    newNode->data=key;
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


int main() {
    struct node * root=NULL;
    root=insert(root,10);
    insert(root,8);
    insert(root,13);
    insert(root,9);
    inorder(root);
	return 0;
}
/*output:
8 9 10 13 
*/