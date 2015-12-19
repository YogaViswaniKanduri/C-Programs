/* program to detect a cycle in undirected graph 
detect a cycle in the graph using union-find algorithm
*/
#include <stdio.h>
#include <stdlib.h>
struct Edge
{
	int src;
	int des;
};
struct Graph
{
	int V;
	int E;
	struct Edge * edges;
};
struct Graph * createGraph(int V, int E)
{
	struct Graph * g = (struct Graph *)malloc(sizeof(struct Graph));
	g->V=V;
	g->E=E;
	g->edges = (struct Edge *)malloc(E*(sizeof(struct Edge)));
	return g;
}
void display(struct Graph * g)
{
	for(int i=0;i<g->E;i++)
	{
		printf("\n%d -- %d",g->edges[i].src,g->edges[i].des);
	}
}
int find(int parent[],int ver)
{
	if(parent[ver]==-1)
		return ver;
	return find(parent,parent[ver]);
}
void unionOfSets(int parent[],int set1, int set2)
{
	parent[set1]=set2;
}
bool isCycle(struct Graph * g)
{
	int parent[g->V];
	for (int j=0;j<g->V;j++)
	{
	    parent[j]=-1;
	}
	for(int i=0; i<g->E; i++)
	{
		int set1=find(parent,g->edges[i].src);
		int set2=find(parent,g->edges[i].des);
		if(set1==set2)
			return true;
		unionOfSets(parent,set1,set2);
	}
	return false;
}
int main()
{
	struct Graph * g = createGraph(3,3);	
	g->edges[0].src=0;
	g->edges[0].des=1;
	
	g->edges[1].src=1;
	g->edges[1].des=2;
	
	g->edges[2].src=2;
	g->edges[2].des=0;
	
	display(g);	
	
	if(isCycle(g))
	{
		printf("\nGraph contains cycle.");
	}
	else
	{
		printf("\nGraph doesn't contain a cycle.");
	}
	return 0;
}
/* Output:
0 -- 1
1 -- 2
2 -- 0
Graph contains cycle.
*/ 