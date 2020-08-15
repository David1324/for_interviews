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
	Node* temp = list.root;
	os << "List values:\n";
	while (temp != NULL)
	{
		os << temp->val << ", ";
		temp = temp->next;
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

