/* Given an array arr[] of size n where every element is in range from 0 to n-1. Rearrange the given array so that arr[i] becomes arr[arr[i]] */
#include<iostream>
using namespace std;

void rearrangeArrayElements(int arr[],int len)
{
	for(int i=0;i<len;i++)
	{
		arr[i]+=(arr[arr[i]]%len)*len;		
	}
	for(int i=0;i<len;i++)
	{
		arr[i]=arr[i]/len;
	}
}

void printArray(int arr[],int len)
{
	cout<<endl;
	for(int i=0;i<len;i++)
		cout<<arr[i]<<" ";
}

int main()
{
	int arr[]={1,0,3,2};
	int size=sizeof(arr)/sizeof(arr[0]);
	printArray(arr,size);
	rearrangeArrayElements(arr,size);
	printArray(arr,size);
	return 0;
}
/*output:
1 0 3 2 
0 1 2 3 
*/