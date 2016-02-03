/* Program to find ceil and floor of a number in a sorted array 
Time complexity=O(logn)
*/

#include <iostream>
using namespace std;

void floorCeilOfANum(int arr[],int low,int high,int num)
{
	int floor=-1,ceil=-1,mid;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(arr[mid]==num)
		{
			floor=num;
			ceil=num;
			break;
		}
		else if(arr[mid]<num)
		{
			floor=arr[mid];
			low=mid+1;
		}
		else{
			ceil=arr[mid];
			high=mid-1;
		}
	}
	cout<<"floor: "<<floor<<" num: "<<num<<" ceil: "<<ceil;
}

int main()
{
	int arr[]={2,4,6,8,10,12,14};
	int size=sizeof(arr)/sizeof(arr[0]);
	int k=7;
	floorCeilOfANum(arr,0,size-1,k);
	return 0;
}
/*output:
floor= 6 num=7 ceil =8
*/