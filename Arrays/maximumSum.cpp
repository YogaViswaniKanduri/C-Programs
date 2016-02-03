/*Program to find maximum sum in an array such that no two elements are adjacent 
and all the elements of the array are positive.*/
//Time Complexity=O(n) and space complexity=O(1)
#include<iostream>

int max(int a, int b)
{
	return a>b?a:b;
}

int maxSum(int arr[],int len)
{
	int incl=arr[0];
	int excl=0;
	int temp=0;
	for(int i=1;i<len;i++)
	{
		temp=max(incl,excl);
		incl=excl+arr[i];
		excl=temp;
	}
	return max(incl,excl);
}

int main()
{
	int arr[]={5,5,10,6,4,90};
	int size=sizeof(arr)/sizeof(arr[0]);
	printf("\nMax sum of non-adjacent elements in the array is:%d",maxSum(arr,size));
	return 0;
}

/*Output:
Max sum of non-adjacent elements in the array is:105
*/