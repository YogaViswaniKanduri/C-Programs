/* You are given an array of 0's and 1's in random order. Segregate 0's on left side and 1's on right side of the array.
Traverse array only once.
*/

#include<iostream>

void display(int arr[],int len)
{
	for(int i=0;i<len;i++)
		printf("%d\t",arr[i]);
}
//Time complexity = O(n) and space complexity=O(1)
void separate0sAnd1s(int arr[],int len)
{
	int lastIndexOfOne=-1;
	int temp;
	for(int i=0;i<len;i++)
	{
		if(arr[i]==1 && lastIndexOfOne==-1)
			lastIndexOfOne=i;
		else if(arr[i]==0 && lastIndexOfOne!=-1)
		{		
			arr[lastIndexOfOne]=0;
			arr[i]=1;
			lastIndexOfOne++;			
		}
	}	
}

int main()
{
	int arr[]={0,0,1,0,0,1,1,1,0,1};
	int size=sizeof(arr)/sizeof(arr[0]);
	separate0sAnd1s(arr,size);
	display(arr,size);
	printf("\n");
	int arr2[]={0,0,0,0,1,1,0,1};
	size=sizeof(arr2)/sizeof(arr2[0]);
	separate0sAnd1s(arr2,size);
	display(arr2,size);
	printf("\n");
	int arr3[]={0,0,0,0,0,0,0,0};
	size=sizeof(arr3)/sizeof(arr3[0]);
	separate0sAnd1s(arr3,size);
	display(arr3,size);
	printf("\n");
	int arr4[]={1,1,1,1,0,0,0,0};
	size=sizeof(arr4)/sizeof(arr4[0]);
	separate0sAnd1s(arr4,size);
	display(arr4,size);
	printf("\n");
	int arr5[]={1,1,1,1,1,1,1};
	size=sizeof(arr5)/sizeof(arr5[0]);
	separate0sAnd1s(arr5,size);
	display(arr5,size);
	return 0;
}
/*Output
0	0	0	0	0	1	1	1	1	1	
0	0	0	0	0	1	1	1	
0	0	0	0	0	0	0	0	
0	0	0	0	1	1	1	1	
1	1	1	1	1	1	1	
*/
/*Another approach:
count number of zeros and number of ones then change the array accordingly*/