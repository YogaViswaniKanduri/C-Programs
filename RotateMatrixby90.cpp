/* Program to rotate matrix by 90*/
#include<stdio.h>
#define N 4
void rotate(int matrix[][N],int start, int end, int layer)
{
	if(layer==1)
		return;
	for(int i=start;i<end;i++)
	{
		int temp = matrix[start][start+i];
		matrix[start][start+i]=matrix[end-i][start];
		matrix[end-i][start]=matrix[end][end-i];
		matrix[end][end-i]=matrix[start+i][end];
		matrix[start+i][end]=temp;
		
	}
	rotate(matrix,++start,--end,layer/2);
}
void rotate90degrees(int matrix[][N])
{
	rotate(matrix,0,N-1,N);	
}
void display(int matrix[][N])
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			printf("%d\t",matrix[i][j]);
		}	
		printf("\n");
	}
}
int main()
{
	int matrix[][N]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
	rotate90degrees(matrix);
	display(matrix);
	return 0;
}
/*
Output:
13	9	5	1	
14	10	6	2	
15	11	7	3	
16	12	8	4
*/