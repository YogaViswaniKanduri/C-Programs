/* Program to find largest subarray with equal number of 0's and 1's 
  1.Replace all 0 with -1
      2. find cumulative sum from left
      3. case1: subarray starts from zero index then length of subarray = i+1 where arr[i]=0
	     case2: subarray starts from other index, remember all cumulative sum values is a diff array, 
		 length of subarray is the max value between two indices with same sum values
     4. return maxLen 
*/
#include<iostream>
#include<string.h>
using namespace std;

int findMax(int a,int b)
{
	return a>b?a:b;
}

int findMin(int a, int b)
{
	return a>b?b:a;
}

int maxSubarrayWith0sAnd1s(int arr[],int len)
{
	int cumulativeSum[len],sum=0;
	int maxLen=0,max=-1,min=-1;
	for(int i=0;i<len;i++)
	{
		if(arr[i]==0)
			arr[i]=-1;
		sum=sum+arr[i];
		cumulativeSum[i]=sum;
		max=findMax(max,cumulativeSum[i]);
		min=findMin(min,cumulativeSum[i]);
	}
	int hashtable[max-min+1];
	memset(hashtable,-1,max-min+1*sizeof(hashtable));
	for(int i=0;i<len;i++)
	{
		if(cumulativeSum==0 && maxLen<i+1)
			maxLen=i+1;
		else
		{
			if(hashtable[max-cumulativeSum[i]]==-1)
				hashtable[max-cumulativeSum[i]]=i;
			else if(maxLen<i-hashtable[max-cumulativeSum[i]])
			{
				maxLen=i-hashtable[max-cumulativeSum[i]];
			}
				
		}
	}
	return maxLen;	
}

int main()
{
	int arr[]={1,1,1,1};
	int size=sizeof(arr)/sizeof(arr[0]);
	cout<<"Length of max subarray with equal number of 0's and 1's: "<<maxSubarrayWith0sAnd1s(arr,size)<<endl;
	return 0;	
}
/*
Output:
Length of max subarray with equal number of 0's and 1's: 4
*/