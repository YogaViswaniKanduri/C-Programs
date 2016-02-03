/* program to find ceil and floor of a number */

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
    struct node * newNode=(struct node *)malloc(sizeof(struct node));
    newNode->data=key;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
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

struct node * insert(struct node * root,int key)
{
	if(root==NULL) return createNode(key);
	if(root->data>key)
		root->left=insert(root->left,key);
	else
		root->right=insert(root->right,key);
	return root;		
}

void floorCeilOfNum(struct node * root,int num)
{
	int ceil=-1,floor=-1;
	struct node * curr=root;
	while(curr!=NULL)
	{
		if(curr->data==num)
		{
			floor=num;
			ceil=num;
			break;
		}
		else if(curr->data>num)
		{
			ceil=curr->data;
			curr=curr->left;
		}
		else
		{
			floor=curr->data;
			curr=curr->right;
		}
	}
	cout<<"Floor: "<<floor<<" num: "<<num<<" ceil: "<<ceil<<endl;
}


int main()
{
	struct node * root=insert(root,8);
	insert(root,4);
	insert(root,12);
	insert(root,2);
	insert(root,6);
	insert(root,10);
	insert(root,14);	
	inorder(root);	
	cout<<endl;
	
	
	for(int i=0;i<=16;i++)
	{
		floorCeilOfNum(root,i);
	}
	
	
	struct node * root2=insert(root2,20);
	insert(root2,12);
	insert(root2,23);
	insert(root2,11);
	insert(root2,15);
	insert(root2,6);
	insert(root2,21);
	insert(root2,25);
	insert(root2,22);
	insert(root2,26);
	inorder(root2);	
	cout<<endl;
	
	for(int i=0;i<28;i++)
	{
		floorCeilOfNum(root2,i);
	}
	
	return 0;	
}
/*output:

*/