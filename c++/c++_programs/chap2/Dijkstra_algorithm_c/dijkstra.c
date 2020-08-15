#include<stdio.h>
#include<conio.h>
#define INFINITY 9999
#define MAX 9

void dijkstra(int G[MAX][MAX], int n, int startnode)
{

	int cost[MAX][MAX], distance[MAX], pred[MAX];
	int visited[MAX], count, min_distance, next_node, i, j;

	//pred[] stores the predecessor of each node
	//count gives the number of nodes seen so far
	//create the cost matrix
	for (i = 0; i<n; i++)
		for (j = 0; j<n; j++)
			if (G[i][j] == 0)
				cost[i][j] = INFINITY;
			else
				cost[i][j] = G[i][j];

	//initialize pred[],distance[] and visited[]
	for (i = 0; i<n; i++)
	{
		distance[i] = cost[startnode][i];
		pred[i] = startnode;
		visited[i] = 0;
	}

	distance[startnode] = 0;
	visited[startnode] = 1;
	count = 1;

	while (count<n - 1)
	{
		min_distance = INFINITY;

		//nextnode gives the node at minimum distance
		for (i = 0; i<n; i++)
			if (distance[i]<min_distance && !visited[i])
			{
				min_distance = distance[i];
				next_node = i;
			}

		//check if a better path exists through nextnode            
		visited[next_node] = 1;
		for (i = 0; i<n; i++)
			if (!visited[i])
				if (min_distance + cost[next_node][i]<distance[i])
				{
					distance[i] = min_distance + cost[next_node][i];
					pred[i] = next_node;
				}
		count++;
	}

	//print the path and distance of each node
	for (i = 0; i<n; i++)
		if (i != startnode)
		{
			printf("\nDistance of node%d=%d", i, distance[i]);
			printf("\nPath=%d", i);

			j = i;
			do
			{
				j = pred[j];
				printf("<-%d", j);
			} while (j != startnode);
		}
}

int main()
{
	int G[MAX][MAX] =
	{ 
	{ 0, 4, 0, 0, 0, 0, 0, 8, 0 },
	{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
	{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
	{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
	{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
	{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
	{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
	{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
	{ 0, 0, 2, 0, 0, 0, 6, 7, 0 }
	};


	int u = 0;
	dijkstra(G, MAX, u);
	getchar();
	return 0;
}

