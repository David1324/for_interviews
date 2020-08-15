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

	node* root = my_tree.get_root();
	node* current_node = root->right;
	node* next_inorder_node = my_tree.find_next_in_order(current_node);

	if (next_inorder_node == NULL)
	{
		printf("There is no inorder next of node (%d)\n", current_node->val);
	}
	else
	{
		printf("Inorder next of node (%d) is node (%d)\n", current_node->val, next_inorder_node->val);
	}
	

	getchar();
	return 0;
}