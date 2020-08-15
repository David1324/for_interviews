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

	vector<list<node*>> vec_levels = my_tree.find_level_nodes();
	vector<list<node*>>::iterator vec_iterator;
	int level = 0;
	for (vec_iterator = vec_levels.begin(); vec_iterator != vec_levels.end(); vec_iterator++)
	{
		cout << "current level = " << level << endl;
		cout << "level nodes:" << endl;
		list<node*> current_list = *vec_iterator;
		list<node*>::iterator list_iterator;
		for (list_iterator = current_list.begin(); list_iterator != current_list.end(); list_iterator++)
		{
			node* current_node = *list_iterator;
			cout << current_node->val << ", ";
		}
		cout << "\n\n";
		level++;
	}

	getchar();
	return 0;
}