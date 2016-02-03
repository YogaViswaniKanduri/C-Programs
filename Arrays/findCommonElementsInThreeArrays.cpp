/* Program to find common elements in three arrays
T=O(n1+n2+n3)
*/

#include<iostream>
using namespace std;

void findCommonElementsInThreeArrays(int arr1[],int arr2[],int arr3[],int len1,int len2,int len3)
{
	int i=0,j=0,k=0;
	while(i<len1&& j<len2&& k<len3)
	{
		if(arr1[i]==arr2[j] && arr1[i]==arr3[k])
		{
			cout<<arr1[i]<<" ";
			i++;
			j++;
			k++;
		}
		else if(arr1[i]<arr2[j])
			i++;
		else if(arr2[j]<arr3[k])
			j++;
		else 
			k++;
	}
}

int main()
{   
    int arr1[] = {1, 5, 10, 20, 40, 80};
    int arr2[] = {6, 7, 20, 80, 100};
    int arr3[] = {3, 4, 15, 20, 30, 70, 80, 120};
    int len1=sizeof(arr1)/sizeof(arr1[0]);
    int len2=sizeof(arr2)/sizeof(arr2[0]);
    int len3=sizeof(arr3)/sizeof(arr3[0]);
	findCommonElementsInThreeArrays(arr1,arr2,arr3,len1,len2,len3);
	return 0;
}
/* Output:
20 80 
*/