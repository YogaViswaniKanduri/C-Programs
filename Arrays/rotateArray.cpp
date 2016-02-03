/*Program to rotate an array by k 

Block Swap algorithm

Time complexity=O(n) and space complexity=O(1)
*/

#include<iostream>

void reverseArray(int arr[],int start,int end)
{
	int temp;
	while(start<end)
	{
		temp=arr[start];
		arr[start]=arr[end];
		arr[end]=temp;		
		start++;
		end--;
	}
}

void display(int arr[],int len)
{
	printf("\n");
	for(int i=0;i<len;i++)
		printf("%d\t",arr[i]);
}

void rotateArrayByk(int arr[],int len,int k){
	
	reverseArray(arr,0,k-1);
	reverseArray(arr,k,len-1);
	reverseArray(arr,0,len-1);
	display(arr,len);	
}

int main()
{
	int arr[]={1,2,3,4,5,6,7,8,9};
	int size=sizeof(arr)/sizeof(arr[0]);
	int k;
	scanf("%d",&k);
	rotateArrayByk(arr,size,k);
	return 0;
}
/*Output:
6	7	8	9	1	2	3	4	5	
*/