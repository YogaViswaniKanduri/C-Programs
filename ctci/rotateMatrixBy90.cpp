/* Program to rotate the matrix by 90 degrees */

#include<iostream>
#define N 5

void display(int matrix[][N])
{
	for(int i=0;i<N;i++)
	{
		printf("\n");
		for(int j=0;j<N;j++)
			printf("%d\t",matrix[i][j]);
	}
}

void rotateMatrix(int matrix[][N], int start, int end, int layer)
{
	//if(layer==1)
	//	return;
	if(start>=end) return;
	int temp,offset;
	for(int i=start;i<end;i++)
	{
	    offset=i-start;
		temp=matrix[start][i];
		matrix[start][i]=matrix[end-offset][start];
		matrix[end-offset][start]=matrix[end][end-offset];
		matrix[end][end-offset]=matrix[i][end];
		matrix[i][end]=temp;
	}
	rotateMatrix(matrix,++start,--end,layer/2);
}


int main()
{
	int matrix[][N]={{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};
	rotateMatrix(matrix,0,N-1,N);
	display(matrix);
	return 0;
}
/*Output:

21	16	11	6	1	
22	17	12	7	2	
23	18	13	8	3	
24	19	14	9	4	
25	20	15	10	5
*/