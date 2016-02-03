/* Rearrange array in such a way that all zeros appear at the end of the array */
#include<iostream>
using namespace std;

void printArray(int arr[],int len)
{
	cout<<endl;
	for(int i=0;i<len;i++)
		cout<<arr[i]<<" ";
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

//inplace swapping
void rearrangeZerosUsingSwapping(int arr[],int len)
{
	int mismatch=-1;
	for(int i=0;i<len;i++)
	{
		if(arr[i]==0&&mismatch==-1)
			mismatch=i;
		if(arr[i]!=0&&mismatch!=-1)
		{
			swap(&arr[i],&arr[mismatch]);
			mismatch++;
		}
	}
}


//counting non zeros 
void rearrangeZeros(int arr[],int len)
{
	int count=0;
	for(int i=0;i<len;i++)
	{
		if(arr[i]!=0)
		{
			arr[count++]=arr[i];
		}
	}
	while(count<len)
	{
		arr[count++]=0;
	}
}

int main()
{
	int arr[]={1,9,8,4,0,0,0,7,2,0,6,0};
	int size=sizeof(arr)/sizeof(arr[0]);
	printArray(arr,size);
	rearrangeZeros(arr,size);
	printArray(arr,size);
	int arr2[]={1,9,8,4,0,0,0,7,2,0,6,0};
	int size2=sizeof(arr2)/sizeof(arr2[0]);
	printArray(arr2,size2);
	rearrangeZerosUsingSwapping(arr2,size2);
	printArray(arr2,size2);
	return 0;
}
/*Output:
1 9 8 4 0 0 0 7 2 0 6 0 
1 9 8 4 7 2 6 0 0 0 0 0 
1 9 8 4 0 0 0 7 2 0 6 0 
1 9 8 4 7 2 6 0 0 0 0 0 
*/