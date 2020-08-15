#include "My_List.h"
#include "My_Hash.h"

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

My_List remove_duplicates_with_temporary_buffer(My_List& my_list)
{
	My_List new_list = my_list;
	My_Hash my_hash(10);

	Node* temp = new_list.get_root();
	while (temp != NULL)
	{
		int val = temp->val;
		bool is_exist = my_hash.check_is_exist(val);
		if (is_exist == false)
		{
			my_hash.insert_val(val);
		}
		else
		{
			new_list.remove(val);
		}
		temp = temp->next;
	}
	return new_list;
}


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

	cout << "list2 = \n";
	cout << list2;

	My_List list_without_duplications1 = remove_duplicates_without_temporary_buffer(my_list);
	My_List list_without_duplications2 = remove_duplicates_with_temporary_buffer(my_list);

	cout << "list_without_duplications1" << endl;
	cout << list_without_duplications1;

	cout << "list_without_duplications2" << endl;
	cout << list_without_duplications2;

	getchar();
	return 0;
}