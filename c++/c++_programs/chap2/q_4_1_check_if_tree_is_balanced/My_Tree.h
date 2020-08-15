#include <vector>
#include <iostream>

using std::cout;
using std::endl;
using std::vector;


class node
{
public:
	int val;
	node* left;
	node* right;
};

class My_Tree
{
private:
	node * root;
	void helper_insert_node(node* &root, int val);
	void helper_inorder_print(node* root);
	int helper_calc_max_height(node* root);
	int helper_calc_min_height(node* root);
	vector<int> helper_calc_longest_path(node* root);

public:
	My_Tree();
	void insert_node(int val);
	void inorder_print();
	int calc_max_height();
	int calc_min_height();
	vector<int> calc_longest_path();
	bool check_if_balanced();
};