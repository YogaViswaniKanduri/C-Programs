/* Program to find maximum circular subarray with max sum */

#include<iostream>
using namespace std;

int max(int a,int b)
{
    return a>b?a:b;
}

int findMaxContinuousSum(int arr[],int len)
{
	int currMax=0,overallMax=arr[0];
	for(int i=0;i<len;i++)
	{
		currMax=max(currMax+arr[i],arr[i]);
		overallMax=max(overallMax,currMax);
	}
	return overallMax;
}

int maxCircularSubarrayWithMaxSum(int arr[],int len)
{
	int overallSum=0,positiveSum=0,negativeSum=0;
	positiveSum=findMaxContinuousSum(arr,len);	
	
	for(int i=0;i<len;i++)
	{
		overallSum=overallSum+arr[i];
		arr[i]=-arr[i];
	}
	negativeSum=findMaxContinuousSum(arr,len);
	return max(positiveSum,overallSum+negativeSum);
}

int main()
{
	int arr[]= {-2, 4, -1, 4, -1};
	int size =sizeof(arr)/sizeof(arr[0]);
	cout<<"Maximum circular subarray with max sum is: "<<maxCircularSubarrayWithMaxSum(arr,size)<<endl;
	return 0;
}
/*Output:
Maximum circular subarray with max sum is: 7
*/