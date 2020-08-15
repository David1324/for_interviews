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

public:
	List();
	void Reverse();
	void addNodeToEnd(T value);
	void addNodeToStart(T value);
	void removeLast();
	void removeFirst();
	~List();
	List(const List &list);  // copy constructor
	

	friend ostream& operator<<(ostream& os, const List& list);
	//ostream& operator<<(ostream& os);
};