/* Program to reverse a doubly linked list */
#include <stdio.h>
#include <stdlib.h>

/* a node of the doubly linked list */
struct node
{
int data;
struct node *next;
struct node *prev; 
};

void swap(struct node **prev, struct node **next)
{
	struct node * temp=*prev;
	*prev=*next;
	*next=temp;
}

/* Function to reverse a Doubly Linked List */
void reverse(struct node ** head)
{
	if(*head==NULL) return;
	struct node * curr=*head;
	struct node * prev=*head;
	struct node * next;
	while(curr!=NULL)
	{
		next=curr->next;
		swap(&(curr->prev),&(curr->next));
		prev=curr;
		curr=next;		
	}
	*head=prev;
}



/* UTILITY FUNCTIONS */
/* Function to insert a node at the beginging of the Doubly Linked List */
void push(struct node** head_ref, int new_data)
{
	/* allocate node */
	struct node* new_node =
			(struct node*) malloc(sizeof(struct node));

	/* put in the data */
	new_node->data = new_data;
	
	/* since we are adding at the begining, 
	prev is always NULL */
	new_node->prev = NULL;

	/* link the old list off the new node */
	new_node->next = (*head_ref); 

	/* change prev of head node to new node */
	if((*head_ref) != NULL)
	(*head_ref)->prev = new_node ; 

	/* move the head to point to the new node */
	(*head_ref) = new_node;
}

/* Function to print nodes in a given doubly linked list 
This function is same as printList() of singly linked lsit */
void printList(struct node *node)
{
while(node!=NULL)
{
printf("%d ", node->data);
node = node->next;
}
} 

/* Drier program to test above functions*/
int main()
{
/* Start with the empty list */
struct node* head = NULL;

/* Let us create a sorted linked list to test the functions
Created linked list will be 10->8->4->2 */
push(&head, 2);
push(&head, 4);
push(&head, 8);
push(&head, 10);

printf("\n Original Linked list ");
printList(head);

/* Reverse doubly linked list */
reverse(&head);

printf("\n Reversed Linked list ");
printList(head);		 

getchar();
}
/* output:
 Original Linked list 10 8 4 2 
 Reversed Linked list 2 4 8 10 
 */