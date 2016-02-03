/* program to implement stack using arrays */

#include<iostream>
using namespace std;

template<class T>
class Stack
{
	private:
	int top,size;
	T *a;
	public:
	Stack(int size)
	{
		this->size=size;
		a=new T[size];
		top=-1;
	}
	~Stack()
	{
		delete a;
	}
	bool isFull();
	bool isEmpty();
	void push(T x);
	T pop();
	T getTop();
};

template<class T>
bool Stack<T>::isFull()
{
	if(top==size-1)
		return true;
	return false;
}

template<class T>
bool Stack<T>::isEmpty()
{
	if(top==-1)
		return true;
	return false;
}

template<class T>
void Stack<T>::push(T data)
{
	if(isFull())
	{
		cout<<"Stack is full.";
		return;
	}
	top++;
	a[top]=data;
}

template<class T>
T Stack<T>::pop()
{
	if(!isEmpty())
	{
		cout<<"Stack is empty";
		return -1;
	}
	T data =a[top];
	top--;
	return data;
}

template<class T>
T Stack<T>::getTop()
{
	if(isEmpty())
	{
		cout<<"Stack is empty";
		return -1;
	}
	return a[top];
}

int main()
{
	Stack<int> s(20);
	int size,data,choice;
	do
	{
		cout<<"1. isFull 2.isEmpty 3.push 4.pop 5.top 6.exit"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1: 
					cout<<(s.isFull()?"Stack is full":"No stack is not full");
					break;
			case 2:
					cout<<(s.isEmpty()?"Stack is empty":"No stack is not empty");
					break;
			case 3:
					cout<<"Enter number to be entered:";
					cin>>data;
					s.push(data);
					break;
			case 4:
					data=s.pop();
					cout<<"poped element is:"<<data;
					break;
			case 5:
					cout<<"Element at the top:"<<s.getTop();
					break;					
			case 6: 
					cout<<"exiting";
					break;
			default:
					cout<<"Invalid choice";
					break;
		}
	}while(choice !=6);
}
