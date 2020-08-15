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

	Node* helper_find_nth_to_last_element(Node* root, int n, int& location);
	friend My_List* helper_add_two_lists(Node* root1, Node* root2, int& carry);

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

	Node* find_nth_to_last_element_recursively(int n);
	Node* find_nth_to_last_element_iteratively(int n);
	void remove_given_node_only(Node* &node_to_delete);
	friend My_List* add_two_lists(My_List const& list1, My_List const& list2);
};

#endif 
