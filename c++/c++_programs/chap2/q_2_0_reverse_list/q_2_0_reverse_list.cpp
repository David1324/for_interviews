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
	My_List my_list;
	my_list.insert_node_at_end(1);
	my_list.insert_node_at_end(2);
	my_list.insert_node_at_end(3);
	my_list.insert_node_at_end(4);
	my_list.insert_node_at_end(5);
	my_list.insert_node_at_end(6);
	My_List list2 = my_list;

	cout << "List:" << endl;
	cout << my_list;

	//my_list.reverse_list_iteratively();
	//cout << "Reversed list (iteratively):" << endl;
	//cout << my_list;

	my_list.reverse_list_recursively();
	cout << "Reversed list (recuresively):" << endl;
	cout << my_list;

	getchar();
	return 0;
}