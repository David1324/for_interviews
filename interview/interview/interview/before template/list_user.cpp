#include "List.h"
#include <iostream>

int main()
{
	List myList;
	//myList.addNodeToStart(3);
	//myList.addNodeToStart(2);
	//myList.addNodeToStart(1);

	myList.addNodeToEnd(1);
	myList.addNodeToEnd(2);
	myList.addNodeToEnd(3);
	myList.addNodeToEnd(4);
	myList.addNodeToEnd(5);	

	List copiedList = myList;
	myList.removeFirst();
	copiedList.removeLast();

	cout << "original list:" << endl;
	cout << myList;

	cout << "\n\n";

	cout << "copied list:" << endl;
	cout << copiedList;

	//cout << "\n\n";

	//copiedList.Reverse();
	//cout << "reversed list:" << endl;
	//cout << copiedList;

	getchar();

}