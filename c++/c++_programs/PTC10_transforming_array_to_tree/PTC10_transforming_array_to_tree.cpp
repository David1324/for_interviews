#include <vector>

using std::vector;

typedef struct Node
{
	int val;
	Node* right;
	Node* left;
}Node;

class My_Tree
{
private:
	Node * root;

public:
	My_Tree()
	{
		root = NULL;
	}
	My_Tree(vector<int> arr)
	{
		root = transfrom_arr_to_tree(arr, 0);
	}

	Node* transfrom_arr_to_tree(vector<int> arr, int index)
	{
		size_t arr_size = arr.size();
		if (index >= arr_size) return NULL;
		Node* new_node = new Node();
		new_node->val = arr[index];
		new_node->left = transfrom_arr_to_tree(arr, 2 * index + 1);
		new_node->right = transfrom_arr_to_tree(arr, 2 * index + 2);
		return new_node;
	}
};


int main()
{
	vector<int> arr;
	arr.push_back(3);
	arr.push_back(4);
	arr.push_back(1);
	arr.push_back(2);
	My_Tree tree(arr);

	getchar();
}