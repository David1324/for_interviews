#include "List.h"
#include <iostream>

typedef int DATA_TYPE;

int main()
{
	List<DATA_TYPE> myList;
	//myList.addNodeToStart(3);
	//myList.addNodeToStart(2);
	//myList.addNodeToStart(1);

	myList.addNodeToEnd(101);
	myList.addNodeToEnd(102);

	myList.addNodeToEnd(103);
	myList.addNodeToEnd(104);
	myList.addNodeToEnd(105);
	myList.addNodeToEnd(106);	

	//List<DATA_TYPE> copiedList = myList;
	List<DATA_TYPE> copiedList;
	List<DATA_TYPE> list3;
	list3 = copiedList = myList;
	myList.removeFirst();
	copiedList.removeLast();

	cout << "original list:" << endl;
	cout << myList;

	cout << "copied list:" << endl;
	cout << copiedList;

	cout << "list3:" << endl;
	cout << list3;

	copiedList.Reverse();
	cout << "reversed list:" << endl;
	cout << copiedList;

	getchar();

}