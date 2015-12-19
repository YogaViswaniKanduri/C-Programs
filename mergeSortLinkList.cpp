/*mergesort of a linked list*/
#include <iostream>
using namespace std;

struct node{
  int data;
  struct node * next;
};
void insert(struct node **head,int data)
{
  struct node * temp=(struct node*)malloc(sizeof(struct node));
  temp->data=data;
  temp->next=*head;
  *head=temp;
}
void printList(struct node * head)
{
  while(head!=NULL)
  {
    printf("%d\t",head->data);
    head=head->next;
  }
}
struct node * divide(struct node * head)
{
  struct node * slow=head;
  struct node * fast=head;
  
  while(fast->next!=NULL && fast->next->next!=NULL)
  {
    fast = fast->next->next;
    slow=slow->next;
  }
  return slow;
}
struct node *merge(struct node * left, struct node * right)
{
  
  if(left==NULL)
    return right;
  if(right==NULL)
    return left;
  struct node * head=NULL;
  if(left->data<=right->data)
  {
    head=left;
    head->next=merge(left->next,right);
  }
    
  else
  {
    head=right;
    head->next=merge(left,right->next);
  }
    
  return head;
}
void mergesort(struct node ** head)
{
  struct node * root=*head;
  if(root==NULL || root->next==NULL)
    return;
  struct node * mid=divide(*head);
  struct node * left=*head;
  struct node * right=mid->next;
  mid->next=NULL;
  mergesort(&left);
  mergesort(&right);
  struct node * temp=merge(left,right);
  *head=temp;
}
int main() {
  
  struct node * head=NULL;
  insert(&head,8);
  insert(&head,5);
  insert(&head,6);
  insert(&head,20);
  insert(&head,1);
  printList(head);
  mergesort(&head);
  printf("\n");
  printList(head);
  return 0;
}
