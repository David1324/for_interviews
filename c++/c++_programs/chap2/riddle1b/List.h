#include "Node.h"
#include <iostream>
using namespace std;

class List
{
private:
	Node *head;
	Node *tail;

public:
	void insert_after_last(int val);
	List() : head(NULL), tail(NULL) {};
	friend ostream& operator<<(ostream& os, const List& list);
	void reverse();

};
