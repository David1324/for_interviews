#ifndef MY_LIST_H
#define MY_LIST_H

#include <iostream>

using std::ostream;
using std::cout;
using std::endl;

#define NULL 0

typedef struct Node
{
	int val;
	Node* next;
} Node;

class My_List
{
private:
	Node * root;
	void helper_reverse_list_recursively(Node* &head_ref);

public:
	My_List();
	~My_List();
	My_List(const My_List& my_list);
	Node* get_root();
	void insert_node_at_beginning(int val);
	void insert_node_at_end(int val);
	Node* find_node(int val);
	void remove(int val);
	friend ostream& operator<<(ostream& os, const My_List& list);
	void reverse_list_iteratively();
	void reverse_list_recursively();
};

#endif 
