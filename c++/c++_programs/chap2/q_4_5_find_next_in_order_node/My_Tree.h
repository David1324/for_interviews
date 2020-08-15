#include <iostream>
#include <vector>
#include <list>

using std::cout;
using std::endl;
using std::vector;
using std::list;


class node
{
public:
	int val;
	node* left;
	node* right;
	node* parent;
};

class My_Tree
{
private:
	node * root;
	void helper_insert_node(node* parent, node* &root, int val);
	void helper_inorder_print(node* root);
	int helper_calc_max_height(node* root);
	int helper_calc_min_height(node* root);
	vector<int> helper_calc_longest_path(node* root);
	node* left_most_node(node* current_node);

public:
	My_Tree();
	node* get_root();
	void insert_node(int val);
	void inorder_print();
	int calc_max_height();
	int calc_min_height();
	vector<int> calc_longest_path();
	bool check_if_balanced();
	My_Tree* build_tree_with_minimal_height(vector<int> sorted_arr);
	vector<list<node*>> find_level_nodes();
	node* find_next_in_order(node* current_node);
};