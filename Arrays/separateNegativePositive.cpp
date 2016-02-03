/* Rearrange array elements such that all negative elements appear at the beginning of the array*/
#include<iostream>
using namespace std;

void rotate(int arr[],int start,int end)
{
	int temp=arr[end];
	while(end>start)
	{
		arr[end]=arr[end-1];
		end--;
	}
	arr[start]=temp;
}

void swap(int *x,int *y)
{
	if(*x!=*y)
	{
		*x=*x^*y;
		*y=*x^*y;
		*x=*x^*y;
	}
}

void separateNegativePositiveWithOrder(int arr[],int len)
{
	int i=0;
	for(int j=0;j<len;j++)
	{
		if(arr[j]<0)
		{
			rotate(arr,i,j);
			i++;
		}
	}
}

void separateNegativePositiveWithoutOrder(int arr[],int len)
{
	int i=0;
	for(int j=0;j<len;j++)
	{
		if(arr[j]<0)
		{
			swap(&arr[i],&arr[j]);
			i++;
		}
	}
}

void printArray(int arr[],int len)
{
	for(int i=0;i<len;i++)
	{
		cout<<arr[i]<<" ";
	}
}

int main()
{
	int arr[]={2,-1,-3,4,5,6,-7,8,9};
	int size=sizeof(arr)/sizeof(arr[0]);
	printArray(arr,size);
	cout<<endl<<"Separate without changing order: ";
	separateNegativePositiveWithOrder(arr,size);
	printArray(arr,size);
	int arr2[]={2,-1,-3,4,5,6,-7,8,9};
	int size2=sizeof(arr2)/sizeof(arr2[0]);
	cout<<endl<<"Separate with changing order: ";
	separateNegativePositiveWithoutOrder(arr2,size);
	printArray(arr2,size);
	return 0;
}

/*output:
2 -1 -3 4 5 6 -7 8 9 
Separate without changing order: -1 -3 -7 2 4 5 6 8 9 
Separate with changing order: -1 -3 -7 4 5 6 2 8 9 
*/