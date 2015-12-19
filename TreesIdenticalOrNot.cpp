/*Write C code to determine if two trees are identical*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node * left;
	struct node * right;
};
int AreTreesIdentical(struct node * curr1, struct node * curr2)
{
	if(curr1==NULL&&curr2==NULL)
		return 1;
	else if(curr1!=NULL&&curr2!=NULL)
	{
		return ((curr1->data==curr2->data)&&AreTreesIdentical(curr1->left,curr2->left)&&AreTreesIdentical(curr1->right,curr2->right));
	}
	return 0;
}
struct node * newNode(int data)
{
	struct node * temp=(struct node *)malloc(sizeof(struct node));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
int main()
{
	struct node *root1 = newNode(1);
    struct node *root2 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left  = newNode(4);
    root1->left->right = newNode(5); 
 
    root2->left = newNode(2);
    root2->right = newNode(3);
    root2->left->left = newNode(4);
    root2->left->right = newNode(5); 
 
    if(AreTreesIdentical(root1, root2))
        printf("Both trees are identical.");
    else
        printf("Trees are not identical."); 
  return 0;	
}
/*
Output:
Both trees are identical.
*/