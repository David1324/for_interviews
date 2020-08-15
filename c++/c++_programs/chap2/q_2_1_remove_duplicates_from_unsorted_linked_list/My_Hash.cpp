#include "My_Hash.h"

My_Hash::My_Hash(int max_size)
{
	this->max_size = max_size;
	for (int i = 0; i < max_size; i++)
	{
		vec.push_back(new My_List());
	}
}

int My_Hash::hash_func(int val)
{
	int new_val = val % max_size;
	return new_val;
}

bool My_Hash::check_is_exist(int val)
{
	int index = hash_func(val);
	My_List* current_list = vec[index];
	Node* val_node = current_list->find_node(val);
	if (val_node == NULL)
		return false;
	return true;
}

void My_Hash::insert_val(int val)
{
	bool is_exist = check_is_exist(val);
	if (is_exist == false)
	{
		int index = hash_func(val);
		vec[index]->insert_node_at_beginning(val);
	}
}

My_Hash::~My_Hash()
{
	for (int i = 0; i < max_size; i++)
	{
		delete vec[i];
	}
}