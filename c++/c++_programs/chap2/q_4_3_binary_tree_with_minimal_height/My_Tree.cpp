#include "My_Tree.h"

My_Tree::My_Tree()
{
	root = NULL;
}

vector<int> My_Tree::calc_longest_path()
{
	return helper_calc_longest_path(root);
}

vector<int> My_Tree::helper_calc_longest_path(node* root)
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

int My_Tree::calc_max_height()
{
	return helper_calc_max_height(root);
}

int My_Tree::helper_calc_max_height(node* root)
{
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		int height;
		int left_height = helper_calc_max_height(root->left);
		int right_height = helper_calc_max_height(root->right);
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

int My_Tree::calc_min_height()
{
	return helper_calc_min_height(root);
}

int My_Tree::helper_calc_min_height(node* root)
{
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		int height;
		int left_height = helper_calc_max_height(root->left);
		int right_height = helper_calc_max_height(root->right);
		if (left_height < right_height)
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

void My_Tree::helper_inorder_print(node* root)
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

void My_Tree::inorder_print()
{
	helper_inorder_print(root);
}

void My_Tree::helper_insert_node(node* &root, int val)
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

void My_Tree::insert_node(int val)
{
	helper_insert_node(root, val);
}

bool My_Tree::check_if_balanced()
{
	int max_height = calc_max_height();
	int min_height = calc_min_height();
	int diff_heights = max_height - min_height;
	if (diff_heights <= 1)
		return true;
	else
		return false;
}

My_Tree* My_Tree::build_tree_with_minimal_height(vector<int> sorted_arr)
{
	My_Tree* tree = new My_Tree();
	size_t num_of_elements = sorted_arr.size();
	if (num_of_elements == 0)
		return tree;
	size_t middle_index = num_of_elements / 2;
	int middle_val = sorted_arr[middle_index];
	tree->insert_node(middle_val);
	vector<int>::iterator first_left_iterator = sorted_arr.begin();
	vector<int>::iterator last_left_iterator = sorted_arr.begin() + middle_index;

	vector<int>::iterator first_right_iterator = sorted_arr.begin() + middle_index + 1;
	vector<int>::iterator last_right_iterator = sorted_arr.begin() + num_of_elements;

	vector<int> left_array(first_left_iterator, last_left_iterator);
	vector<int> right_array(first_right_iterator, last_right_iterator);

	My_Tree* left_sub_tree = build_tree_with_minimal_height(left_array);
	My_Tree* right_sub_tree = build_tree_with_minimal_height(right_array);

	tree->root->left = left_sub_tree->root;
	tree->root->right = right_sub_tree->root;

	return tree;
}