#pragma once

#include <iostream>
#include "Node.h"

using namespace std;

template <class T>
class List
{
private:
	Node<T>* m_pHead;
	Node<T>* m_pTail;

	void copyList(const List &list);

public:
	List();
	void Reverse();
	void addNodeToEnd(T value);
	void addNodeToStart(T value);
	void removeLast();
	void removeFirst();
	~List();
	List(const List &list);  // copy constructor

	//const List& operator=(const List& list);
	List& operator=(const List& list);
	
	template <class U>
	friend ostream& operator<<(ostream& os, const List<U>& list);
	//ostream& operator<<(ostream& os);
};











//source code:
template <class T>
void List<T>::Reverse()
{
	if (m_pHead != NULL)
	{
		m_pHead->Swap(m_pHead->GetNext());
		m_pHead->SetNext(NULL);
	}

	Node<T>* pTemp = m_pHead;
	m_pHead = m_pTail;
	m_pTail = pTemp;
}

template <class T>
List<T>::List() : m_pHead(NULL), m_pTail(NULL) //can't use this->.. because this exists only after the construction of the object is done.
{
	cout << "List: Contructor" << endl;
	//this->m_pHead = NULL;
	//this->m_pTail = NULL;
}

template <class T>
void List<T>::addNodeToEnd(T value)
{
	Node<T>* temp = new Node<T>;
	temp->SetVal(value);
	temp->SetNext(NULL);
	//if the list was empty before calling this function (the only case m_pTail can be NULL)
	if (m_pTail != NULL)
	{
		m_pTail->SetNext(temp);
	}
	m_pTail = temp;

	//if the list was empty before calling this function
	if (m_pHead == NULL)
	{
		m_pHead = m_pTail;
	}
}

template <class T>
void List<T>::addNodeToStart(T value)
{
	Node<T>* temp = new Node<T>;
	temp->SetVal(value);
	temp->SetNext(m_pHead);
	m_pHead = temp;

	//if the list was empty before calling this function
	if (m_pTail == NULL)
	{
		m_pTail = m_pHead;
	}
}

template <class T>
ostream& operator<<(ostream& os, const List<T>& list)
{
	Node<T>* temp = list.m_pHead;
	while (temp != NULL)
	{
		T value = temp->GetVal();
		os << value << ", ";
		temp = temp->GetNext();
	}
	os << "\n\n\n";
	//os << endl;
	return os;
}

template <class T>
void List<T>::removeLast()
{
	Node<T>* beforeLast = m_pHead;
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
	Node<T>* secondNode = m_pHead->GetNext();
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
		Node<T> * n = m_pHead->GetNext();
		delete m_pHead;
		m_pHead = n;
	}
}

template <class T>
List<T>::List(const List &list)  // copy constructor
{
	cout << "List: Copy constructor" << endl;
	copyList(list);
}

//template <class T>
//const List<T>& List<T>::operator=(const List &list)
//{
//	cout << "List: Operator =" << endl;
//	copyList(list);
//	return list;
//}

template <class T>
List<T>& List<T>::operator=(const List &list)
{
	cout << "List: Operator =" << endl;
	copyList(list);
	return *this;
}

template <class T>
void List<T>::copyList(const List &list)
{
	Node<T>* head = new Node<T>;
	head->SetVal(list.m_pHead->GetVal());

	Node<T>* prev = head;
	Node<T>* node = list.m_pHead->GetNext();
	while (node != NULL)
	{
		Node<T>* temp = new Node<T>;
		prev->SetNext(temp);
		temp->SetVal(node->GetVal());

		prev = temp;
		node = node->GetNext();
	}

	this->m_pHead = head;
	this->m_pTail = prev;
}