
#include <iostream>
#include "My_Graph.h"

using std::cout;
using std::endl;



int main()
{
	My_Graph* graph = new My_Graph(4);
	graph->add_edge(0, 1);
	graph->add_edge(0, 2);
	graph->add_edge(1, 2);
	graph->add_edge(2, 0);
	graph->add_edge(2, 3);
	graph->add_edge(3, 3);

	list<int> BFS_course = graph->BFS(2);

	cout << "BFS course:" << endl;
	for (list<int>::iterator i = BFS_course.begin(); i != BFS_course.end(); i++)
	{
		cout << *i << ", ";
	}
	cout << endl;

	cout << "\n\n";

	list<int> DFS_course = graph->DFS(2);

	cout << "DFS course:" << endl;
	for (list<int>::iterator i = DFS_course.begin(); i != DFS_course.end(); i++)
	{
		cout << *i << ", ";
	}
	cout << endl;

	getchar();
	return 0;
}