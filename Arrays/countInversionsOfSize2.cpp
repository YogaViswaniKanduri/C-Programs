#include<iostream>
using namespace std;

int merge(int arr[],int low,int mid ,int high)
{
	int leftarr[mid-low+1];
	int rightarr[high-mid];
	int inversionCount=0;
	for(int i=0;i<mid-low+1;i++)
	{
		leftarr[i]=arr[low+i];
	}
	for(int i=0;i<high-mid;i++)
	{
		rightarr[i]=arr[mid+1+i];
	}
	int i=0,j=0,k=low;
	while(i<(mid-low+1) &&j<(high-mid))
	{
		if(leftarr[i]<=rightarr[j])
		{
			arr[k++]=leftarr[i++];
		}
		else
		{
			arr[k++]=rightarr[j++];
			inversionCount+=mid-low-i+1; //----------------------------------------important
			//cout<<"enterand inversioncount:"<<inversionCount<<endl;
		}	
	}
	while(i<(mid-low+1))
	{
		arr[k++]=leftarr[i++];
	
	}
	while(j<(high-mid))
	{
		arr[k++]=rightarr[j++];
	}
	return inversionCount;
}

int mergesort(int arr[],int low, int high)
{
    int inversionCount=0;
	if(low<high)
	{
		
		int mid=(low+high)/2;
		inversionCount+=mergesort(arr,low,mid);
		inversionCount+=mergesort(arr,mid+1,high);
		inversionCount+=merge(arr,low,mid,high);
		
	}
	return inversionCount;
}


int main()
{
	//int arr[]={1, 20, 6, 4, 5};
	//int arr[]={9,6,4,5,8};
	int arr[]={8,4,2,1};
	int size=sizeof(arr)/sizeof(arr[0]);
	int countInversions=mergesort(arr,0,size-1);
	for(int i=0;i<size;i++)
		cout<<arr[i]<<" ";
	cout<<endl<<"Count of inversions of the array are:"<<countInversions<<endl;
	return 0;
}