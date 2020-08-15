#include "List.h"

void List::insert_after_last(int val)
{
	Node* new_node = new Node(val);
	new_node->set_next(NULL);
	if (tail == NULL)
	{
		head = new_node;
		tail = new_node;
	}
	else
	{
		tail->set_next(new_node);
		tail = new_node;
	}
}

ostream& operator<<(ostream& os, const List& list)
{
	Node* temp = list.head;
	while (temp != NULL)
	{
		int value = temp->get_value();
		os << value << ", ";
		temp = temp->get_next();
	}
	os << "\n\n\n";
	return os;
}

void List::reverse()
{
	if (head != NULL)
	{
		head->reverse_node(head->get_next());
	}
	
	head->set_next(NULL);
	Node* temp = head;
	head = tail;
	tail = temp;
}