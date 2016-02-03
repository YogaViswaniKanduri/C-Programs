/* Program to reverse a string */

#include<iostream>
#include<string.h>

void reverseString(char str[])
{
	int start=0;
	int end=strlen(str)-1;
	char temp;
	while(start<end)
	{
		temp=str[start];
		str[start]=str[end];
		str[end]=temp;
		start++;
		end--;
	}
}

void reverseStringRecursion(char str[],int start, int end)
{
	if(start<end)
	{
		char temp=str[start];
		str[start]=str[end];
		str[end]=temp;
		reverseStringRecursion(str,++start,--end);
	}
	
}

int main()
{
	char str[]="linda";
	reverseString(str);
	printf("%s\n",str);
	reverseStringRecursion(str,0,strlen(str)-1);
	printf("%s\n",str);
	return 0;
}
/*Output:
adnil
linda
*/