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

struct node * pairwiseSwap(struct node * head)
{
	if(head==NULL || head->link ==NULL) return head;
	struct node * curr=head;
	struct node * next=curr->link;
	curr->link=next->link;
	next->link=curr;
	curr->link=pairwiseSwap(curr->link);
	return next;
}



int main()
{
	struct node * head1=NULL;
	struct node * head2=NULL;	
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
	
	head1=pairwiseSwap(head1);
	head2=pairwiseSwap(head2);
	display(head1);
	display(head2);	
	cout<<endl;
	
	return 0;
}

/*output:
1 3 9 9 11 
1 2 9 9 11 17 
3 1 9 9 11 
2 1 9 9 17 11 */
