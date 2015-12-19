/* Print Anagrams of a string 
permutations of a string
interleavings of a string
*/
#include<stdio.h>
void swap(char a[],int src,int des)
{
	char temp=a[src];
	a[src]=a[des];
	a[des]=temp;
}
void printArray(char a[],int len)
{
	for(int i=0;i<len;i++)
	{
		printf("%c",a[i]);		
	}
	printf("\n");
}
void printAnagrams(char a[],int index, int len)
{
	if(index==(len-1))
	{
		printArray(a,len);
		return;
	}
	for(int i=index;i<len;i++)
	{
		swap(a,index,i);
		printAnagrams(a,index+1,len);
		swap(a,index,i);
	}
}
void copyArray(char temp_arr[],char arr[],int *temp_index)
{
	int len=sizeof(arr)/sizeof(arr[0]);
	int i=0;
	while(i<len)
	{
		temp_arr[*temp_index]=arr[i];
		*temp_index++;
	}
}
void printAnagrams_optimized(char arr[],int index,int len)
{
	char temp_arr[2*len];
	int temp_index=0;
	for(int i=0;i<len;i++)
	{
		swap(arr,index,i);
		copyArray(temp_arr,arr,&temp_index);
		copyArray(temp_arr,arr,&temp_index);
		for(int j=0;j<len;j++)
		{
			printf("%c%c%c\n",temp_arr[j],temp_arr[j+1],temp_arr[j+2]);
		}
		swap(arr,index,i);
	}
}



int main()
{
	char arr[]={'a','b','c'};
	int len=sizeof(arr)/sizeof(arr[0]);
	printAnagrams(arr,0,len);
	printAnagrams_optimized(arr,0,len);
	return 0;
}
/*Output:
abc
acb
bac
bca
cba
cab
*/