/* Program to replace every element with the greatest element on right side 
Given an array of integers, replace every element with the next greatest element (greatest element on the right side) in the array.
Since there is no element next to the last element, replace it with -1.
Time complexity = O(n) and space complexity = O(1) */

#include<iostream>

void display(int arr[],int len)
{
	printf("\n");
	for(int i=0;i<len;i++)
		printf("%d\t",arr[i]);
}
void replaceEleWithMax(int arr[],int len)
{
	int max_so_far=-1;
	int temp=0;
	for(int i=len-1;i>=0;i--)
	{
		temp=arr[i];
		arr[i]=max_so_far;
		if(temp>max_so_far)
			max_so_far=temp;		
	}
}

int main()
{
	int arr[]= {16, 17, 4, 3, 5, 2};
	int size=sizeof(arr)/sizeof(arr[0]);
	replaceEleWithMax(arr,size);
	display(arr,size);
	return 0;
}

/*Output:
17	5	5	5	2	-1
*/