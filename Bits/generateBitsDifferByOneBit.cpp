/* Program to generate gray codes for n bits. Given n generate bit patterns from 0 to 2^n-1 such that succesive patterns differ by one bit
Algorithm:

		Loop from 0 to 2^n-1
	for each i
		int num=(i>>1) xor i  
		print(num)
		
Time complexity: 0(2^n-1) because for loop executes 2^n-1 times ignoring print number in bits complexity
*/

#include<iostream>
using namespace std;

void printNumber(int num,int n)
{
	printf("\n");
	int j;
	for(int i=n;i>0;i--)
	{
	     j=num&(1<<(i-1));
	     cout<<(j?1:0);
	}
	
}

void generateBitsDifferByOneBit(int n)
{
	int num;
	for(int i=0;i< (1<<n); i++)
	{
		num=i^(i>>1);
		printNumber(num,n);
	}
}

int main()
{
    int n;
    cin>>n;
	generateBitsDifferByOneBit(n);
	return 0;
}

/*Output: 
for n=3
000
001
011
010
110
111
101
100
*/