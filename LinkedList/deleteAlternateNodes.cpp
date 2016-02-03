/* program to delete alternate nodes of a singly linked list */
#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node * link;
};

void addNode(struct node **head,int data)
{
	struct node * newNode=(struct node *)malloc(sizeof(struct node));
	newNode->data=data;
	newNode->link=*head;
	*head=newNode;
}

void display(struct node * head)
{
	struct node * curr=head;
	while(curr!=NULL)
	{
		cout<<curr->data<<" ";
		curr=curr->link;
	}	
}

void deleteAlternateNodes(struct node * head)
{
	struct node * curr=head;
	while(curr!=NULL && curr->link!=NULL)
	{
		curr->link=curr->link->link;
		curr=curr->link;
	}	
}

int main()
{
	struct node * head=NULL;
	addNode(&head,11);
	addNode(&head,9);
	addNode(&head,19);
	addNode(&head,26);
	addNode(&head,5);
	addNode(&head,15);
	display(head);
	deleteAlternateNodes(head);
	cout<<endl;
	display(head);
	return 0;
}
/*
output:
15 5 26 19 9 11 
15 26 9 
*/