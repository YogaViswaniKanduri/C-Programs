/* Program to find two elements that sum to a given value in an array */

#include<iostream>
using namespace std;

void findElementsWithSum(int a[],int start,int end,int reqsum)
{
	//mergesort(arr,start,end); 
	int sum=0;
	for(int i=start,j=end;i<j;)
	{
		sum=a[i]+a[j];
		if(sum==reqsum)
		{
			cout<<a[i]<<" "<<a[j]<<endl;
			i++;
		}
		else if(sum<reqsum)
			i++;
		else 
			j--;
	}
	
}

int main()
{
	//int arr[]={2,10,3,0,3,4,7,8,4};
	int arr[]={0,2,3,3,4,4,7,8,10};
	int size=sizeof(arr)/sizeof(arr[0]);
	int sum=10;
	findElementsWithSum(arr,0,size-1,sum);
	return 0;
}

/* Output:
0 10
2 8
3 7
3 7
*/