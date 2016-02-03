/* program to implement queues using arrays */

#include<iostream>
using namespace std;

template<class T>
class Queue
{
	private:
	int front,rear,size;
	T * arr;
	public:
	Queue(int size)
	{
		this->size=size;
		front=rear=-1;
		arr=new T[size];
	}
	~Queue()
	{
		delete arr;
	}
	int isEmpty();
	int isFull();
	void enqueue(T data);
	T dequeue();
	void display();
	T getFront();
};

template<class T>
int Queue<T>:: isEmpty()
{
	if(front==-1 && rear==-1)
		return 1;
	return 0;
}

template<class T>
int Queue<T>::isFull()
{
	if(rear==size-1)
		return 1;
	return 0;	
}

template<class T>
void Queue<T>::enqueue(T data)
{
	if(isFull())
		cout<<"Queue is full"<<endl;
	else{
		if(isEmpty())
		{			
			front++;
		}
		rear++;
		arr[rear]=data;		
	}
}

template<class T>
T Queue<T>::dequeue()
{
	if(isEmpty())
	{
		cout<<"Queue is empty cannot dequeue."<<endl;
		return -1;
	}
	else
	{
		T data=arr[front];
		if(front==rear)
			front=rear=-1;
		else
			front++;
		return data;
	}
}

template<class T>
void Queue<T>::display()
{
	if(isEmpty())
		cout<<"Queue is empty"<<endl;
	else
	{
		for(int i=front;i<=rear;i++)
			cout<<arr[i]<<" ";
	}		
}

template<class T>
T Queue<T>::getFront()
{
	if(isEmpty())
	{
		cout<<"Queue is empty."<<endl;
		return -1;
	}
		return arr[front];	
}

int main()
{
	Queue<int> q(4);
	int choice;
	do
	{
		cout<<"Enter choice:1.enqueue 2.dequeue 3.display 4.front 5.isEmpty 6.isFull 7.exit"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1: 
					int x;
					cout<<"Enter number:";
					cin>>x;
					q.enqueue(x);
					break;
			case 2:
					cout<<"Element deleted is: "<<q.dequeue();
					break;
			case 3:
					cout<<"Queue elements are:";
					q.display();
					break;
			case 4:
					cout<<"Front element is:"<<q.getFront();
					break;
			case 5:
					cout<<"Is queue empty: "<<q.isEmpty();
					break;
			case 6:
					cout<<"Is queue full: "<<q.isFull();
					break;
			case 7:
			        cout<<"Exiting";
			        break;
					
			default:
					cout<<"Invalid choice:";
					break;
		}
	}while(choice!=7);
}