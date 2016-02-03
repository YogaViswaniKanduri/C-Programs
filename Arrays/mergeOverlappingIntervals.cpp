/* Program to merge overlapping intervals 
Given a set of time intervals in any order, merge all overlapping intervals into one and output the result which should have only mutually exclusive intervals. 
Let the intervals be represented as pairs of integers for simplicity.
*/

#include<iostream>
#include<algorithm>
using namespace std;

struct interval
{
	int start;
	int end;
};

int max(int a,int b)
{
    return a>b?a:b;
}

int min(int a,int b)
{
    return a<b?a:b;    
}

int compare(struct interval a,struct interval b)
{
	return a.start>b.start;
}

void printIntervals(struct interval *arr,int len)
{
    for(int i=0;i<len;i++)
    {
        cout<<arr[i].start<<" "<<arr[i].end<<endl;
    }
}

void mergeOverlappingIntervals(struct interval *arr,int len)
{
	sort(arr,arr+len,compare);
	cout<<"sorted intervals:"<<endl;
	printIntervals(arr,len);
	int index=0;
	for(int i=1;i<len;i++)
	{
		if(arr[index].start<=arr[i].end)
		{
		    //cout<<index<<" "<<i;
			arr[index].start=min(arr[index].start,arr[i].start);
			arr[index].end=max(arr[index].end,arr[i].end);			
		}
		else
		{
		    index++;
			arr[index].start=arr[i].start;
			arr[index].end=arr[i].end;
		}
	}
	cout<<"Merged Intervals:"<<endl;
	printIntervals(arr,index+1);
}

int main()
{
	int len=4;
	struct interval *arr=(struct interval *)malloc(len*sizeof(struct interval));
	arr[0].start=1;
	arr[0].end=3;
	arr[1].start=2;
	arr[1].end=4;
	arr[2].start=5;
	arr[2].end=7;
	arr[3].start=6;
	arr[3].end=8;
	mergeOverlappingIntervals(arr,len);
	return 0;
}
/*Output:
sorted intervals:
6 8
5 7
2 4
1 3
Merged Intervals:
5 8
1 4
*/