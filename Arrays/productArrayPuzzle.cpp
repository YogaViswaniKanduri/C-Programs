/* program to find product array puzzle 
Given an array arr[] of n integers, construct a Product Array prod[] (of same size) such that prod[i] is equal to the product of all the elements of arr[] except arr[i]. 
Solve it without division operator and in O(n).
*/

#include<iostream>
void printSolution(int prod[], int len)
{
	for(int i=0;i<len;i++)
		printf("%d\t",prod[i]);
}

void findProductArray(int arr[],int len)
{
	int left[len];
	int right[len];
	int prod[len];
	
	left[0]=arr[0];
	right[len-1]=arr[len-1];
	
	for(int i=1;i<len;i++)
	{
		left[i]=left[i-1]*arr[i];
	}
	
	for(int i=len-2;i>=0;i--)
	{
		right[i]=right[i+1]*arr[i];
	}
	
	prod[0]=right[1];
	prod[len-1]=left[len-2];
	
	for(int i=1;i<len-1;i++)
	{
		prod[i]=left[i-1]*right[i+1];
	}
	printSolution(prod,len);	
}

int main()
{
	int arr[]={10,3,5,6,2};
	int size = sizeof(arr)/sizeof(arr[0]);
	findProductArray(arr,size);
	return 0;
}
/*Output
180	600	360	300	900
*/