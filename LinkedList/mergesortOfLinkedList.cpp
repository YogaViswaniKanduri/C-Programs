/*Program to do merge sort of a linked list
It is efficient to use mergesort for sorting a linked list as it doesn't require any extra space
Time complexity=O(n)
*/
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

struct node * findMid(struct node * head)
{
	struct node * fast=head;
	struct node * slow=head;
	while(fast->link!=NULL && fast->link->link!=NULL)
	{
		fast=fast->link->link;
		slow=slow->link;
	}
	return slow;
}

struct node * merge(struct node *list1, struct node *list2)
{
    if(list1==NULL)
       return list2;
    if(list2==NULL)
        return list1;
    struct node * head;
    if(list1->data<=list2->data)
    {
        head=list1;
        head->link=merge(list1->link,list2);
    }
    else
    {
        head=list2;
        head->link=merge(list1,list2->link);        
    }
    return head;
    
}

void mergesort(struct node **head)
{
	if(*head!=NULL && (*head)->link!=NULL)
	{
		struct node * mid=findMid(*head);
		struct node * leftList=*head;
		struct node * rightList=mid->link;
		mid->link=NULL;
		mergesort(&leftList);
		mergesort(&rightList);
	    *head=merge(leftList,rightList);
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
	mergesort(&head);
	cout<<endl;
	display(head);
	return 0;
}
/*Output:
15 5 26 19 9 11 
5 9 11 15 19 26 
*/
