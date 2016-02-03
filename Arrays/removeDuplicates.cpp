/* program to remove duplicates in an array */

#include <iostream>
#include <string.h>
using namespace std;

void removeDuplicates(char str[])
{
	int len=strlen(str);
	int tail=0;
	int hit[256]={0};
	for(int i=0;i<len;i++)
	{
		if(hit[str[i]]==0)
		{
			str[tail]=str[i];
			tail++;
			hit[str[i]]++;
		}		
	}
	str[tail]='\0';
}

int main()
{
	char arr[]={'g','e','e','k','s','f','o','r','g','e','e','k','s'};
	removeDuplicates(arr);
	cout<<arr;
	return 0;	
}
/*Output:
geksfor
*/