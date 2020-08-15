#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

class node
{
public:
	int val;
	node* right;
	node* left;
};

class My_Tree
{
private:
	node * root;
	void helper_insert_node(node* &root, int val)
	{
		if (root == NULL)
		{
			root = new node();
			root->val = val;
			root->left = NULL;
			root->right = NULL;
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
			else
			{
				helper_insert_node(root->left, val);
			}
		}
	}
	void helper_inorder_print(node* root)
	{
		if (root == NULL) return;
		helper_inorder_print(root->left);
		cout << root->val << endl;
		helper_inorder_print(root->right);
	}

	int helper_calc_max_height(node* root)
	{
		if (root == NULL) return 0;
		int height_left_tree = helper_calc_max_height(root->left);
		int height_right_tree = helper_calc_max_height(root->right);
		if (height_left_tree > height_right_tree)
			return height_left_tree + 1;
		else
			return height_right_tree + 1;
	}

	int helper_calc_min_height(node* root)
	{
		if (root == NULL) return 0;
		int height_left_tree = helper_calc_min_height(root->left);
		int height_right_tree = helper_calc_min_height(root->right);
		if (height_left_tree < height_right_tree)
			return height_left_tree + 1;
		else
			return height_right_tree + 1;
	}
	vector<int> helper_calc_longest_path(node* root)
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
			size_t left_longest_path_size = left_longest_path.size();
			size_t right_longest_path_size = right_longest_path.size();
			longest_path.push_back(root->val);
			if (left_longest_path_size > right_longest_path_size)
			{
				longest_path.insert(longest_path.end(), left_longest_path.begin(), left_longest_path.end());
			}
			else
			{
				longest_path.insert(longest_path.end(), right_longest_path.begin(), right_longest_path.end());
			}
			return longest_path;
		}
	}

public:
	My_Tree()
	{
		root = NULL;
	}
	void insert_node(int val)
	{
		helper_insert_node(root, val);
	}

	void inorder_print()
	{
		helper_inorder_print(root);
	}

	int calc_max_height()
	{
		int max_height = helper_calc_max_height(root);
		return max_height;
	}

	int calc_min_height()
	{
		int min_height = helper_calc_min_height(root);
		return min_height;
	}
	vector<int> calc_longest_path()
	{
		vector<int> longest_path = helper_calc_longest_path(root);
		return longest_path;
	}
	bool check_if_balanced()
	{
		int max_height = calc_max_height();
		int min_height = calc_min_height();
		int diff_heights = max_height - min_height;
		if (diff_heights <= 1)
			return true;
		else
			return false;
	}
};


int main()
{
	My_Tree my_tree;
	my_tree.insert_node(3);
	my_tree.insert_node(1);
	my_tree.insert_node(5);
	my_tree.insert_node(7);
	my_tree.insert_node(4);

	my_tree.inorder_print();

	int height = my_tree.calc_max_height();

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

	bool is_balanced = my_tree.check_if_balanced();
	if (is_balanced)
	{
		cout << "The tree is balanced!\n";
	}
	else
	{
		cout << "The tree is NOT balanced!\n";
	}


	getchar();
	return 0;
}