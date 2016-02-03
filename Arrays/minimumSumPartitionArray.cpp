#include <iostream>
#include <stdlib.h>
using namespace std;

void merge(int arr[],int low,int mid,int high)
{
    int temp[high-low+1];
    int i=low,j=mid+1,k=low;
    while(i<=mid && j<=high)
    {
        if(arr[i]<=arr[j])
            temp[k++]=arr[i++];
        else
            temp[k++]=arr[j++];
    }
    while(i<=mid)
    {
        temp[k++]=arr[i++];
    }
    while(j<=high)
    {
        temp[k++]=arr[j++];
    }
    for(int i=low;i<=high;i++)
    {
        arr[i]=temp[i];
    }
}

void mergesort(int arr[],int low,int high)
{
    if(low<high)
    {
        int mid= (low+high)/2;
        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}

int sumOfElements(int arr[],int N)
{
    int sum=0;
    for(int i=0;i<N;i++)
        sum+=arr[i];
    return sum;
}

int findAbsDiff(int arr[],int N)
{
    mergesort(arr,0,N-1);
    int s1_sum=0,s2_sum=0;
    s1_sum=sumOfElements(arr,N);
    int minDiff=abs(s1_sum-s2_sum);
    for(int i=N-1;i>=0;i--)
    {
        s1_sum-=arr[i];
        s2_sum+=arr[i];
        if(abs(s1_sum-s2_sum)<minDiff)
            minDiff=abs(s1_sum-s2_sum);
    }
    return minDiff;
}

int main() {
	int T=0,N=0;
	int arr[N];
	cin>>T>>N;
	for(int i=0;i<N;i++)
	    cin>>arr[i];
	//for(int i=0;i<T;i++)
		cout<<findAbsDiff(arr,N)<<endl;
	return 0;
}
