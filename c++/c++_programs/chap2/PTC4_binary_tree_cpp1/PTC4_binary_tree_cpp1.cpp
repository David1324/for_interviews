#include <iostream>
#include <vector>

using std::ostream;
using std::cout;
using std::endl;
using std::vector;


typedef struct Node
{
	int val;
	Node* left;
	Node* right;
}Node;

class My_Tree
{
private:
	Node * root;
	void helper_insert_node(Node*& node, int val)
	{
		if (node == NULL)
		{
			node = new Node;
			node->left = NULL;
			node->right = NULL;
			node->val = val;
		}
		else
		{
			if (val == node->val)
			{
				return;
			}
			else if (val > node->val)
			{
				helper_insert_node(node->right, val);
			}
			else //if (val < node->val)
			{
				helper_insert_node(node->left, val);
			}
		}
	}
	int helper_calc_height(Node* node)
	{
		int height;
		if (node == NULL)
			return 0;
		int left_height = helper_calc_height(node->left);
		int right_height = helper_calc_height(node->right);
		if (left_height > right_height)
			height = left_height + 1;
		else
			height = right_height + 1;
		return height;
	}

	void helper_inorder_print(Node* node)
	{
		if (node == NULL)
		{
			return;
		}
		else
		{
			helper_inorder_print(node->left);
			cout << node->val << endl;
			helper_inorder_print(node->right);
		}
	}

	vector<int> helper_calc_longest_path(Node* node)
	{
		vector<int> longest_path;
		if (node == NULL)
		{
			return longest_path;
		}
		else
		{
			vector<int> left_longest_path = helper_calc_longest_path(node->left);
			size_t size_left_longest_path = left_longest_path.size();
			vector<int> right_longest_path = helper_calc_longest_path(node->right);
			size_t size_right_longest_path = right_longest_path.size();

			longest_path.push_back(node->val);
			if (size_left_longest_path > size_right_longest_path)
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
		if (root == NULL)
		{
			root = new Node;
			root->left = NULL;
			root->right = NULL;
			root->val = val;
		}
		else
		{
			helper_insert_node(root, val);
		}
	}

	int calc_height()
	{
		int height = helper_calc_height(root);
		return height;
	}

	//friend ostream& operator<<(ostream& os, const My_Tree& tree)
	//{
	//	//inorder print:
	//	os << tee
	//}

	void inorder_print()
	{
		helper_inorder_print(root);
	}

	vector<int> calc_longest_path()
	{
		vector<int> longest_path = helper_calc_longest_path(root);
		return longest_path;
	}
};

int main()
{
	My_Tree my_tree;
	my_tree.insert_node(3);
	my_tree.insert_node(1);
	my_tree.insert_node(5);
	my_tree.insert_node(7);

	my_tree.inorder_print();

	vector<int> longest_path = my_tree.calc_longest_path();

	vector<int>::iterator i;
	for (i = longest_path.begin(); i != longest_path.end(); i++)
	{
		int current_val = *i;
		cout << current_val << ", ";
	}
	cout << endl;

	int height = my_tree.calc_height();
	cout << "height = " << height << endl;

	getchar();
	return 0;
}