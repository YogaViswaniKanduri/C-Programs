/* Program to add two bit strings */

#include<iostream>
#include<string.h>

int max(int a,int b)
{
	return a>b?a:b;
}

void reverse(char res[])
{
    int i=0,j=strlen(res)-1;
    char temp;
    while(i<j)
    {
        temp=res[i];
        res[i]=res[j];
        res[j]=temp;
        i++;
        j--;
    }
}

void addTwoBitStrings(char a[],char b[],int aLength,int bLength)
{
	int i=aLength-1,j=bLength-1,sum=0,carry=0;
	int resLength=max(aLength,bLength)+1;
	char res[resLength];
	int resIndex=0;
	while(i>=0||j>=0)
	{
		sum=carry+(i>=0?(a[i]-'0'):0)+(j>=0?(b[j]-'0'):0);
		carry=sum>1?1:0;
		sum=sum&1;
		res[resIndex++]=sum+'0';
		i--;
		j--;
	}
	if(carry)
		res[resIndex++]=carry+'0';
	res[resIndex++]='\0';
	reverse(res);
	printf("%s",res);
	
	
}

int main()
{
	char a[]={'1','0','1','0'};
	char b[]={'1','1','1','1'};
	int aLength=sizeof(a)/sizeof(a[0]);
	int bLength=sizeof(b)/sizeof(b[0]);
	addTwoBitStrings(a,b,aLength,bLength);
	return 0;	
}

/*Output:
11001
*/