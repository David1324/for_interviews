#include "My_Tree.h"

int main()
{
	My_Tree my_tree;
	vector<int> sorted_arr;
	sorted_arr.push_back(1);
	sorted_arr.push_back(2);
	sorted_arr.push_back(3);
	sorted_arr.push_back(4);
	sorted_arr.push_back(5);
	sorted_arr.push_back(6);
	sorted_arr.push_back(7);
	sorted_arr.push_back(8);
	sorted_arr.push_back(9);

	My_Tree* tree_with_minimal_height = my_tree.build_tree_with_minimal_height(sorted_arr);


	getchar();
	return 0;
}