/*	Program to find the number of zeros ?
	Given an array of 1s and 0s which has all 1s first followed by all 0s. Find the number of 0s. Count the number of zeroes in the given array.
*/
#include<iostream>
using namespace std;

int findNumberOfZeros(int a[],int len)
{
	int low=0,high=len-1,mid;
	
	while(low<=high)
	{
		mid=(low+high)/2;
		if(a[mid]==0 && (mid==0||a[mid-1]==1))
			return (len-mid);
		else if(a[mid]==1)
			low=mid+1;
		else
			high=mid-1;
	}
	return 0;
}

int main()
{
	int arr[]={1,1,1,1,1};
	int size=sizeof(arr)/sizeof(arr[0]);
	cout<<"The number of zeros in the array are:"<<findNumberOfZeros(arr,size);
	return 0;
}
/*Output:
The number of zeros in the array are:0
*/