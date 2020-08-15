#include "Node.h"


Node::Node(int val)
{
	this->value = val;
}

void Node::set_next(Node* next)
{
	this->next = next;
}

void Node::set_value(int value)
{
	this->value = value;
}

Node* Node::get_next()
{
	return this->next;
}

int Node::get_value()
{
	return this->value;
}

void Node::reverse_node(Node* node)
{
	if (node != NULL)
	{
		node->reverse_node(node->get_next());
		node->set_next(this);
	}
}


