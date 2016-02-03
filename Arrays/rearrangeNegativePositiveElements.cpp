/* Program to rearrange elements such that all the positive and negative elements are arranged in such a way that positive is always followed by negative and 
the array starts with negative element. Order of occurrence of elements should be same in the result

WITHOUT USING EXTRA SPACE

*/

#include<iostream>
using namespace std;

void printArray(int arr[],int len)
{
	for(int i=0;i<len;i++)
	{
		cout<<arr[i]<<" ";
	}
}

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

void rearrangeNegativePositiveWithOrder(int arr[],int len)
{
	int mismatch=-1,i=0;
	while(i<len)
	{
		if(mismatch==-1)
		{
			if((arr[i]<0 && i%2!=0)||(arr[i]>=0 && i%2==0))
			{
				mismatch=i;
			}
		}
		else if((arr[mismatch]>=0&&arr[i]<0)||(arr[mismatch]<0&&arr[i]>=0))
		{
			rotate(arr,mismatch,i);
			if(i-mismatch>2)
			{
				mismatch+=2;
			}
			else{
				mismatch=-1;
			}				
			
		}
		i++;
	}
	
}

void swap(int *x, int *y)
{
	if(*x!=*y)
	{
		*x=*x^*y;
		*y=*x^*y;
		*x=*x^*y;
	}
}

void rearrangeNegativePositiveWithoutOrder(int arr[],int len)
{
	int mismatch=-1,i=0;
	while(i<len)
	{
		if(mismatch==-1)
		{
			if((arr[i]<0 && i%2!=0) || (arr[i]>=0&& i%2==0))
			{
				mismatch=i;
			}
		}
		else if((arr[mismatch]>=0&&arr[i]<0)||(arr[mismatch]<0&&arr[i]>=0))
		{
			swap(&arr[mismatch],&arr[i]);
			if(i-mismatch>2)
				mismatch+=2;
			else
				mismatch=-1;
		}
		i++;		
	}
	
}

int main()
{
	int arr[]={2,-1,-3,4,5,6,-7,8,9};
	int size=sizeof(arr)/sizeof(arr[0]);
	printArray(arr,size);
	cout<<endl<<"rearrange without changing order: ";
	rearrangeNegativePositiveWithOrder(arr,size);
	printArray(arr,size);
	int arr2[]={2,-1,-3,4,5,6,-7,8,9};
	int size2=sizeof(arr2)/sizeof(arr2[0]);
	cout<<endl<<"rearrange with changing order: ";
	rearrangeNegativePositiveWithoutOrder(arr2,size2);
	printArray(arr2,size2);
	return 0;
}
/*Output:
2 -1 -3 4 5 6 -7 8 9 
rearrange without changing order: -1 2 -3 4 -7 5 6 8 9 
rearrange with changing order: -1 2 -3 4 -7 6 5 8 9 
*/