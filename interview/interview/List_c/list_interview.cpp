#include <stdio.h>
#include <stdlib.h>


struct element1
{
	int val;
	struct element1* next;
};
typedef struct element1 element;

element* reverse_list(element* first_node)
{
	element* last_node = first_node;
	while (last_node->next != NULL) last_node = last_node->next;

	element* node = last_node;
	while (node != first_node)
	{
		element* prev_node = first_node;
		while (prev_node->next != node)
		{
			prev_node = prev_node->next;
		}
		node->next = prev_node;
		node = node->next;
	}
	node->next = NULL;

	return last_node;
}


int main()
{

	//string math_problem = "7+3";
	element* node1 = (element*)malloc(sizeof(element));
	element* node2 = (element*)malloc(sizeof(element));
	element* node3 = (element*)malloc(sizeof(element));

	node1->val = 1;
	node1->next = node2;

	node2->val = 2;
	node2->next = node3;

	node3->val = 8;
	node3->next = NULL;

	element* node = node1;
	printf("regulare list:\n");
	while (node != NULL)
	{
		printf("%d\n", node->val);
		node = node->next;
	}
	printf("\n\n");
	printf("reversed list:\n");

	node = reverse_list(node1);
	while (node != NULL)
	{
		printf("%d\n", node->val);
		node = node->next;
	}


	getchar();
	return 0;
}