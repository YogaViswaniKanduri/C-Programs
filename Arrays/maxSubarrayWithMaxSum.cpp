/* Program to find Maximum subarray sum */

#include<iostream>
using namespace std;

int max(int a, int b)
{
	return a>b?a:b;
}

int maxSubarrayWithMaxSum(int arr[],int len)
{
	int currMax=0, overallMax=arr[0];
	for(int i=0;i<len;i++)
	{
		currMax=max(currMax+arr[i],arr[i]);
		overallMax=max(currMax,overallMax);		
	}
	return overallMax;
}

int main()
{
	int arr[]={-2, -3, 4, -1, -2, 1, 5, -3};
	int size=sizeof(arr)/sizeof(arr[0]);
	cout<<"Max contiguous sum is: "<<maxSubarrayWithMaxSum(arr,size)<<endl;
	return 0;	
}
/*Output:
Max contiguous sum is: 7
*/