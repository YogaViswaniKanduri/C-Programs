/* Program to detect a Hamiltonian cycle in undirected graph and directed graph
Hamiltonian path is a path in an undirected or directed graph that visits each vertex exactly once. 
A Hamiltonian cycle (or Hamiltonian circuit) is a Hamiltonian path that is a cycle.
*/
#include<stdio.h>
#define V 5
void printPath(int hpath[])
{
	printf("\nhamitonian cycle is:");
	for(int i=0;i<V;i++)
	{
		printf("\t%d",hpath[i]);		
	}
	printf("\t%d",hpath[0]);
}
bool hamiltonianCycleUtil(int graph[][V],int hpath[],bool visited[],int index)
{
	if(index==V)
	{
		if(graph[hpath[index-1]][hpath[0]]==1)
			return true;
		return false;
	}
	for(int i=0;i<V;i++)
	{
		if(visited[i]==false)
		{
			if(graph[hpath[index-1]][i]==1)
			{
				visited[i]=true;
				hpath[index]=i;
				//printf("\nadding vertex %d to hpath",i);
				if(hamiltonianCycleUtil(graph,hpath,visited,index+1))
				{
					return true;
				}
				else
				{
					visited[i]=false;
					hpath[index]=-1;
				}
			}
		}
	}
	return false;
}
void hamiltonianCycle(int graph[][V])
{
	int hpath[V]={-1};
	bool visited[V]={false};
	hpath[0]=0;
	visited[0]=true;
	/*
	Note that the above code always prints cycle starting from 0. Starting point should not matter as cycle can be started from any point.
	*/
	if(hamiltonianCycleUtil(graph,hpath,visited,1))
	{
		printf("\n the graph contains hamitonian cycle");
		printPath(hpath);
		return;
	}
	printf("\nthe graph doesn't contain hamiltonian cycle");
}
int main()
{
	/* Let us create the following graph
	  (0)--(1)--(2)
	   |   / \   |
	   |  /   \  |
	   | /     \ |
	  (3)-------(4)    */
   int graph1[V][V] = {{0, 1, 0, 1, 0},
					  {1, 0, 1, 1, 1},
					  {0, 1, 0, 0, 1},
					  {1, 1, 0, 0, 1},
					  {0, 1, 1, 1, 0},
					 };
 
	hamiltonianCycle(graph1);
	
	 
   /* Let us create the following graph
	  (0)--(1)--(2)
	   |   / \   |
	   |  /   \  |
	   | /     \ |
	  (3)       (4)    */
	int graph2[V][V] = {{0, 1, 0, 1, 0},
					  {1, 0, 1, 1, 1},
					  {0, 1, 0, 0, 1},
					  {1, 1, 0, 0, 0},
					  {0, 1, 1, 0, 0},
					 };
	hamiltonianCycle(graph2);
	return 0;
}
/*
Output:
the graph contains hamitonian cycle
hamitonian cycle is:	0	1	2	4	3	0
the graph doesn't contain hamiltonian cycle
*/	