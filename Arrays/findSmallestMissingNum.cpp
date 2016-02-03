/* Program to find smallest missing number */

#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
	if(*a!=*b)
	{
		*a=*a^*b;
		*b=*a^*b;
		*a=*a^*b;
	}
}

int segregatePositivesAndNonPositives(int arr[],int len)
{
	int i=0;
	for(int j=0;j<len;j++)
	{
		if(arr[j]<=0)
		{
			swap(&arr[i],&arr[j]);
			i++;
		}
	}
	return i;
}

int findPositiveMissing(int arr[],int len)
{
	for(int i=0; i<len; i++)
	{
		if(abs(arr[i])<len)
		{
			arr[abs(arr[i])]=-abs(arr[abs(arr[i])]);
		}
	}
	for(int i=1;i<len;i++)
		if (arr[i]>0) return i;
}

int findSmallestMissingNum(int arr[],int len)
{
	int index=segregatePositivesAndNonPositives(arr,len);
	return findPositiveMissing(arr+index, len-index);	
}

int main()
{
	int arr[]={5, 3, 7, 6, 8, 1, -10, 15};
	int size=sizeof(arr)/sizeof(arr[0]);
	cout<<"The smallest missing number: "<<findSmallestMissingNum(arr,size);
	return 0;
}
/* 
Output: The smallest missing number: 2
*/