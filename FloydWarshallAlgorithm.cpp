/* program to find all pairs shortest paths using Floyd-warshall algorithm
Time complexity is O(v^3)
Can be used for both positive and negative edge weights but no negative cycles.
The algorithm gives only shortest distances. We can print by using the predecessor matrix.
*/
#include<stdio.h>
#include<limits.h>
#define INF INT_MAX
#define v 4
void floydWarshall(int input[][v],int output[][v],int predecessor[][v])
{
	for(int k=0;k<v;k++)
	{
		for(int i=0;i<v;i++)
		{
			for(int j=0;j<v;j++)
			{
				if(output[i][k]!=INF && output[k][j]!=INF && output[i][j] > output[i][k] + output[k][j])
				{
					output[i][j] = output[i][k]+output[k][j];
					predecessor[i][j] = k;
				}
			}
		}
	}
}
void print_shortest_path(int predecessor[][v], int i, int j)
{
	int x= predecessor[i][j];
	if(x==INF)
	{
		printf("\nNo path from %d to %d",i,j);
		return;
	}
	if(i==x || j==x)
	{
		printf("\t%d",x);
		return;
	}
		
	else
	{
		print_shortest_path(predecessor,i,x);
		print_shortest_path(predecessor,x,j);	
	}

}
int main()
{
	int input[v][v]={{0,8,INF,1},{INF,0,1,INF},{4,INF,0,INF},{INF,2,9,0}};
	int output[v][v];
	int predecessor[v][v];
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			output[i][j]=input[i][j];
			if(input[i][j]==INF)
			{
				predecessor[i][j]=INF;
			}
			else
			{
				predecessor[i][j]=i;
			}
		}
	}
	floydWarshall(input,output,predecessor);
	//Display all pairs shortest distances
	printf("\nShortest distances\n");
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			printf("\t%d",output[i][j]);			
		}
		printf("\n");
	}
	//Display predecessor matrix
	printf("\nPredecessor Matrix\n");
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			printf("\t%d",predecessor[i][j]);			
		}
		printf("\n");
	}
	
	printf("\nPrint the shortest paths:");
	for(int i=0;i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			printf("\nShortest path from %d to %d: ",i,j);
			if(predecessor[i][j]==INF)
			{
			    printf("No path exists from %d to %d", i,j);
			}
			else
			{
			    print_shortest_path(predecessor,i,j);
			    if(i!=j)
			        printf("\t%d",j);
			}
		}
	}
	return 0;
}
/*
Output:
Shortest distances
	0	3	4	1
	5	0	1	6
	4	7	0	5
	7	2	3	0

Predecessor Matrix
	0	3	3	0
	2	1	1	2
	2	3	2	0
	2	3	1	3

Print the shortest paths:
Shortest path from 0 to 0: 	0
Shortest path from 0 to 1: 	0	3	1
Shortest path from 0 to 2: 	0	3	1	2
Shortest path from 0 to 3: 	0	3
Shortest path from 1 to 0: 	1	2	0
Shortest path from 1 to 1: 	1
Shortest path from 1 to 2: 	1	2
Shortest path from 1 to 3: 	1	2	0	3
Shortest path from 2 to 0: 	2	0
Shortest path from 2 to 1: 	2	0	3	1
Shortest path from 2 to 2: 	2
Shortest path from 2 to 3: 	2	0	3
Shortest path from 3 to 0: 	3	1	2	0
Shortest path from 3 to 1: 	3	1
Shortest path from 3 to 2: 	3	1	2
Shortest path from 3 to 3: 	3
*/