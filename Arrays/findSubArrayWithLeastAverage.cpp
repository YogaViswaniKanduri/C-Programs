/* Find a contagious subarray of k numbers with least average. Given an array and k values*/

#include<iostream>
#include<limits.h>
void print_solution(int arr[], int start_index, int end_index)
{
	for(int i=start_index;i<=end_index;i++)
		printf("%d\t",arr[i]);
}
/* Brute force Algorithm  Complexity=O(n*k) */
void findLeastAverageSubarray(int arr[],int k, int length)
{
	int min_sum=INT_MAX;
	int curr_sum=0;
	int start_index=-1;
	int end_index=-1;	
	for(int i=0; i+k <= length; i++)
	{
		curr_sum=0;
		for(int j=k-1;j>=0;j--)
		{
			curr_sum += arr[i+j];
		}
		if(curr_sum < min_sum)
		{
			min_sum=curr_sum;
			start_index=i;
			end_index=i+k-1;
		}
	}
	print_solution(arr, start_index, end_index);
}
/*
Optimized O(n) algorithm
*/
void optimizedFindLeastAverage(int arr[], int k, int length)
{
	int min_sum=INT_MAX;
	int curr_sum=0;
	int start_index=0;
	int end_index=k-1;
	for(int i=0; i<k; i++)
		curr_sum +=arr[i];
	for(int i=k;i<length;i++)
	{
		curr_sum += arr[i]-arr[i-k];
		if(curr_sum < min_sum)
		{
			min_sum = curr_sum;
			start_index = i-k+1;
			end_index = i;
		}
	}
	print_solution(arr, start_index, end_index);
}

int main()
{
	int arr[]={3, 7, 90, 20, 10, 50, 40};
	int size=sizeof(arr)/sizeof(arr[0]);
	int k=3;
	findLeastAverageSubarray(arr,k,size);
	printf("\n");
	optimizedFindLeastAverage(arr,k,size);
	return 0;
}
/*output
20	10	50
20	10	50
*/


