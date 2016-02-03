/* Program to find longest span with same sum in two binary arrays 

Given two binary arrays arr1[] and arr2[] of same size n. Find length of the longest common span (i, j) 
where j >= i such that arr1[i] + arr1[i+1] + …. + arr1[j] = arr2[i] + arr2[i+1] + …. + arr2[j].

Approaches = divide and conquer

*/

#include<iostream>
using namespace std;

int max(int a, int b,int c)
{
	if(a>=b && a>=c)
		return a;
	else if(b>=a && b>=c)
		return b;
	return c;
}

int mergedSpan(int a[],int b[], int low, int mid, int high)
{
	int i=mid,j=mid+1,sum1=0,sum2=0,leftIndex=-1,rightIndex=-1,maxsum=0;
	while(i>=low||j<=high)
	{
		sum1=sum1+(i>=low?a[i]:0)+(j<=high?a[j]:0);
		sum2=sum2+(i>=low?b[i]:0)+(j<=high?b[j]:0);
		if(sum1==sum2)
		{
			if(i>=low)
				leftIndex=i;
			if(j<=high)
				rightIndex=j;
			maxsum=sum1;
		}
		i--;
		j++;
	}
	if(maxsum)
	    return rightIndex-leftIndex+1;
	return 0;
}

int findLongestSpan(int a[],int b[],int low,int high)
{
	if(low==high)
	{
		if(a[low]==b[low])
			return 1;
		else 
			return 0;
	}
	if(low<high)
	{
		int mid,leftSpan=0,rightSpan=0,combinedSpan=0;
		mid=(low+high)/2;
		leftSpan=findLongestSpan(a,b,low,mid);
		rightSpan=findLongestSpan(a,b,mid+1,high);
		combinedSpan=mergedSpan(a,b,low,mid,high);
		//cout<<endl<<"low is"<<low<<endl<<"high is"<<high<<endl;
		//cout<<"leftSpan is"<<leftSpan<<"right is"<<rightSpan<<"combinedSpan is"<<combinedSpan<<endl;
		return max(leftSpan,rightSpan,combinedSpan);
	}
}

int main()
{
	int a[]={0, 1, 0, 0, 0, 0};
	int b[]={1, 0, 1, 0, 0, 1};
	int size=sizeof(a)/sizeof(a[0]);
	cout<<"longest span is:"<<findLongestSpan(a,b,0,size-1)<<endl;
	return 0;	
}
/* 
Output:
longest span is:4
*/