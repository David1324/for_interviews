#include <iostream>
#include <stdlib.h>

using std::cout;
using std::endl;

int option = 0;

typedef struct Node
{
	int id;
}Node;

int main()
{
	Node* ptr = NULL;
	if (option == 1)
	{
		Node* ptr = (Node*)malloc(sizeof(Node));
		ptr->id = 3;
	}

	//if (ptr->id && ptr != NULL)
	//{
	//	cout << "hello1" << endl;
	//}

	if (ptr != NULL && ptr->id)
	{
		cout << "hello2" << endl;
	}

	getchar();
	return 0;
}