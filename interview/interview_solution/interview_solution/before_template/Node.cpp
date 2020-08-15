#include "Node.h"
#include <stdio.h>

void Node::Swap(Node* currentNode)
{
	if (currentNode != NULL)
	{
		currentNode->Swap(currentNode->m_pNext);
		currentNode->m_pNext = this;
	}
}

Node* Node::GetNext()
{
	return this->m_pNext;
}

void Node::SetNext(Node* nextNode)
{
	this->m_pNext = nextNode;
}

int Node::GetVal()
{
	return this->val;
}

void Node::SetVal(int value)
{
	this->val = value;
}

Node::Node()
{
	this->val = -1;
	this->m_pNext = NULL;
}

Node::Node(int value)
{
	this->val = value;
	this->m_pNext = NULL;
}
