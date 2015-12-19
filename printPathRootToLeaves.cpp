/*program to print all of its root-to-leaf paths for a tree*/
#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;	
	struct node * left;
	struct node * right;
};

void printPathRootToLeavesUtil(struct node * curr, int a[],int len)
{
    a[len]=curr->data;
	len++;
	
	if (curr->left == NULL && curr->right == NULL)
	{
	    printf("\npath is: ");
		for(int i=0;i<len;i++)
		{
			printf("%d\t",a[i]);
			
		}
		return;
	}
	if(curr->left!=NULL)
	{
	    printPathRootToLeavesUtil(curr->left,a,len);
	}
	if(curr->right!=NULL)
	{
	    
		printPathRootToLeavesUtil(curr->right,a,len);
	}
		
}
void printPathRootToLeaves(struct node * curr)
{
	if (curr==NULL)
		return;
	int a[10];
	int startIndex = 0;
	printPathRootToLeavesUtil(curr,a,startIndex);
}
struct node* newNode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
 
  return(node);
}
 
/* Driver program to test mirror() */
int main()
{
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5); 
  root->right->left = newNode(6); 
  printPathRootToLeaves(root);
 
  getchar();
  return 0;
}
/*output: 
path is: 1	2	4	
path is: 1	2	5	
path is: 1	3	6
*/