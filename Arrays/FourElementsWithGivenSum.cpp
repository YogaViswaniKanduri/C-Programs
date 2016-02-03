/* Program to find four elements with given sum*/

#include<iostream>
#include<stdlib.h>
using namespace std;

struct Entry
{
	int sum;
	int firstIndex;
	int secondIndex;
};


void merge(struct Entry* arr,int low, int mid,int high)
{
	int leftLength=mid-low+1,rightLength=high-mid;
	struct Entry* leftArray=(struct Entry*)malloc(leftLength*sizeof(struct Entry));
	struct Entry* rightArray=(struct Entry*)malloc(rightLength*sizeof(struct Entry));
	
	for(int i=0;i<leftLength;i++)
	{
		leftArray[i].sum=arr[i+low].sum;
		leftArray[i].firstIndex=arr[i+low].firstIndex;
		leftArray[i].secondIndex=arr[i+low].secondIndex;
	}
	
	for(int i=0;i<rightLength;i++)
	{
		rightArray[i].sum=arr[i+mid+1].sum;
		rightArray[i].firstIndex=arr[i+mid+1].firstIndex;
		rightArray[i].secondIndex=arr[i+mid+1].secondIndex;
	}
	
	int i=0,j=0,k=low;
	
	while(i<leftLength&&j<rightLength)
	{
		if(leftArray[i].sum<=rightArray[j].sum)
		{
			arr[k].sum=leftArray[i].sum;
			arr[k].firstIndex=leftArray[i].firstIndex;
			arr[k].secondIndex=leftArray[i].secondIndex;
			k++;
			i++;
		}
		else{
			arr[k].sum=rightArray[j].sum;
			arr[k].firstIndex= rightArray[j].firstIndex;
			arr[k].secondIndex=rightArray[j].secondIndex;
			k++;
			j++;			
		}
	}
	while(i<leftLength)
	{
		arr[k].sum=leftArray[i].sum;
		arr[k].firstIndex=leftArray[i].firstIndex;
		arr[k].secondIndex=leftArray[i].secondIndex;
		k++;
		i++;		
	}
	while(j<rightLength)
	{
		arr[k].sum=rightArray[j].sum;
		arr[k].firstIndex= rightArray[j].firstIndex;
		arr[k].secondIndex=rightArray[j].secondIndex;
		k++;
		j++;
	}
}

void mergesort(struct Entry* arr,int low,int high)
{
	if(low<high)
	{
		int mid=(low+high)/2;
		mergesort(arr,low,mid);
		mergesort(arr,mid+1,high);
		merge(arr,low,mid,high);
	}
}

bool checkRepetitions(struct Entry a,struct Entry b)
{
	if(a.firstIndex==b.firstIndex || a.firstIndex==b.secondIndex || a.secondIndex==b.firstIndex || a.secondIndex==b.secondIndex )
		return false;
	return true;
}

int compare(const void * a, const void * b)
{
   return (((*(struct Entry * )a).sum-(*(struct Entry *)b).sum));
}

void findElementsWithGivenSum(int arr[],int len,int reqsum)
{
	//Creating an array of sum of all pairs	
	int sumArrLength=len*(len-1)/2;
	struct Entry *sumarray=(struct Entry *)malloc(sumArrLength*sizeof(Entry));
	int index=0,sum=0;
	for(int i=0;i<len;i++)
	{
		for(int j=i+1;j<len;j++)
		{
			sumarray[index].sum=arr[i]+arr[j];
			sumarray[index].firstIndex=i;
			sumarray[index].secondIndex=j;
			index++;
		}
	}
	
	/*for(int i=0;i<sumArrLength;i++)
		cout<<sumarray[i].sum<<",";
	*/
	//mergesort(sumarray,0,sumArrLength-1);
	qsort(sumarray,sumArrLength-1,sizeof(sumarray[0]),compare);
	
	/*cout<<endl<<endl;
	for(int i=0;i<sumArrLength;i++)
		cout<<sumarray[i].sum<<",";
	
	cout<<endl<<endl;*/
	
	
	for(int i=0,j=sumArrLength-1;i<j;)
	{
		sum=sumarray[i].sum+sumarray[j].sum;
		if(sum==reqsum && checkRepetitions(sumarray[i],sumarray[j]))
		{
			cout<<arr[sumarray[i].firstIndex]<<" "<<arr[sumarray[i].secondIndex]<<" "<<arr[sumarray[j].firstIndex]<<" "<<arr[sumarray[j].secondIndex]<<endl;
			i++;
		}
		else if(sum<reqsum)
		{
			i++;
		}
		else
			j--;
	}
	
}


int main()
{
	int arr[]={10, 2, 3, 4, 5, 9, 7, 8};
	//int arr[]={1,2,4};
	int sum=23;	
	int size=sizeof(arr)/sizeof(arr[0]);
	findElementsWithGivenSum(arr,size,sum);
	return 0;
}

/*
Output: 
3 5 7 8
2 7 5 9
2 8 4 9
3 7 4 9
2 9 5 7
3 8 5 7
4 7 3 9
*/