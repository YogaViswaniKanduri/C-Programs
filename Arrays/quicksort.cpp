/* Program to do quicksort 
Quicksort uses divide and conquer strategy.
It is in-place sorting algorithm.
Best and average time complexity is O(nlogn)
Worst case complexity is O(n2)

Quick sort is fast compared to merge sort for smaller number of elements. Because mergesort calls more functions.
In quick sort,for every one iteration only one element is sorted.

Quicksort is not a stable algorithm. An algorithm is said to be a stable algorithm if elements with equal keys ( {1,"saghd"},{1,"jhjhjk"}) appear in the
same order they are before. 

*/
#include<iostream>
using namespace std;

void swap(int *x,int *y)
{
	if(*x!=*y)
	{
		*x=*x^*y;
		*y=*x^*y;
		*x=*x^*y;
	}
}

int partition(int arr[],int low,int high)
{
	int pivot=arr[high];
	int i=low-1,j=low;
	for(int j=low;j<high;j++)
	{
		if(arr[j]<=pivot)
		{
			i++;
			swap(&arr[i],&arr[j]);			
		}
	}
	i++;
	swap(&arr[i],&arr[high]);
	return i;
}


void quicksort(int arr[],int low,int high)
{
	if(low<high)
	{
		int index=partition(arr,low,high);
		quicksort(arr,low,index-1);
		quicksort(arr,index+1,high);
	}
	
}

void printArray(int arr[],int len)
{
	for(int i=0;i<len;i++)
	{
		cout<<arr[i]<<" ";
	}
}

int main()
{
	int arr[]={8,45,67,2,89,19};
	int size=sizeof(arr)/sizeof(arr[0]);
	quicksort(arr,0,size-1);
	printArray(arr,size);
	return 0;
}
/*
output:
2 8 19 45 67 89 
*/
