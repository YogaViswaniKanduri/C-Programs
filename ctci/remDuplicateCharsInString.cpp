/* Program to remove duplicate characters in a string */

#include<iostream>
#include<string.h>

//Time Complexity=O(n^2)
void remDuplicateCharsInString(char str[])
{
	int tail=1,j=0;
	int len=strlen(str);
	char key;
	
	for(int i=1;i<len;i++)
	{
		key=str[i];
		for(j=0;j<tail;j++)
		{
			if(str[j]==key)
				break;
		}
		if(j==tail)
		{
			str[tail]=str[i];
			tail++;
		}
	}
	str[tail]='\0';
}

int main()
{
	char str[]="geeks";
	remDuplicateCharsInString(str);
	printf("%s\n",str);
	return 0;	
}
/*
Output:
geks
*/