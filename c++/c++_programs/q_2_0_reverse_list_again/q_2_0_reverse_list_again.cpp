#include <stdlib.h>
#include <iostream>

using std::cout;
using std::endl;
using std::ostream;

typedef struct Node
{
	int val;
	Node* next;
} Node;

class My_List
{
private:
	Node * root;
	void helper_reverse_list_recursively(Node* &root)
	{
		if (root == NULL)
			return;

		Node* rest = root->next;
		if (rest == NULL)
			return;

		helper_reverse_list_recursively(rest);

		root->next->next = root;
		root->next = NULL;
		root = rest;
	}

public:
	My_List()
	{
		root = NULL;
	}

	My_List(const My_List& list)
	{
		Node* temp = list.root;
		while (temp != NULL)
		{
			insert_node_at_end(temp->val);
			temp = temp->next;
		}
	}

	void insert_node_at_beginning(int val)
	{
		Node* new_node = new Node();
		new_node->val = val;
		new_node->next = root;
		root = new_node;
	}

	void insert_node_at_end(int val)
	{
		Node* new_node = new Node();
		new_node->val = val;
		new_node->next = NULL;

		if (root == NULL)
		{
			root = new_node;			
		}
		else
		{
			Node* current_last_node = root;
			while (current_last_node->next != NULL)
			{
				current_last_node = current_last_node->next;
			}
			current_last_node->next = new_node;
		}
	}

	friend ostream& operator<<(ostream& os, const My_List& list)
	{
		Node* temp = list.root;
		while (temp != NULL)
		{
			os << temp->val << ", ";
			temp = temp->next;
		}
		os << endl;
		return os;
	}

	void remove(int val)
	{
		if (root == NULL) return;

		if (root->val == val)
		{
			Node* temp = root->next;
			delete root;
			root = temp;	
		}
		else
		{
			Node* temp = root;
			while (temp->next->val != val)
			{
				temp = temp->next;
			}
			Node* new_next = temp->next->next;
			delete temp->next;
			temp->next = new_next;			
		}
	}

	void reverse_list_recursively()
	{
		helper_reverse_list_recursively(root);
	}

	void reverse_list_iteratively()
	{
		Node* current = root;
		Node* prev = NULL;
		while (current != NULL)
		{
			root = current;
			Node* temp = current->next;
			current->next = prev;
			prev = current;
			current = temp;
		}
	}




};

int main()
{
	My_List my_list;
	my_list.insert_node_at_end(1);
	my_list.insert_node_at_end(2);
	my_list.insert_node_at_end(3);
	my_list.insert_node_at_end(4);
	my_list.insert_node_at_end(5);
	my_list.insert_node_at_end(6);
	My_List list2 = my_list;

	cout << "my_list:" << endl;
	cout << my_list;

	my_list.remove(3);

	cout << "my_list:" << endl;
	cout << my_list;


	cout << "List2:" << endl;
	cout << list2;

	my_list.reverse_list_iteratively();
	cout << "Reversed list (iteratively):" << endl;
	cout << my_list;

	my_list.reverse_list_recursively();
	cout << "Reversed list (recuresively):" << endl;
	cout << my_list;

	getchar();
	return 0;
}