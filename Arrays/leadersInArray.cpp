/*Program to find leaders in an array
An element is leader if it is greater than all the elements to its right side. And the rightmost element is always a leader.

Time complexity=O(n) and space complexity=O(1)*/

#include<iostream>
#include<limits.h>

void printLeadersInArray(int arr[],int len)
{
	int max_so_far=INT_MIN;
	for(int i=len-1;i>=0;i--)
	{
		if(arr[i]>=max_so_far)
		{
			max_so_far=arr[i];
			printf("%d\t",max_so_far);
		}
	}
}

int main()
{
	int arr[]={16,17,4,3,5,2};
	int size=sizeof(arr)/sizeof(arr[0]);
	printLeadersInArray(arr,size);
	return 0;
}
/*Output:
2	5	17
*/