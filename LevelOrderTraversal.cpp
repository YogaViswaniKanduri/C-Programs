/*program to print Level order traversal of a tree*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;	
	struct node * left;
	struct node * right;
};
template<class T>
class Queue
{
	private:
	T * a;
	int front, rear, maxsize;
	public:
	Queue(int size)
	{
		a=new T[size];
		maxsize=size;
		front=rear=-1;
	}
	~Queue()
	{
		delete a;
	}
	int isEmpty()
	{
		if((front==-1&&rear==-1)||(front>rear))
			return 1;
		return 0;
	}
	int isFull()
	{
		if(rear==(maxsize-1))
		{
			return 1;
		}
		return 0;
	}
	void enqueue(T node)
	{
		if(!isFull())
		{
		    if(isEmpty())
		    {
		        front=0;
		    }
			a[++rear]=node;
			
		}
	}
	T dequeue()
	{
		if(!isEmpty())
		{
			T top=a[front];
			front++;
			
			return top;
		}
		return NULL;
	}
};
void printLevelOrderTraversal(struct node * root)
{
    
	if (root==NULL)
	{
		return;
	}
	Queue<struct node *> q(15);
	q.enqueue(root);
	struct node * temp=NULL;
	q.enqueue(temp);
	
	while(!q.isEmpty())
	{
	    
		struct node * curr = q.dequeue();
		
		if(curr==NULL)
		{
			if(!q.isEmpty())
			{
				q.enqueue(temp);
				printf("\n");
			}
			else
			{
				return;
			}
			
		}
		else
		{
			printf("%d\t",curr->data);
			if(curr->left!=NULL)
			{
				q.enqueue(curr->left);
			}
			if(curr->right!=NULL)
			{
				q.enqueue(curr->right);
			}
		}
		
	}
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
int main()
{
 struct node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7);
    root->right->right->left = newNode(8);
    printLevelOrderTraversal(root);
    return 0;
	
}
/*output:
1	
2	3	
4	5	6	7	
8	
*/