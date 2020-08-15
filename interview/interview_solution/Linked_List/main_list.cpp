#include "LinkedList.h"
#include "LinkedList.h" // to test #ifndef
#include <cassert>
using namespace std;

int main()
{
	LinkedList <int> a; // test obj
	int var;

	// testing constructor
	assert(a.isEmpty() == true);
	cout << "Constructor working successfully" << endl;

	a.insert(5);
	a.insert(6);

	assert(a.isEmpty() == false);
	cout << "Insert working successfully" << endl;

	a.makeEmpty();
	assert(a.isEmpty() == true);
	cout << "makeEmpty working successfully" << endl;

	a.insert(7);
	assert(a.isEmpty() == false);

	a.first(var); // get first value and set "current" to its node
}