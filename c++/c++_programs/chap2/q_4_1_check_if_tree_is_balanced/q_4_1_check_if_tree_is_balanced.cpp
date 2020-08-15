#include "My_Tree.h"

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