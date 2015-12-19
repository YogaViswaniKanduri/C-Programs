/*Program to print interleavings of two strings
str1="AB";
str2="CD";
interleavings: (order remains same)
ABCD
ACBD
ACDB
CABD
CADB
CDAB
Complexity=O(2^(m+n))
*/
#include<stdio.h>
#include<string.h>
void printInterleavings(char a[], char b[], int i1, int i2, int len1, int len2, char ab[], int index, int totalLen)
{
	if(index==totalLen)
	{
		printf("%s\n",ab);
		return;
	}
	if(i1<len1)
	{
		ab[index]=a[i1];
		printInterleavings(a,b,i1+1,i2,len1,len2,ab,index+1,totalLen);		
	}
	if(i2<len2)
	{
		ab[index]=b[i2];
		printInterleavings(a,b,i1,i2+1,len1,len2,ab,index+1,totalLen);		
	}
}
int main()
{
	char *a="AB";
	char *b="CD";
	int len1=strlen(a);
	int len2=strlen(b);
	int totalLen=len1+len2;
	char *ab=new char[totalLen];
	printInterleavings(a,b,0,0,len1,len2,ab,0,totalLen);
	return 0;	
}

/**/
#include <iostream>
#include <string.h>
using namespace std;


void printInterleaving(char * str1, char * str2,char *c,int index,int copy)
{
  if(!*str1 && !*str2)
  {
    c[index]='\0';
    printf("%s\n",c);
    return;
  }
  if(*str1 && !copy)
  {
    c[index]=*str1;
    printInterleaving(str1+1,str2,c,index+1,copy);
  }
  if(*str2)
  {
    copy=0;
    if(*str1 && *str1==*str2)
    {
      copy++;
    }
    c[index]=*str2;
    printInterleaving(str1,str2+1,c,index+1,copy);
    
  }
}

int main() {
  char str1[]="AB";
  char str2[]="AD";
  int len= strlen(str1)+strlen(str2);
  char *c=new char[len];
  printInterleaving(str1,str2,c,0,0);
  return 0;
}

