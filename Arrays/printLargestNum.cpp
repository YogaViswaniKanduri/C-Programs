/* Given a number print the largest number that can be formed with the given numbers. Duplicates are allowed.*/

#include<iostream>
using namespace std;

int printLargestNum(int num)
{
	int res=0;
	int table[10]={0};
	while(num)
	{
		table[num%10]++;
		num=num/10;
	}
	for(int i=9;i>=0;i--)
	{
		while(table[i])
		{
			res=res*10+i;
			table[i]--;
		}
	}
	return res;
}

int main()
{
	int num=23987619;
	cout<<printLargestNum(num);
	return 0;
}
/*output: 99876321
*/
