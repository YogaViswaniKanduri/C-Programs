/* Program to find if a string has all unique characters or not */

#include<iostream>
#include<string.h>

//Time Complexity=O(n) and space complexity=O(1)
bool checkUniqueCharacters(char str[])
{
	int len=strlen(str);
	int flag=0,val=0;
	for(int i=0;i<len;i++)
	{
		val=str[i]-'a';
		if(flag & 1<<(val-1))
			return false;
		flag = flag | 1<<(val-1);
	}
	return true;
}

int main()
{
	char str[]="indian";
	printf("%s",checkUniqueCharacters(str)?"true":"false");
	return 0;
}
/*Output:
false
*/
