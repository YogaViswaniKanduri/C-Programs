/* program to rint vertical bars of "#" 
	Given a 1D array with integers, print vertical bars of "#" {1,4,3,2}
	T=O(maxElement*len)
*/
#include<iostream>
using namespace std;

void printVerticalBars(int arr[],int len)
{
	int max=arr[0],height;
	for(int i=0;i<len;i++)
	{
		if(max<arr[i])
			max=arr[i];
	}
	height=max-1;
	for(int i=height;i>=0;i--)
	{
		for(int j=0;j<len;j++)
		{
			if(arr[j]>i)
				cout<<"#";
			else
				cout<<" ";
		}
		cout<<endl;
	}
}

int main()
{
	int arr[]={1,4,3,2};
	int size=sizeof(arr)/sizeof(arr[0]);
	printVerticalBars(arr,size);
	return 0;
}
/*Output:
 #  
 ## 
 ###
####
*/