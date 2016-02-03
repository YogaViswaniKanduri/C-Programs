/* Program to find maximum difference between two elements in an array such that larger element always appears after smaller element */
/*Time complexity = O(n) and space complexity=O(1)*/
#include<iostream>

void maxDiffBtwTwoElements(int arr[], int len)
{
	int small=arr[0],large=arr[0];
	int diff=0;
	for(int i=1;i<len;i++)
	{
		if(arr[i]<small)
		{
			small=arr[i];
		}
		if(arr[i]>large && arr[i]-small > diff)
		{
			large=arr[i];
			diff=large-small;
		}
	}
	for(int i=0;i<len;i++)
		printf("%d\t",arr[i]);
	printf("\nlarge=%d small=%d and diff=%d\n",large,large-diff,diff);
}

int main()
{
	int arr[]={7,3,90,20,10,50,2,40};
	int size=sizeof(arr)/sizeof(arr[0]);
	maxDiffBtwTwoElements(arr,size);
	int arr2[]={2, 3, 10, 6, 4, 8, 1};
	size=sizeof(arr2)/sizeof(arr2[0]);
	maxDiffBtwTwoElements(arr2,size);
	int arr3[] = {80, 2, 6, 3, 100};
	size=sizeof(arr3)/sizeof(arr3[0]);
	maxDiffBtwTwoElements(arr3,size);
	return 0;
}
/*Output:
7	3	90	20	10	50	2	40	
large=90 small=3 and diff=87
2	3	10	6	4	8	1	
large=10 small=2 and diff=8
80	2	6	3	100	
large=100 small=2 and diff=98
*/