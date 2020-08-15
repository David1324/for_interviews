#ifndef LinkedList_h
#define LinkedList_h

#include <iostream>
using namespace std;

// LinkedList.h -- class for a linked list as a data structure

template <class DataType>
struct Node
{
	DataType data;
	Node<DataType> *next;
};

template <class DataType>
class LinkedList
{
public:
	LinkedList();
	LinkedList(const LinkedList<DataType> & aplist);
	~LinkedList();
	LinkedList<DataType> & operator = (const LinkedList<DataType> & rlist);
	void insert(const DataType & element); // no current position after use
	bool first(DataType & listEl);	  // returns first element of list in listEl
	inline bool getNext(DataType & listEl);	  // retrieves the next element of a linked list
	bool find(const DataType & element);  // returns true if element is found
	bool retrieve(DataType & element);  // like find, except returns found element
	bool replace(const DataType & newElement); // replaces element at current position
	bool remove(DataType & element);    // returns true if element is found
	bool isEmpty() const;				  // returns true if linked list is empty
	void makeEmpty();					  // no current position
private:
	Node<DataType> *start;
	Node<DataType> *current;			  // points to node at current position
	inline void deepCopy(const LinkedList<DataType> & original);
};

#endif 