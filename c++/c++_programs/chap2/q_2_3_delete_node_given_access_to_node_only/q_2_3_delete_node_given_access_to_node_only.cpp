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

	int n = 2;
	Node* node_to_delete = my_list.find_nth_to_last_element_recursively(n);
	printf("Recursive: node %d from last = %d (this is the node to delete)\n", n, node_to_delete->val);

	my_list.remove_given_node_only(node_to_delete);

	cout << "List after deletion" << endl;
	cout << my_list;

	getchar();
	return 0;
}