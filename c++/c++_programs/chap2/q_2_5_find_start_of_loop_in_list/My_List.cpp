#include "My_List.h"

My_List::My_List()
{
	root = NULL;
}

My_List::~My_List()
{
	Node* temp = root;
	while (temp != NULL)
	{
		Node* next = temp->next;
		delete temp;
		temp = next;
	}
}

Node* My_List::get_root()
{
	return root;
}

void My_List::insert_node_at_beginning(int val)
{
	Node* new_node = new Node();
	new_node->val = val;

	if (root == NULL)
	{
		root = new_node;
		root->next = NULL;
	}
	else
	{
		Node* temp = root;
		root = new_node;
		new_node->next = temp;
	}
}

void My_List::insert_node_at_end(int val)
{
	Node* new_node = new Node();
	new_node->val = val;

	if (root == NULL)
	{
		root = new_node;
		root->next = NULL;
	}
	else
	{
		Node* temp = root;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new_node;
		new_node->next = NULL;
	}
}

Node* My_List::find_node(int val)
{
	Node* temp = root;
	while (temp != NULL)
	{
		if (temp->val == val)
		{
			return temp;
		}
		else
		{
			temp = temp->next;
		}
	}
	return NULL;
}

void My_List::remove(int val)
{
	Node* node_to_remove = find_node(val);
	if (node_to_remove != NULL)
	{
		if (node_to_remove == root)
			root = root->next;
		else
		{
			Node* temp = root;
			while (temp->next != node_to_remove)
				temp = temp->next;
			temp->next = temp->next->next;
		}
		delete node_to_remove;
	}
}

ostream& operator<<(ostream& os, const My_List& list)
{
	int max_steps = 20;
	int counter = 0;
	Node* temp = list.root;
	os << "List values:\n";
	while (temp != NULL && counter<max_steps)
	{
		os << temp->val << ", ";
		temp = temp->next;
		counter++;
	}
	os << "\n\n";
	return os;
}

My_List::My_List(const My_List& my_list)
{
	Node* temp = my_list.root;
	while (temp != NULL)
	{
		insert_node_at_end(temp->val);
		temp = temp->next;
	}
}

Node* My_List::helper_find_nth_to_last_element(Node* root, int n, int& location)
{
	if (root == NULL)
	{
		location = 0;
		return NULL;
	}
	else
	{
		Node* node = helper_find_nth_to_last_element(root->next, n, location);
		if (location == n)
		{
			location++;
			return root->next;
		}
		else if (location > n)
		{
			return node;
		}
		location++;
	}
	return NULL;
}

Node* My_List::find_nth_to_last_element_recursively(int n)
{
	int location;
	Node* node = helper_find_nth_to_last_element(root, n, location);
	return node;
}

Node* My_List::find_nth_to_last_element_iteratively(int n)
{
	Node* p1 = root;
	Node* p2 = root;
	for (int i = 0; i < n; i++)
	{
		if (p2 == NULL) return NULL;
		p2 = p2->next;
	}
	while (p2 != NULL)
	{
		p1 = p1->next;
		p2 = p2->next;
	}
	return p1;
}

void My_List::remove_given_node_only(Node* &node_to_delete)
{
	Node* next_node = node_to_delete->next;
	if (next_node == NULL)
	{
		throw "Cannot delete last element";
		return;
	}
	else
	{
		node_to_delete->val = next_node->val;
		node_to_delete->next = next_node->next;
		delete next_node;
	}
}

//My_List* helper_add_two_lists(Node* root1, Node* root2, int& carry)
//{
//	if (root1 == NULL) //we assume that if root1==NULL then also root2==NULL
//	{
//		return new My_List();
//	}
//	else
//	{
//		My_List* current_result_list = helper_add_two_lists(root1->next, root2->next, carry);
//		int result_val = root1->val + root2->val + carry;
//		if (result_val >= 10)
//		{
//			carry = 1;
//			result_val = result_val - 10;
//		}
//		else
//		{
//			carry = 0;
//		}
//		current_result_list->insert_node_at_beginning(result_val);
//		return current_result_list;
//	}
//}

My_List* helper_add_two_lists(Node* root1, Node* root2, int& carry)
{
	if (root1 == NULL) //we assume that if root1==NULL then also root2==NULL
	{
		return new My_List();
	}
	int result_val = root1->val + root2->val + carry;
	if (result_val >= 10)
	{
		carry = 1;
		result_val = result_val - 10;
	}
	else
	{
		carry = 0;
	}
	My_List* current_result_list = helper_add_two_lists(root1->next, root2->next, carry);
	current_result_list->insert_node_at_beginning(result_val);
	return current_result_list;
}

My_List* add_two_lists(My_List const& list1, My_List const& list2)
{
	int carry = 0;
	Node* root1 = list1.root;
	Node* root2 = list2.root;
	My_List* result_list = helper_add_two_lists(root1, root2, carry);
	return result_list;
}

void My_List::make_loop(int start_loop)
{
	Node* last_node = root;
	while (last_node->next != NULL)
		last_node = last_node->next;

	Node* node_starting_loop = root;
	for (int i = 0; i < start_loop; i++)
	{
		node_starting_loop = node_starting_loop->next;
	}

	last_node->next = node_starting_loop;
}

Node* My_List::find_start_of_loop()
{
	Node* slow_pointer = root;
	Node* fast_pointer = root;

	while (1)
	{
		slow_pointer = slow_pointer->next;
		fast_pointer = fast_pointer->next->next;
		if (slow_pointer == fast_pointer)
			break;
	}

	slow_pointer = root;
	while (slow_pointer != fast_pointer)
	{
		slow_pointer = slow_pointer->next;
		fast_pointer = fast_pointer->next;
	}
	return slow_pointer;
}