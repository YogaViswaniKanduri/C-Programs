/* Program to convert integers into English phrases
Integer datatype only accepts values till 999,999,999 */
#include<stdio.h>
char englishPhrase1[][15]={"","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
char englishPhrase2[][10]={"","","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
void printNum(int num,char a[],char b[])
{
	if(num!=0)
	{
		if(num>99)
		{
			printf("%s %s ",englishPhrase1[num/100],a);
			num=num%100;
		}
		num<=19? printf("%s ",englishPhrase1[num]): printf("%s %s ",englishPhrase2[num/10],englishPhrase1[num%10]);
		printf("%s ",b);
	}	
}
void printEnglishPhrase(int num)
{
	if(num<0)
	{
		printf("\nInvalid input");
	}
	if(num==0)
	{
		printf("zero");
		return;
	}	
	printNum((num/1000000),"hundred","million");	
	printNum((num%1000000)/1000,"hundred","thousand");
	printNum((num%1000),"hundred","");
	
}

int main()
{
	int num=999999999;     // 999,999,999
	printf("%d\n",num);
	printEnglishPhrase(num);
	return 0;
}
/*Output:
999999999
nine hundred ninety nine million nine hundred ninety nine thousand nine hundred ninety nine
800000009
eight hundred  million nine  	
*/




