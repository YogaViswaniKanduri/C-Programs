/* program to print the number of binary search trees possible with n nodes
Youtube video = https://www.youtube.com/watch?v=UfA_v0VmiDg
Link = http://cslibrary.stanford.edu/110/BinaryTrees.html
*/

#include<stdio.h>
#include<stdlib.h>
int countTrees(int num)
{
    int sum=0;
	if(num==0||num==1)
	{
		return 1;
	}
	
	
	else 
	{
		int left,right;
		for(int i=1;i<=num;i++)
		{
			left=countTrees(i-1);
			right=countTrees(num-i);
			sum=sum+ left*right;
		}
		
	}
	return sum;
}
/*iterative solution*/
int countBST(int num)
{
	int *a=new int[num+1];
	a[0]=1;
	a[1]=1;
	for(int i=2;i<=num;i++)
	{
		for(int j=0;j<i;j++)
		{
			a[i]=a[i]+ (a[j]*a[i-j-1]);
		}
	}
	return a[num];
}

int main()
{
	int n=3;
	printf("\nnumber of binary search trees possible for %d nodes: %d",n,countTrees(n));
	printf("\nnumber of binary search trees possible for %d nodes: %d",n,countBST(n));
	getchar();
	return 0;
}
/*
Output:
number of binary search trees possible for 3 nodes: 5
number of binary search trees possible for 3 nodes: 5
*/