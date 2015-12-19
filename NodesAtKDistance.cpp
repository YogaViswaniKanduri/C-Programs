/*program to print nodes at a distance of K*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node * left;
	struct node * right;
};
void NodesAtKDistance(struct node * curr,int i, int k)
{
	if(curr==NULL)
		return;
	if(i==k)
	{
		printf("\n node at distance %d: %d",k,curr->data);
		return;
	}
	i++;
	NodesAtKDistance(curr->left,i,k);
	NodesAtKDistance(curr->right,i,k);
}
void NodesAtKDistanceUtil(struct node * curr, int k)
{
	int i=0;
	NodesAtKDistance(curr,i,k);
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
 
  /* Constructed binary tree is
            1
          /   \
        2      3
      /  \    /
    4     5  8 
  */
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
  root->right->left = newNode(8);   
  NodesAtKDistanceUtil(root, 2); 
  getchar();
  printf("\nprogram exited without errors");
  return 0;
}