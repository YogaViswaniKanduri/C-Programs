/* Program to find intersection of two sorted arrays
T=O(n1+n2)
*/
#include<iostream>
using namespace std;

void findCommonInTwoArrays(int arr1[],int arr2[],int len1,int len2)
{
	int i=0,j=0;
	while(i<len1 && j<len2)
	{
		if(arr1[i]==arr2[j])
		{
			cout<<arr1[i]<<" ";
			i++;
			j++;
		}
		else if(arr1[i]<arr2[j])
		{
			i++;
		}
		else
			j++;
	}
}

int main()
{
	int arr1[]={1, 5, 5};
	int size1=sizeof(arr1)/sizeof(arr1[0]);
	int arr2[]={3,4,5,5,10};
	int size2=sizeof(arr2)/sizeof(arr2[0]);
	findCommonInTwoArrays(arr1,arr2,size1,size2);
	return 0;
}
/*Output:
5 5 
*/