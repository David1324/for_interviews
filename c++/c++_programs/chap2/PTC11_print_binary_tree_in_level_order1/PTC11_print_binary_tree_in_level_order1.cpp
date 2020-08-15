#include <iostream>
#include <vector>

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

class Tree
{
private:
	node * root;
	void helper_insert_node(node* &root, int val);
	void helper_inorder_print(node* root);
	void helper_level_order_print(node* root, int level);
	vector<int> helper_create_nodes_in_level_order_to_array(node* root, int level);
	int helper_calc_height(node* root);
	vector<int> helper_calc_longest_path(node* root);

public:
	Tree();
	void insert_node(int val);
	void inorder_print();
	void level_order_print();
	int calc_height();
	vector<int> calc_longest_path();
	vector<int> create_nodes_in_level_order_to_array();
};

Tree::Tree()
{
	root = NULL;
}

vector<int> Tree::helper_create_nodes_in_level_order_to_array(node* root, int level)
{
	vector<int> level_nodes;
	if (root == NULL) return level_nodes;
	if (level == 1)
	{
		level_nodes.push_back(root->val);
	}
	else
	{
		vector<int> level_nodes_left_side = helper_create_nodes_in_level_order_to_array(root->left, level-1);
		vector<int> level_nodes_right_side = helper_create_nodes_in_level_order_to_array(root->right, level - 1);
		level_nodes.insert(level_nodes.end(), level_nodes_left_side.begin(), level_nodes_left_side.end());
		level_nodes.insert(level_nodes.end(), level_nodes_right_side.begin(), level_nodes_right_side.end());
		
	}
	return level_nodes;
}

vector<int> Tree::create_nodes_in_level_order_to_array()
{
	vector<int> level_order_nodes;
	int height = calc_height();
	for (int i = 1; i <= height; i++)
	{
		vector<int> current_array = helper_create_nodes_in_level_order_to_array(root, i);
		level_order_nodes.insert(level_order_nodes.end(), current_array.begin(), current_array.end());
	}
	return level_order_nodes;
}

vector<int> Tree::calc_longest_path()
{
	return helper_calc_longest_path(root);
}

vector<int> Tree::helper_calc_longest_path(node* root)
{
	vector<int> longest_path;
	if (root == NULL)
	{
		return longest_path;
	}
	else
	{
		vector<int> left_longest_path = helper_calc_longest_path(root->left);
		vector<int> right_longest_path = helper_calc_longest_path(root->right);
		size_t size_left_longest_path = left_longest_path.size();
		size_t size_right_longest_path = right_longest_path.size();
		longest_path.push_back(root->val);
		if (size_left_longest_path > size_right_longest_path)
		{
			longest_path.insert(longest_path.end(), left_longest_path.begin(), left_longest_path.end());
		}
		else
		{
			longest_path.insert(longest_path.end(), right_longest_path.begin(), right_longest_path.end());
		}
	}
	return longest_path;
}

int Tree::calc_height()
{
	return helper_calc_height(root);
}

int Tree::helper_calc_height(node* root)
{
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		int height;
		int left_height = helper_calc_height(root->left);
		int right_height = helper_calc_height(root->right);
		if (left_height > right_height)
		{
			height = left_height + 1;
		}
		else
		{
			height = right_height + 1;
		}
		return height;
	}
}

void Tree::helper_level_order_print(node* root, int level)
{
	if (root == NULL)
		return;
	if (level == 1)
	{
		cout << root->val << ", ";
	}
	else
	{
		helper_level_order_print(root->left, level - 1);
		helper_level_order_print(root->right, level - 1);
	}
}

void Tree::level_order_print()
{
	int height = calc_height();
	for (int i = 1; i <= height; i++)
	{
		helper_level_order_print(root, i);
	}
}

void Tree::helper_inorder_print(node* root)
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		helper_inorder_print(root->left);
		cout << root->val << endl;
		helper_inorder_print(root->right);
	}
}

void Tree::inorder_print()
{
	helper_inorder_print(root);
}

void Tree::helper_insert_node(node* &root, int val)
{
	if (root == NULL)
	{
		root = new node;
		root->val = val;
		root->right = NULL;
		root->left = NULL;
	}
	else
	{
		if (val == root->val)
		{
			return;
		}
		else if (val > root->val)
		{
			helper_insert_node(root->right, val);
		}
		else if (val < root->val)
		{
			helper_insert_node(root->left, val);
		}
	}
}

void Tree::insert_node(int val)
{
	helper_insert_node(root, val);
}

int main()
{
	Tree my_tree;
	my_tree.insert_node(3);
	my_tree.insert_node(1);
	my_tree.insert_node(5);
	my_tree.insert_node(7);

	my_tree.inorder_print();

	int height = my_tree.calc_height();

	cout << "The height = " << height << endl;

	vector<int> longest_path = my_tree.calc_longest_path();

	cout << "Longest path = " << endl;

	size_t size_longest_path = longest_path.size();
	for (size_t i = 0; i < size_longest_path; i++)
	{
		int current_node = longest_path[i];
		cout << current_node << ", ";
	}
	cout << "\n\n";

	cout << "Level order print:" << endl;
	my_tree.level_order_print();

	cout << "\n\n";

	vector<int> level_order_nodes = my_tree.create_nodes_in_level_order_to_array();

	for (size_t i = 0; i < level_order_nodes.size(); i++)
	{
		cout << level_order_nodes[i] << ", ";
	}
	cout << "\n\n";

	getchar();
	return 0;
}