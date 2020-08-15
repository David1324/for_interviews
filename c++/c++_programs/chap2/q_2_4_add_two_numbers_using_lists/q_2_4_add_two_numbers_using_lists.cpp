#include "My_List.h"

int main()
{
	My_List list1;
	list1.insert_node_at_end(3);
	list1.insert_node_at_end(1);
	list1.insert_node_at_end(5);
	My_List list2;
	list2.insert_node_at_end(5);
	list2.insert_node_at_end(9);
	list2.insert_node_at_end(2);

	cout << "List1" << endl;
	cout << list1;

	cout << "List2" << endl;
	cout << list2;

	My_List* list3 = add_two_lists(list1, list2);

	cout << "List3" << endl;
	cout << *list3;

	getchar();
	return 0;
}