/* Count the number of possible triangles formed by array of elements

T=O(n2)
*/

#include<iostream>
#include<algorithm>
using namespace std;

int compare(int a, int b)
{
	return a<b?1:0;
}

void printArray(int arr[],int len)
{
	cout<<endl;
	for(int i=0;i<len;i++)
		cout<<arr[i]<<" ";
}

int countTriangles(int arr[],int len)
{
	sort(arr,arr+len,compare);
	printArray(arr,len);
	int k,count=0;
	for(int i=0;i<len-2;i++)
	{
		k=i+2;//this will reduce the complexity
		for(int j=i+1;j<len-1;j++)
		{
			while(k<len && arr[k]<arr[i]+arr[j])
			{
				k++;
			}
			count+=k-j-1;
		}
	}
	return count;	
}

int main()
{
	int arr[]={7,6,3,4};
	int size=sizeof(arr)/sizeof(arr[0]);
	cout<<"Number of traingles formed by given array is: "<<countTriangles(arr,size);
	return 0;
}
/*output:
3 4 6 7 Number of traingles formed by given array is: 3
*/
