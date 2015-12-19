#include<stdio.h>
#include<string.h>
bool isRotation(char s1[],char s2[])
{
	if(strlen(s1)!= strlen(s2))
	{
		return false;
	}
	strcat(s1,s1);
	if(strstr(s1,s2))
		return true;
	return false;
}
int main()
{
	char s1[]="erbottlewat";
	char s2[]="waterbottle";
	if(isRotation(s1,s2))
	{
		printf("\nStrings are rotation of each other");
	}
	else
	{
		printf("\nStrings are not rotation of each other");
	}
	return 0;
}
/*
Output:
Strings are rotation of each other
*/