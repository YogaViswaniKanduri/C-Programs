/* Program to find the max repeating element.
Given an array of size n, the array contains numbers in range from 0 to k-1 
where k is a positive integer and k < = n. Find the maximum repeating number in this array.
*/
#include<iostream>
#include<climits>
using namespace std;

int findMaxRepeatingElement(int arr[],int len,int k)
{
	for(int i=0;i<len;i++)
	{
		arr[arr[i]%k]+=k;
	}
	int max=INT_MIN,ele=-1;
	for(int i=0;i<len;i++)
	{
		if(max<arr[i])
		{
			max=arr[i];
			ele=i;
		}
	}
	return ele;
}

int main()
{
	int arr[]={1,0,0,0,0,2,0,2,3,8,0,9,2,3};
	int size=sizeof(arr)/sizeof(arr[0]);
	int k=10;
	cout<<"Max repeating element: "<<findMaxRepeatingElement(arr,size,k);
	return 0;
}
/*Output:
Max repeating element: 0
*/