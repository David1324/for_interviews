#include "My_List.h"

My_List remove_duplicates_without_temporary_buffer(My_List& my_list)
{
	My_List new_list = my_list;
	Node* temp = new_list.get_root();

	Node* prev = new_list.get_root();
	while (prev != NULL)
	{
		Node* current = prev;
		while (current->next != NULL)
		{
			if (prev->val == current->next->val)
			{
				Node* temp = current->next;
				current->next = current->next->next;
				delete temp;
			}
			else
			{
				current = current->next;
			}
		}
		prev = prev->next;
	}
	return new_list;
}




int main()
{
	//My_List list1;
	//list1.insert_node_at_end(1);
	//list1.insert_node_at_end(2);
	//list1.insert_node_at_end(3);
	//

	//My_List list2;
	//list2.insert_node_at_end(4);
	//list2.insert_node_at_end(5);

	//My_List list3 = list2;

	//int sum = list1.sum_lists_into_integer(&list2);
	//My_List sum_lists = list1.sum_lists_into_list(&list2);

	//cout << "list1:" << endl;
	//cout << list1 << endl;

	//cout << "list2:" << endl;
	//cout << list2 << endl;

	//cout << "sum = " << sum << endl;

	//cout << "sum_lists:" << endl;
	//cout << sum_lists << endl;

	My_List list5;
	list5.insert_node_at_end(1);
	list5.insert_node_at_end(2);
	list5.insert_node_at_end(3);
	list5.insert_node_at_end(4);
	list5.insert_node_at_end(5);
	list5.insert_node_at_end(6);
	list5.insert_node_at_end(7);
	list5.insert_node_at_end(8);

	list5.zigzag_list();

	

	//list1.reverse_list_iteratively();
	//cout << "Reversed list (iteratively):" << endl;
	//cout << list1;

	//list1.reverse_list_recursively();
	//cout << "Reversed list (recuresively):" << endl;
	//cout << list1;

	getchar();
	return 0;
}