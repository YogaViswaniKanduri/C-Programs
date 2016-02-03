/* program to split alternating nodes of a singly linked list */

#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node * link;
};

void alternateSplitOfNodes(struct node *head, struct node **a, struct node **b)
{
	if(head==NULL) return;
	*a=head;
	head=head->link;
	(*a)->link=NULL;
	alternateSplitOfNodes(head,b,&((*a)->link));
}

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

int main()
{
	struct node * head=NULL;
	struct node * a=NULL;
	struct node * b=NULL; 
	addNode(&head,11);
	addNode(&head,9);
	addNode(&head,19);
	addNode(&head,26);
	addNode(&head,5);
	addNode(&head,15);
	display(head);
	alternateSplitOfNodes(head,&a,&b);
	head=NULL;
	display(a);
	display(b);	
	display(head);
	return 0;
}
/*Output:
15 5 26 19 9 11 
15 26 9 
5 19 11 
*/