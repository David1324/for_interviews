#include <iostream>
#include <stdlib.h>

using std::cout;
using std::endl;

#define NULL 0

typedef struct node
{
	int val;
	node* right;
	node* left;
} node;

void insert_node(node* &root, int val)
{
	if (root == NULL)
	{
		root = (node*)calloc(1, sizeof(node));
		root->val = val;
	}
	else
	{
		if (val == root->val)
		{
			return;
		}
		else if (val > root->val)
		{
			insert_node(root->right, val);
		}
		else if (val < root->val)
		{
			insert_node(root->left, val);
		}
	}
}

void inorder_point(node* root)
{
	if (root == NULL)
	{
		return;
	}
	else
	{
		inorder_point(root->left);
		cout << root->val << endl;
		inorder_point(root->right);
	}
}

int calc_height(node* root)
{
	if (root == NULL)
	{
		return 0;
	}
	else
	{
		int height;
		int left_height = calc_height(root->left);
		int right_height = calc_height(root->right);
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

int main()
{
	node* root = NULL;
	insert_node(root, 3);
	insert_node(root, 1);
	insert_node(root, 5);
	insert_node(root, 7);
	insert_node(root, 2);

	inorder_point(root);

	int height = calc_height(root);
	cout << "The height = " << height << endl;

	getchar();
	return 0;

}