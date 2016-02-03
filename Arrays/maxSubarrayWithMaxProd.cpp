/* Program to find max subarray with max product */
#include<iostream>
using namespace std;

int max(int a,int b)
{
	return a>b?a:b;
}

int min(int a,int b)
{
	return a>b?b:a;
}

int maxSubarrayWithMaxProd(int arr[],int len)
{
	int tempMin,tempMax;
	int currMin=arr[0],currMax=arr[0],overallMax=arr[0];
	for(int i=1;i<len;i++)
	{
		tempMin=currMin;
		tempMax=currMax;
		currMax=max(max(tempMin*arr[i],tempMax*arr[i]),arr[i]);
		currMin=min(min(tempMin*arr[i],tempMax*arr[i]),arr[i]);
		overallMax=max(overallMax,currMax);		
	}
	return overallMax;
}

int main()
{
	int arr[]={6, -3, -10, 0, 2};
	int size=sizeof(arr)/sizeof(arr[0]);
	cout<<"Max contiguous product is:"<<maxSubarrayWithMaxProd(arr,size)<<endl;
	return 0;
}
/*
Output:Max contiguous product is:180
*/