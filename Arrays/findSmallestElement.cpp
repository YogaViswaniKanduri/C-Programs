/* Program to find the smallest positive element that cannot be represented as a sum by any subset in the given sorted array?

T=O(n)

*/
#include<iostream>
using namespace std;

int findSmallestPositive(int arr[],int len)
{
	int num=1;
	for(int i=0;i<len;i++)
	{
		if(arr[i]>num)
			break;
		num+=arr[i];
	}
	return num;
}

int main()
{
	int arr[]={1,1,1,1,2};
	int size=sizeof(arr)/sizeof(arr[0]);
	cout<<"Element is: "<<findSmallestPositive(arr,size)<<endl;
	
   int arr1[] = {1, 3, 4, 5};
   int n1 = sizeof(arr1)/sizeof(arr1[0]);
   cout << findSmallestPositive(arr1, n1) << endl;
 
   int arr2[] = {1, 2, 6, 10, 11, 15};
   int n2 = sizeof(arr2)/sizeof(arr2[0]);
   cout << findSmallestPositive(arr2, n2) << endl;
 
   int arr3[] = {1, 1, 1, 1};
   int n3 = sizeof(arr3)/sizeof(arr3[0]);
   cout << findSmallestPositive(arr3, n3) << endl;
 
   int arr4[] = {1, 1, 3, 4};
   int n4 = sizeof(arr4)/sizeof(arr4[0]);
   cout << findSmallestPositive(arr4, n4) << endl;
	return 0;
}
/*Output:
Element is: 7
2
4
5
10
*/