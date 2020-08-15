#include "My_List.h"

int main()
{
	My_List list;
	list.insert_node_at_end(1);
	list.insert_node_at_end(2);
	list.insert_node_at_end(3);
	list.insert_node_at_end(4);
	list.insert_node_at_end(5);
	list.insert_node_at_end(6);
	list.insert_node_at_end(7);
	list.insert_node_at_end(8);

	int start_loop = 2;
	list.make_loop(start_loop);


	cout << "List" << endl;
	cout << list;

	Node* node_start_of_loop = list.find_start_of_loop();
	cout << "the start of loop node is with value " << node_start_of_loop->val << endl;

	getchar();
	return 0;
}