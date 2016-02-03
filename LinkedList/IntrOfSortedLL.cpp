/* program to create intersection of two sorted linked lists */

#include<iostream>
#include<stdlib.h>
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
	cout<<endl;
	struct node * curr=head;
	while(curr!=NULL)
	{
		cout<<curr->data<<" ";
		curr=curr->link;
	}	
}

struct node * createNode(int data)
{
    struct node * newNode=(struct node *)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->link=NULL;
    return newNode;
}

void intrOfSortedLL(struct node **newHead, struct node * head1, struct node * head2)
{
	if(head1 == NULL || head2 == NULL) return;
	if(head1->data == head2->data)
	{
		*newHead=createNode(head1->data);
		intrOfSortedLL(&((*newHead)->link),head1->link,head2->link);
	}
	else if(head1->data<head2->data)
	{
		intrOfSortedLL(newHead,head1->link,head2);
	}
	else
	{
		intrOfSortedLL(newHead,head1,head2->link);
	}
}

int main()
{
	struct node * head1=NULL;
	struct node * head2=NULL;
	struct node * newHead=NULL;
	addNode(&head1,11);
	addNode(&head1,9);
	addNode(&head1,9);
	addNode(&head1,3);
	addNode(&head1,1);
	
	addNode(&head2,17);
	addNode(&head2,11);
	addNode(&head2,9);
	addNode(&head2,9);
	addNode(&head2,2);
	addNode(&head2,1);
	display(head1);
	display(head2);	
	intrOfSortedLL(&newHead,head1,head2);
	display(head1);
	display(head2);	
	cout<<endl;
	display(newHead);
	return 0;
}
/* output:
1 3 9 9 11 
1 2 9 9 11 17 
1 3 9 9 11 
1 2 9 9 11 17 

1 9 9 11 
*/