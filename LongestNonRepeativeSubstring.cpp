/*Program to print longest substring without repeating characters
Logic is derived from maximum contiguous sub array
substring => the output sequence should be continguous
*/
#include<stdio.h>
#include<string.h>
void printSoultion(char a[],int start, int end, int len)
{
	printf("\nLongest nonrepeative substring is:");
	for(int i=start;i<=end;i++)
	{
		printf("%c\t",a[i]);
	}
	printf("\nLength of the longest nonrepeative substring is:%d",len);
}
void longestNonrepeativeSubstring(char a[],int len)
{
	int hit[26]={0};
	int start=0, end=0,temp_start=0;
	int count=0,max_count=0;
	for(int i=0;i<len;i++)
	{
		if(hit[a[i]-'a']==0)
		{
			count++;
			if(count>max_count)
			{
				max_count=count;
				start=temp_start;
				end=i;				
			}
		}
		else
		{
			//hit[26]={0}; ----- this will not work use memset function string.h library
			memset(hit,0,sizeof(hit));
			count=1;
			temp_start=i;
		}
		hit[a[i]-'a']=1;
	}
	printSoultion(a,start,end,max_count);
}
int main()
{
	char a[]="geeksforgeeks";
	int len=sizeof(a)/sizeof(a[0]);
	longestNonrepeativeSubstring(a,len);
	char b[]="facebook";
	int len2=sizeof(a)/sizeof(a[0]);
	longestNonrepeativeSubstring(b,len2);
	return 0;	
}