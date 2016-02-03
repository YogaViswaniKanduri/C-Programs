/* Program to find maximum subarray with minimum sum */
#include<iostream>
using namespace std;

int min(int a,int b)
{
	return a>b?b:a;
}

int findMaxSubarrayWithMinSum(int arr[],int len)
{
	int currMin=0,overallMin=arr[0];
	for(int i=0;i<len;i++)
	{
		currMin=min(currMin+arr[i],arr[i]);
		overallMin=min(currMin,overallMin);
	}
	return overallMin;
}
int main()
{
	int arr[]=;
	int size=sizeof(arr)/sizeof(arr[0]);
	cout<<"Minimum sum is: "<<findMaxSubarrayWithMinSum(arr,size)<<endl;
	return 0;
}