#pragma once

#include <iostream>
#include "Node.h"

using namespace std;

class List
{
private:
	Node* m_pHead;
	Node* m_pTail;

public:
	List();
	void Reverse();
	void addNodeToEnd(int value);
	void addNodeToStart(int value);
	void removeLast();
	void removeFirst();
	~List();
	List(const List &list);  // copy constructor
	

	friend ostream& operator<<(ostream& os, const List& list);
	//ostream& operator<<(ostream& os);
};