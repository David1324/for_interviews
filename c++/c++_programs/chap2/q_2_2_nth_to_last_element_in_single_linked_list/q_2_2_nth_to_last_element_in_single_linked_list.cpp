#include "My_List.h"

int main()
{
	My_List my_list;
	my_list.insert_node_at_beginning(41);
	my_list.insert_node_at_beginning(25);
	my_list.insert_node_at_beginning(15);
	my_list.insert_node_at_beginning(25);
	my_list.insert_node_at_beginning(78);
	my_list.insert_node_at_beginning(98);
	my_list.insert_node_at_beginning(21);
	my_list.insert_node_at_beginning(21);
	my_list.insert_node_at_beginning(79);
	my_list.insert_node_at_beginning(78);
	my_list.insert_node_at_end(99);
	My_List list2 = my_list;

	cout << "List with duplications" << endl;
	cout << my_list;

	int n = 4;
	Node* n_node_recursive = my_list.find_nth_to_last_element_recursively(n);
	printf("Recursive: node %d from last = %d\n", n, n_node_recursive->val);

	Node* n_node_iterative = my_list.find_nth_to_last_element_iteratively(n);
	printf("Recursive: node %d from last = %d\n", n, n_node_iterative->val);

	getchar();
	return 0;
}