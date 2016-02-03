/* Program to buy and sell stock such that maximum profit occurs
The cost of a stock on each day is given in an array, find the max profit that you can make by buying and selling in those days.
*/
#include<iostream>
using namespace std;

void printArray(int arr[],int len)
{
	cout<<endl;
	for(int i=0;i<len;i++)
		cout<<arr[i]<<" ";
}


void buySellStock(int arr[],int len)
{
	int buy,sell,i=0;
	while(i<len-1)
	{
		buy=sell=i;
		while(i<len-1 && arr[i+1]<=arr[i])
		{
			buy++;
			i++;
		}
		if(i<len) sell=i;
		while(i<len-1 && arr[i+1]>arr[i])
		{
			sell++;
			i++;
		}
		if(sell>buy)
		{
			cout<<endl<<"Buy on : "<<buy;
			cout<<endl<<"Sell on: "<<sell;
		}
	}
}

int main()
{
	int arr[]={100,180,260,310,40,535,695};
	int size=sizeof(arr)/sizeof(arr[0]);
	printArray(arr,size);
	buySellStock(arr,size);
	int arr2[]={100,180,260,310,440,535,695};
	int size2=sizeof(arr2)/sizeof(arr2[0]);
	printArray(arr2,size2);
	buySellStock(arr2,size2);
	int arr3[]={100,50,40,30,20,10,4};
	int size3=sizeof(arr3)/sizeof(arr3[0]);
	printArray(arr3,size3);
	buySellStock(arr3,size3);
	int arr4[]={100,50,40,30,120,110,4};
	int size4=sizeof(arr4)/sizeof(arr4[0]);
	printArray(arr4,size4);
	buySellStock(arr4,size4);
	return 0;
}
/*Output:
100 180 260 310 40 535 695 
Buy on : 0
Sell on: 3
Buy on : 4
Sell on: 6
100 180 260 310 440 535 695 
Buy on : 0
Sell on: 6
100 50 40 30 20 10 4 
100 50 40 30 120 110 4 
Buy on : 3
Sell on: 4
*/

