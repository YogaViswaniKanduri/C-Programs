/*mergesort*/
#include <iostream>
using namespace std;

void merge(int arr[],int low,int mid,int high)
{
	int leftLength=mid-low+1,rightLength=high-mid;
	int leftArray[leftLength];
	int rightArray[rightLength];
	for(int i=0;i<leftLength;i++)
		leftArray[i]=arr[i+low];
	
	for(int j=0;j<rightLength;j++)
		rightArray[j]=arr[j+mid+1];
	
	int i=0,j=0,k=low;
	
	while(i<leftLength && j<rightLength)
	{
		if(leftArray[i]<=rightArray[j])
		{
			arr[k++]=leftArray[i++];
		}
		else 
		{
			arr[k++]=rightArray[j++];
		}
	}
	while(i<leftLength)
	{
		arr[k++]=leftArray[i++];
	}
	while(j<rightLength)
	{
		arr[k++]=rightArray[j++];
	}
}

void mergesort(int a[],int low, int high)
{
  if(low<high)
  {
    int mid=(low+high)/2;
    mergesort(a,low,mid);
    mergesort(a,mid+1,high);
    merge(a,low,mid,high);
  }
}
void printArray(int a[],int len)
{  
  
  for(int i=0;i<len;i++)
  {
    cout<<a[i]<<"\t";
  }
}
int main() {
  int a[]={8,7,6,5,4,3};
  mergesort(a,0,5);
  int len=sizeof(a)/sizeof(a[0]);
  printArray(a,len);
  return 0;
}
