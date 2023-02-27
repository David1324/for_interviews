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
	root = NULL;
	while (temp != NULL)
	{
		insert_node_at_end(temp->val);
		temp = temp->next;
	}
}

void My_List::reverse_list_iteratively()
{
	Node* current = root;
	Node* prev = NULL;
	while (current != NULL)
	{
		root = current;
		Node* temp = current->next;
		current->next = prev;
		prev = current;
		current = temp;
	}
}

void My_List::helper_reverse_list_recursively(Node* &root)
{
	if (root == NULL)
		return;
	Node* rest = root->next;
	if (rest == NULL)
		return;
	helper_reverse_list_recursively(rest);
	root->next->next = root;
	root->next = NULL;
	root = rest;
}

//void My_List::helper_reverse_list_recursively(Node* &head)
//{
//	Node* first;
//	Node* rest;
//
//	/* empty list */
//	if (head == NULL)
//		return;
//
//	/* suppose first = {1, 2, 3}, rest = {2, 3} */
//	first = head;
//	rest = first->next;
//
//	/* List has only one node */
//	if (rest == NULL)
//		return;
//
//	/* reverse the rest list and put the first element at the end */
//	helper_reverse_list_recursively(rest);
//	
//	//currenty first->next->next is NULL since first->next is the last node of the reversed rest
//	//we change it to point to first instead of NULL and then we change 'first' to point to NULL since
//	//this is the new last node of the current list
//	first->next->next = first; 
//
//	/* tricky step -- see the diagram */
//	first->next = NULL;
//
//	/* fix the head pointer */
//	head = rest;
//}

void My_List::reverse_list_recursively()
{
	helper_reverse_list_recursively(root);
}

My_List My_List::sum_lists_into_list(My_List* list2)
{
	My_List sum_lists;
	My_List reversed_list1 = *this; //copy constructor
	My_List reversed_list2 = *list2; //copy constructor
	reversed_list1.reverse_list_recursively();
	reversed_list2.reverse_list_recursively();
	Node* node1 = reversed_list1.root;
	Node* node2 = reversed_list2.root;
	int carrier = 0;
	while (node1 != NULL && node2 != NULL)
	{
		int current_sum = node1->val + node2->val + carrier;
		int remainder = current_sum % 10;
		sum_lists.insert_node_at_beginning(remainder);
		carrier = current_sum / 10;
		node1 = node1->next;
		node2 = node2->next;
	}

	while (node1 != NULL)
	{
		int current_sum = node1->val + carrier;
		int remainder = current_sum % 10;
		sum_lists.insert_node_at_beginning(remainder);
		carrier = current_sum / 10;
		node1 = node1->next;
	}

	while (node2 != NULL)
	{
		int current_sum = node2->val + carrier;
		int remainder = current_sum % 10;
		sum_lists.insert_node_at_beginning(remainder);
		carrier = current_sum / 10;
		node2 = node2->next;
	}

	return sum_lists;
}

int My_List::sum_lists_into_integer(My_List* list2)
{
	My_List reversed_list1 = *this; //copy constructor
	My_List reversed_list2 = *list2; //copy constructor
	reversed_list1.reverse_list_recursively();
	reversed_list2.reverse_list_recursively();
	Node* node1 = reversed_list1.root;
	Node* node2 = reversed_list2.root;
	int sum = 0;
	int base = 1;
	while (node1 != NULL && node2 != NULL)
	{
		sum += base * (node1->val + node2->val);
		base *= 10;
		node1 = node1->next;
		node2 = node2->next;
	}

	while (node1 != NULL)
	{
		sum += base * node1->val;
		base *= 10;
		node1 = node1->next;
	}

	while (node2 != NULL)
	{
		sum += base * node2->val;
		base *= 10;
		node2 = node2->next;
	}

	return sum;
}

int My_List::get_length()
{
	int length = 0;
	Node* temp = root;
	while (temp != NULL)
	{
		length++;
		temp = temp->next;
	}
	return length;
}



void My_List::zigzag_list()
{
	int length = get_length();
	int half_length = length / 2;
	Node* half_node = root;
	Node* node_before_half_node = NULL;
	for (int i = 0; i < half_length; i++)
	{
		node_before_half_node = half_node;
		half_node = half_node->next;
	}
	helper_reverse_list_recursively(half_node);
	if (node_before_half_node != NULL)
	{
		node_before_half_node->next = half_node;
	}

	cout << "list with second half reversed:" << endl;
	cout << *this << endl;


}