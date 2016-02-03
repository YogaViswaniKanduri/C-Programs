/* program to replace all spaces in a string with %20 */

#include<iostream>
#include<string.h>

void replaceSpaces(char str[])
{
	int len=strlen(str);
	int spaceCount=0;
	for(int i=0;i<len;i++)
		if(str[i]==' ')
			spaceCount++;
	if(spaceCount<=0)
        return;
	
	char new_str[len+2*spaceCount];
	int index=0;
	for(int i=0;i<len;i++)
	{
		if(str[i]==' ')
		{
			new_str[index++]='%';
			new_str[index++]='2';
			new_str[index++]='0';
		}
		else
		{
			new_str[index++]=str[i];
		}
	}
	new_str[index]='\0';	   
	printf("%s",new_str);
	
	
}

int main()
{
	char str[]="I am a good girl";	
	replaceSpaces(str);
	return 0;
}