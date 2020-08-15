#include "Node.h"
#include <stdio.h>

template <class T>
void Node<T>::Swap(Node* currentNode)
{
	if (currentNode != NULL)
	{
		currentNode->Swap(currentNode->m_pNext);
		currentNode->m_pNext = this;
	}
}

template <class T>
Node<T>* Node<T>::GetNext()
{
	return this->m_pNext;
}

template <class T>
void Node<T>::SetNext(Node* nextNode)
{
	this->m_pNext = nextNode;
}

template <class T>
T Node<T>::GetVal()
{
	return this->val;
}

template <class T>
void Node<T>::SetVal(T value)
{
	this->val = value;
}

template <class T>
Node<T>::Node()
{
	this->val = -1;
	this->m_pNext = NULL;
}

template <class T>
Node<T>::Node(T value)
{
	this->val = value;
	this->m_pNext = NULL;
}
