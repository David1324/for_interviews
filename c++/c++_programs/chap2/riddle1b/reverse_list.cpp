#include "List.h"
#include <iostream>

int main()
{
	List my_list;
	my_list.insert_after_last(101);
	my_list.insert_after_last(102);
	my_list.insert_after_last(103);

	cout << my_list;

	my_list.reverse();
	cout << my_list;
	getchar();
}