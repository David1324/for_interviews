#include "My_Graph.h"

My_Graph::My_Graph(int num_of_vertices)
{
	this->num_of_vertices = num_of_vertices;
	for (int i = 0; i < num_of_vertices; i++)
	{
		adjacents = new list<int>[num_of_vertices];
	}
	for (int i = 0; i < num_of_vertices; i++)
	{
		visited[i] = false;
	}
}

void My_Graph::add_edge(int v1, int v2)
{
	adjacents[v1].push_back(v2);
}

list<int> My_Graph::BFS(int start_vertex)
{
	list<int> BFS_course;
	list<int> queue;
	for (int i = 0; i < num_of_vertices; i++)
	{
		visited[i] = false;
	}
	queue.push_back(start_vertex);
	visited[start_vertex] = true;
	while (!queue.empty())
	{
		int current_node = queue.front();
		queue.pop_front();
		BFS_course.push_back(current_node);

		list<int> node_adjacents = adjacents[current_node];
		list<int>::iterator i;

		for (i = node_adjacents.begin(); i != node_adjacents.end(); i++)
		{
			int current_neighbor = *i;
			bool is_visited = visited[current_neighbor];
			if (is_visited == false)
			{
				queue.push_back(current_neighbor);
				visited[current_neighbor] = true;
			}
		}

	}
	return BFS_course;
}

void My_Graph::recursive_DFS(int start_vertex, bool* visited, list<int>& DFS_course)
{
	visited[start_vertex] = true;
	DFS_course.push_back(start_vertex);
	list<int> vertex_neighbors = adjacents[start_vertex];
	list<int>::iterator i;
	for (i = vertex_neighbors.begin(); i != vertex_neighbors.end(); i++)
	{
		int current_neighbor = *i;
		bool is_visited = visited[current_neighbor];
		if (is_visited == false)
		{
			recursive_DFS(current_neighbor, visited, DFS_course);
		}
	}
}

list<int> My_Graph::DFS(int start_vertex)
{
	for (int i = 0; i < num_of_vertices; i++)
	{
		visited[i] = false;
	}

	list<int> DFS_course;
	recursive_DFS(start_vertex, visited, DFS_course);
	return DFS_course;
}

bool My_Graph::is_there_a_route(int from_node, int to_node)
{
	//list<int> BFS_course = BFS(from_node);
	//list<int>::iterator i;
	//for (i = BFS_course.begin(); i != BFS_course.end(); i++)
	//{
	//	int current_vertex = *i;
	//	if (current_vertex == to_node)
	//		return true;
	//}
	//return false;


	list<int> queue;
	for (int i = 0; i < num_of_vertices; i++)
	{
		visited[i] = false;
	}
	queue.push_back(from_node);
	visited[from_node] = true;
	while (!queue.empty())
	{
		int current_node = queue.front();
		queue.pop_front();
		if (current_node == to_node)
			return true;

		list<int> node_adjacents = adjacents[current_node];
		list<int>::iterator i;

		for (i = node_adjacents.begin(); i != node_adjacents.end(); i++)
		{
			int current_neighbor = *i;
			bool is_visited = visited[current_neighbor];
			if (is_visited == false)
			{
				queue.push_back(current_neighbor);
				visited[current_neighbor] = true;
			}
		}

	}
	return false;
}