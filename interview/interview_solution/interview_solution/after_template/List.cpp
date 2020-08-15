#include "List.h"
#include "Node.h"
#include <stdio.h>

bool debug_value;

template <class T>
void List<T>::Reverse()
{
	if (m_pHead != NULL)
	{
		m_pHead->Swap(m_pHead->GetNext());
		m_pHead->SetNext(NULL);
	}

	Node* pTemp = m_pHead;
	m_pHead = m_pTail;
	m_pTail = pTemp;
}

template <class T>
List<T>::List()
{
	cout << "List: Contructor" << endl;
	this->m_pHead = NULL;
	this->m_pTail = NULL;
}

template <class T>
void List<T>::addNodeToEnd(T value)
{
	Node* temp = new Node;
	temp->SetVal(value);
	temp->SetNext(NULL);
	if (m_pTail != NULL)
	{
		m_pTail->SetNext(temp);
	}
	m_pTail = temp;
	if (m_pHead == NULL)
	{
		m_pHead = m_pTail;
	}
}

template <class T>
void List<T>::addNodeToStart(T value)
{
	Node* temp = new Node;
	temp->SetVal(value);
	temp->SetNext(m_pHead);
	m_pHead =temp;
	if (m_pTail == NULL)
	{
		m_pTail = m_pHead;
	}
}

template <class T>
ostream& operator<<(ostream& os, const List<T>& list)
{
		Node* temp = list.m_pHead;
		while (temp != NULL)
		{
			T value = temp->GetVal();
			os << value << ", ";
			temp = temp->GetNext();
		}
		os << endl;
		return os;
}

template <class T>
void List<T>::removeLast()
{
	Node* beforeLast = m_pHead;
	while (beforeLast->GetNext() != m_pTail)
	{
		beforeLast = beforeLast->GetNext();
	}
	delete m_pTail;

	m_pTail = beforeLast;
	m_pTail->SetNext(NULL);
}

template <class T>
void List<T>::removeFirst()
{
	Node* secondNode = m_pHead->GetNext();
	if (m_pHead == m_pTail)
	{
		m_pTail = NULL;
	}
	delete m_pHead;

	m_pHead = secondNode;	
}

template <class T>
List<T>::~List() {
	cout << "Destructor" << endl;
	while (m_pHead != NULL) {
		Node * n = m_pHead->GetNext();
		delete m_pHead;
		m_pHead = n;
	}
}

template <class T>
List<T>::List(const List &list)  // copy constructor
{
	cout << "List: Copy constructor" << endl;
	Node* head = new Node;
	head->SetVal(list.m_pHead->GetVal());

	Node* prev = head;
	Node* node = list.m_pHead->GetNext();
	while (node != NULL)
	{
		Node* temp = new Node;
		prev->SetNext(temp);
		temp->SetVal(node->GetVal());

		prev = temp;
		node = node->GetNext();
	}

	this->m_pHead = head;
	this->m_pTail = prev;
}