/* Program to implement BST */

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

int main()
{
	int choice;
	do{
		
		cout<<"1.Insert 2.Delete 3.Search 4.Inorder traversal 5.Preorder traversal 6.Postorder traversal 7.Height 8.Depth 8.Exit"<<endl;
		cin>>choice;
		struct node * root=NULL;
		switch(choice)
		{
			case 1:
				int x;
			    cout<<"Enter an element to be inserted: "<<endl;
				cin>>x;
				root=insert(root,x);
				break;
			case 3:
				int k;
				cout<<"Enter key to be searched: "<endl;
				cin>>k;
				cout<<"Is element present:"<<search(root,k);
				break;
			case 4:
				
		}
		
	}while(choice!=9);
	
}