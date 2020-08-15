#include <list>

using std::list;


class My_Graph
{
private:
	int num_of_vertices;
	list<int>* adjacents;
	bool* visited = new bool[num_of_vertices];
	void recursive_DFS(int start_vertex, bool* visited, list<int>& DFS_course);

public:
	My_Graph(int num_of_vertices);
	void add_edge(int v1, int v2);
	list<int> BFS(int start_vertex);	
	list<int> DFS(int start_vertex);
};
