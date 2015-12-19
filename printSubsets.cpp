/* program to print subsets of a set */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void printSubsets(char a[], int len)
{	
	int noOfSets = pow(2,len);
	int counter=0;
	for(int i=0; i<noOfSets; i++)
	{
		counter=i;
		for(int j=0;j<len;j++)
		{
			if(counter>>j&1)
			{
				printf("%c\t",a[j]);
			}
		}
		printf("\n");
	}		
}
int main()
{
	char a[]={'a','b','c'};
	int len=sizeof(a)/sizeof(a[0]);
	printf("len is: %d",len);
	printSubsets(a,len);
	return 0;
}