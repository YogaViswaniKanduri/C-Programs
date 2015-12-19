/*cutting problem of dynamic programming
This is based on the technique B(n)=max(max_value,price[j]+B(n-j-1)) where j is iterated upto n-1
Complexity is O(n^2).
This is my own algorithm.
*/
#include<stdio.h>
#include<limits.h>
int max(int a, int b)
{
	return a>b? a:b;
}
int cutRod(int prices[],int n)
{
	int bestRodValues[n+1];
	bestRodValues[0]=0;
	int max_value;
	for(int i=1;i<=n;i++)
	{	
		max_value=INT_MIN;
		for(int j=0;j<i;j++)
		{
			max_value = max(max_value,prices[j]+bestRodValues[i-j-1]);
		}
		bestRodValues[i]=max_value;
	}
	return bestRodValues[n];
}
int main()
{
	int prices[]={1, 5, 8, 9, 10, 17, 17, 20};
	int n=sizeof(prices)/sizeof(prices[0]);
	printf("\nThe maximum obtainable value is: %d",cutRod(prices,n));
	//Second example:
	int prices2[]={1, 10, 18, 20};
	int n2=sizeof(prices2)/sizeof(prices2[0]);
	printf("\nThe maximum obtainable value is: %d",cutRod(prices2,n2));
	return 0;
}
/*
Output:
The maximum obtainable value is: 22
The maximum obtainable value is: 20
*/