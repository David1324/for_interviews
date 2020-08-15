#include "My_Stack.h"

My_Stack::My_Stack()
{
	top = NULL;
}

void My_Stack::push(int val)
{
	Node* new_node = new Node();
	new_node->val = val;

	if (top == NULL)
	{
		top = new_node;
		top->next = NULL;
	}
	else
	{
		Node* temp = top;
		top = new_node;
		top->next = temp;
	}
}

int My_Stack::pop()
{
	int val = top->val;
	Node* temp = top;
	top = top->next;
	delete temp;
	return val;
}