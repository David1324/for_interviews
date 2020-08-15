#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
	vector<int> v(10, 0);

	// iterator
	vector<int>::iterator it;
	it = v.begin(); //ok
	*it = 911; // ok
	it++; //ok

	// const_iterator
	vector<int>::const_iterator cit;
	cit = v.begin();
	// *cit = 911; // Error: cannot assign to a variable that is const
	cit++; // ok

	// iterator that is constant
	const vector<int>::iterator itc = v.begin();
	// itc = v.begin();  // Can't assign a new value
	*itc = 911;  // ok: itc can change its underlying element
	// itc++; // Error: can't change the value of itc

    // wait until user is ready before terminating program
    // to allow the user to see the program results
    system("PAUSE");
	return 0;
}