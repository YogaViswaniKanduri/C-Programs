/* Write a program such that if a n element in an MXN matrix is 0, its entire row and column is set to zero */

#include<iostream>
#define rows 3
#define cols 4

void addZeros(int matrix[][cols])
{
	int rows_array[rows]={0};
	int cols_array[cols]={0};
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
		{
			if(matrix[i][j]==0)
			{
				rows_array[i]=1;
				cols_array[j]=1;
			}
		}
	}
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++)
		{
			if(rows_array[i]==1||cols_array[j]==1)
			{
				matrix[i][j]=0;
			}
		}
	}
}

void display(int matrix[][cols])
{
	for(int i=0;i<rows;i++)
	{
		printf("\n");
		for(int j=0;j<cols;j++)
		{
			printf("%d\t",matrix[i][j]);
		}
	}
}

int main()
{
	int matrix[rows][cols]={{1,2,0,3},{4,5,6,7},{8,9,10,11}};
	addZeros(matrix);
	display(matrix);
	return 0;
}

/*Output:

0	0	0	0	
4	5	0	7	
8	9	0	11
*/