#pragma once

template <class T>
class Node
{
private:
	T val;
	Node* m_pNext;

public:
	Node();
	Node(T value);
	void Swap(Node* pNext);
	void Reverse();
	Node* GetNext();
	void SetNext(Node*);

	T GetVal();
	void SetVal(T value);
};





//source code:
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
