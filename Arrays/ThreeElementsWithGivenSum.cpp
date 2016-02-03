/* Program to find two elements that sum to a given value in an array */

#include<iostream>
using namespace std;

void findElementsWithSum(int a[],int start,int end,int reqsum)
{
	//mergesort(arr,start,end); 
	int sum=0,index,subsum=0;
	for(int i=start;i<end;i++)
	{
		sum=reqsum-a[i];		
		for(int j=i+1,k=end;j<k;)
		{
			subsum=a[j]+a[k];
			if(subsum==sum)
			{
				cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<endl;
				j++;
			}
			else if(subsum<sum)
				j++;
			else
				k--;
				
		}
	}
	
}

int main()
{
	//int arr[]={2,10,3,0,3,4,7,8,4};
	int arr[]={0,2,3,3,4,4,7,8,10};
	int size=sizeof(arr)/sizeof(arr[0]);
	int sum=10;
	findElementsWithSum(arr,0,size-1,sum);
	cout<<endl;
	int arr2[]={ 2, 3, 4, 5, 7, 8, 9, 10};
	int size2=sizeof(arr2)/sizeof(arr2[0]);
	int sum2=14;
	findElementsWithSum(arr2,0,size2-1,sum2);
	return 0;
}

/* Output:
0 2 8
0 3 7
0 3 7
2 4 4
3 3 4

2 3 9
2 4 8
2 5 7
3 4 7
*/