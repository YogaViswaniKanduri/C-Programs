/* my own algorithm for inorder traversal without using stack and recursion*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node * left;
	struct node * right;
	struct node * parent = NULL;
	int visit=0;
};
struct node * goToLeftMost(struct node * curr)
{
	while(curr->left!=NULL)
		curr=curr->left;
	return curr;
}
void inorderTraversalWithoutStack(struct node * curr)
{
	if(curr==NULL)
		return;
	curr=goToLeftMost(curr);
	while(curr!=NULL)
	{
		if(!curr->visit)
		{
			printf("%d\t",curr->data);
			curr->visit=1;
			if(curr->right)
			{
				curr=goToLeftMost(curr->right);				
			}
			else
			{
				curr=curr->parent;
			}
		}
		else
		{
			curr=curr->parent;
		}
	}
}
struct node * newNode(int data, struct node * parent)
{
	struct node * temp=(struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->left=NULL;
	temp->right=NULL;
	temp->parent=parent;		
}
int main()
{
	struct node * root1=newNode(1,NULL);
	root1->left = newNode(2,root1);
    root1->right = newNode(3,root1);
    root1->left->left  = newNode(4,root1->left);
    root1->left->right = newNode(5,root1->left);
	inorderTraversalWithoutStack(root1);
	printf("\n");
	struct node * root2=newNode(20,NULL);
	root2->left = newNode(22,root2);
    root2->right = newNode(8,root2);
    root2->left->left  = newNode(32,root2->left);
    root2->left->right = newNode(5,root2->left);
	root2->left->left->right  = newNode(10,root2->left->left);
	root2->right->left = newNode(12,root2->right);
	root2->right->right = newNode(9,root2->right);
	root2->right->right->left = newNode(11,root2->right->right);
	root2->right->left->left = newNode(14,root2->right->left);
	root2->right->left->right = newNode(18,root2->right->left);
	inorderTraversalWithoutStack(root2);
	printf("\n");
	//left skew tree
	struct node * root3=newNode(17,NULL);
	root3->left=newNode(16,root3);
	root3->left->left=newNode(15,root3->left);
	root3->left->left->left=newNode(14,root3->left->left);
	root3->left->left->left->left=newNode(13,root3->left->left->left);
	inorderTraversalWithoutStack(root3);
	printf("\n");
	//right skew tree
	struct node * root4=newNode(17,NULL);
	root4->right=newNode(16,root4);
	root4->right->right=newNode(15,root4->right);
	root4->right->right->right=newNode(14,root4->right->right);
	root4->right->right->right->right=newNode(13,root4->right->right->right);
	inorderTraversalWithoutStack(root4);	
	printf("\n");
	//left skew tree with single right node
	struct node * root5=newNode(17,NULL);
	root5->left=newNode(16,root5);
	root5->left->left=newNode(15,root5->left);
	root5->left->left->left=newNode(14,root5->left->left);
	root5->left->left->left->right=newNode(13,root5->left->left->left);
	root5->left->left->left->left=newNode(12,root5->left->left->left);
	root5->left->left->left->left->right=newNode(11,root5->left->left->left->left);	
	inorderTraversalWithoutStack(root5);
	printf("\n");
	
	getchar();
	return 0;
}
/*
Output:
4	2	5	1	3	
32	10	22	5	20	14	12	18	8	11	9	
13	14	15	16	17	
17	16	15	14	13	
12	11	14	13	15	16	17
*/
