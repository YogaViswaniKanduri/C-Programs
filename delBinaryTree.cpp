/*program to delete a binary tree*/
/*pending....*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node * left;
	struct node * right;
};
void delTreeFun(struct node ** root_ref)
{
	delTree(*root_ref);
	*root_ref=NULL;	
	/*
	when root is not changed to null, user can still access the memory locations previously allocated(not the tree).Hence it should be changed to null.
	*/
}
void delTree(struct node * root)
{
	if(root!=NULL)
	{
		delTree(root->left);
		delTree(root->right);
		printf("\n deleting node: %d",root->data);
		free(root);
		/*
		Generally, memory allocated by malloc is deallocated by calling free(). Free is c library function void free(void *)
		Memory allocated by new operator is deallocated by calling delete. delete (void *) in c++
		diff btw free and delete is free frees memory, delete calls the destructor of pointer and then fress the memory;
		
		*/
	}	
}
void displayTreePostorder(struct node * root)
{
	if (root!=NULL)
	{
		
		displayTreePostorder(root->left);
		displayTreePostorder(root->right);
		printf("\n%d\t and its address: %p",root->data,root);
	}
		
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
	struct node * root=newNode(20);
	root->left=newNode(8);
	root->right=newNode(22);
	root->left->left=newNode(4);
	root->left->right=newNode(12);
	root->left->right->left=newNode(10);
	root->left->right->right=newNode(14);
	root->right->right=newNode(32);
	printf("\ndisplaying inorder traversal of a tree:");
	displayTreePostorder(root);
	delTreeFun(root);
	printf("\nroot address: %p",root);
	printf("\nroot->data: %d",root->data);
	displayTreePostorder(root);
}
/*
OUTPUT WHEN ROOT IS NOT CHANGED TO NULL
displaying inorder traversal of a tree:
4	 and its address: 0x144b070
10	 and its address: 0x144b0b0
14	 and its address: 0x144b0d0
12	 and its address: 0x144b090
8	 and its address: 0x144b030
32	 and its address: 0x144b0f0
22	 and its address: 0x144b050
20	 and its address: 0x144b010
 deleting node: 4
 deleting node: 10
 deleting node: 14
 deleting node: 12
 deleting node: 8
 deleting node: 32
 deleting node: 22
 deleting node: 20
root address: 0x144b010
root->data: 21278784
0	 and its address: 0x144b070
21278816	 and its address: 0x144b0b0
21278880	 and its address: 0x144b0d0
21278912	 and its address: 0x144b090
21278848	 and its address: 0x144b030
21278752	 and its address: 0x144b0f0
21278944	 and its address: 0x144b050
21278784	 and its address: 0x144b010
*/
