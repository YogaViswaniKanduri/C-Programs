/* program to find a sorted subsequence of size 3 in linear time */

#include <iostream>
#include <string.h> 
using namespace std;

void findSortedSubsequence(int arr[],int len)
{
	int smaller[len];
	int bigger[len];
	int minIndex=0,	maxIndex=len-1;
	memset(smaller,-1,sizeof(smaller));
	memset(bigger,-1,sizeof(bigger));
	for(int i=1;i<len;i++)
	{
		if(arr[i]<=arr[minIndex])
		{
			minIndex=i;
		}
		else
			smaller[i]=minIndex;
	}
	for(int i=len-2;i>=0;i--)
	{
		if(arr[i]>=arr[maxIndex])
		{	
			maxIndex=i;
		}
		else
		{
			bigger[i]=maxIndex;
		}
	}
	for(int i=0;i<len;i++)
	{
		if(smaller[i]!=-1 && bigger[i]!=-1)
		{
			cout<<arr[smaller[i]]<<" "<<arr[i]<<" "<<arr[bigger[i]]<<endl;
		    return;
		}
	}
	cout<<"No such subsequence found.";
}

int main()
{
	int arr[]={12,11,10,5,6,2,30};
	int size=sizeof(arr)/sizeof(arr[0]);
	findSortedSubsequence(arr,size);
	return 0;
}
/*
output:
5 6 30
*/