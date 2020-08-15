#include "List.h"
#include "Node.h"
#include <stdio.h>

bool debug_value;

void List::Reverse()
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

List::List()
{
	cout << "List: Contructor" << endl;
	this->m_pHead = NULL;
	this->m_pTail = NULL;
}

void List::addNodeToEnd(int value)
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

void List::addNodeToStart(int value)
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

//ostream& List::operator<<(ostream& os)
//{
//	Node* temp = this->m_pHead;
//	while (temp != NULL)
//	{
//		int value = temp->GetVal();
//		os << value << ", ";
//		temp = temp->GetNext();
//	}
//	os << endl;
//	return os;
//}

ostream& operator<<(ostream& os, const List& list)
{
		Node* temp = list.m_pHead;
		while (temp != NULL)
		{
			int value = temp->GetVal();
			os << value << ", ";
			temp = temp->GetNext();
		}
		os << endl;
		return os;
}

void List::removeLast()
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

void List::removeFirst()
{
	Node* secondNode = m_pHead->GetNext();
	if (m_pHead == m_pTail)
	{
		m_pTail = NULL;
	}
	delete m_pHead;

	m_pHead = secondNode;	
}

List::~List() {
	cout << "Destructor" << endl;
	while (m_pHead != NULL) {
		Node * n = m_pHead->GetNext();
		delete m_pHead;
		m_pHead = n;
	}
}

List::List(const List &list)  // copy constructor
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