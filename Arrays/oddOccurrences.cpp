/* program to find two odd occurrences in an unsorted array */

#include<iostream>
using namespace std;

void findOddOccuringNumber(int arr[], int len)
{
	int xorValue=0;
	for(int i=0;i<len;i++)
	{
		xorValue^=arr[i];
	}
	int rightmostSetBit=(xorValue)&~(xorValue-1);
	int x=0,y=0;
	for(int i=0;i<len;i++)
	{
		if(arr[i]&rightmostSetBit)
			x^=arr[i];
		else
			y^=arr[i];
	}
	cout<<x<<" "<<y;
}


int main()
{
	int arr[]={2,1,3,2,1,2,3,3,3,4,3,4,3,4};
	int size=sizeof(arr)/sizeof(arr[0]);
	findOddOccuringNumber(arr,size);
	return 0;
}
/*output:
2 4
*/