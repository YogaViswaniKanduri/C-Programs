/* program to print the largest sum contiguous subarray*/
#include<stdio.h>
#include<stdlib.h>
int maximumSumIterative(int a[],int len)
{
	int maxsum=a[0];
	int sum=0,start=0,end=0,temp_start=0;
	for(int i=0;i<len;i++)
	{
		sum = sum+a[i];
		if(sum>maxsum)
		{
			maxsum=sum;
			end=i;
			start=temp_start;
		}
		if(sum<0 && i+1<len)
		{
			sum=0;
			temp_start=i+1;
		}
	}
	return maxsum;
}
int maximumCrossArray(int a[],int low, int mid, int high)
{
	int left_sum=a[mid], right_sum=a[mid+1], sum=0;
	for(int i=mid;i>=0;i--)
	{
		sum=sum+a[i];
		if(sum>left_sum)
		{
			left_sum=sum;
		}
	}
	sum=0;
	for (int j=mid+1;j<=high;j++)
	{
		sum=sum+a[j];
		if(sum>right_sum)
		{
			right_sum=sum;
		}
	}
	return left_sum+right_sum;
}
int maximumSumRecursive(int a[],int low, int high)
{
	if(low==high)
	{
		return a[low];
	}	
	if(low<high)
	{
		int mid = (low+high)/2;
		int left_sum=0,right_sum=0,cross_sum=0;
		left_sum=maximumSumRecursive(a,low,mid);
		right_sum=maximumSumRecursive(a,mid+1,high);
		cross_sum=maximumCrossArray(a,low,mid,high);
		if(left_sum>right_sum && left_sum>cross_sum)
			return left_sum;
		else if(right_sum>left_sum && right_sum>cross_sum)
			return right_sum;
		else
			return cross_sum;
	}
}
int main()
{
	int a[]={-4,-12,-8,-5,-3,-1};
	int len=sizeof(a)/sizeof(a[0]);
	printf("\nMaximum sum returned by iterative function:%d",maximumSumIterative(a,len));
	printf("\nMaximum sum returned by recursive function:%d",maximumSumRecursive(a,0,5));
	int b[]={4,12,8,5,3,1};
	int len2=sizeof(b)/sizeof(b[0]);
	printf("\nMaximum sum returned by iterative function:%d",maximumSumIterative(b,len2));
	printf("\nMaximum sum returned by recursive function:%d",maximumSumRecursive(b,0,5));
	return 0;
}