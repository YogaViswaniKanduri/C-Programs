/* Program to find majority element in a sorted array */
//C function to find if a given integer x appears more than n/2 times in a sorted array of n integers.

#include<iostream>

int binarysearch(int arr[],int low,int high,int ele){
	if(low<=high)
	{
		int mid=(low+high)/2;
		if(arr[mid]==ele&&(mid==0||arr[mid-1]<ele))
			return mid;
		else if(arr[mid]<ele)
			return binarysearch(arr,mid+1,high,ele);
		else
			return binarysearch(arr,low,mid-1,ele);					
	}
	return -1;
}
/*Time complexity=O(log n)*/
bool checkForMajority(int arr[],int len,int ele)
{
	//get the first occurence of search element in the array using binary search
	int firstIndex=binarysearch(arr,0,len-1,ele);
	if(firstIndex==-1)
		return false;
	else{
		if((firstIndex+len/2 < len)&&arr[firstIndex+ len/2]==ele)
			return true;
		else return false;
	}
}

int main()
{
	int arr[]={1,1,1,1,1,3,3,3,4};
	int size=sizeof(arr)/sizeof(arr[0]);
	int key=1;
	printf("%s",checkForMajority(arr,size,key)?"true":"false");	
	return 0;
}

/*Output:
true
*/
