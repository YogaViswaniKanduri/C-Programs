/*Program to detect a cycle in an undirected graph using union by rank and path compression technique
Complexity = O(log n) in worst case
 */
#include<stdio.h>
#include<stdlib.h>
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
struct subset
{
	int rank;
	int parent;
};
struct Graph * createGraph(int V, int E)
{
	struct Graph * g = (struct Graph *)malloc(sizeof(struct Graph));
	g->V=V;
	g->E=E;
	g->edges=(struct Edge *)malloc(E*sizeof(struct Edge));
	return g;
}
int find(struct subset * s, int v)
{
	if(s[v].parent == v)
	{
		return v;
	}
	else
	{
		return find(s,s[v].parent);
	}	
}
void unionOfSets(struct subset * s,int x, int y)
{
	if(s[x].rank>s[y].rank)
	{
		s[y].parent=x;
	}
	else if(s[x].rank<s[y].rank)
	{
		s[x].parent=y;
	}
	else
	{
		s[y].parent = x;
		s[x].rank++;
	}
}
bool isCycle(struct Graph * g)
{
	struct subset * s=(struct subset *)malloc(g->V * sizeof(struct subset));
	for(int i=0;i<g->V;i++)
	{
		s[i].parent=i;
		s[i].rank=0;		
	}
	for(int j=0;j<g->E;j++)
	{
		int x = find(s,g->edges[j].src);
		int y = find(s,g->edges[j].des);
		if(x==y)
		{
			return true;
		}
		unionOfSets(s,x,y);
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
	
	if(isCycle(g))
	{
		printf("\nGraph contains cycle.");
	}
	else
	{
		printf("\nGraph doesn't contain cycle.");
	}
	return 0;	
}
/*
Output:
Graph contains cycle.
/*
