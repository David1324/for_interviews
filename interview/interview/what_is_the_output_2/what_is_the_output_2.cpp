#include <iostream>
using namespace std;

class A
{
public:
	A(int n = 1) : ia(n)
	{
		cout << "A() ia = " << ia << endl;
	}
	~A()
	{
		cout << "~A() ia = " << ia << endl;
	}

protected:
	int ia;
};

class B : public A
{
public:
	B(int n) : a1(new A[5]), a2(n), A(3)
	{
		cout << "B() ia = " << ia << endl;
	}
	~B()
	{
		delete[] a1;
		cout << "~B() ia = " << ia-- << endl;
		
	} //only here, after the closing, the member a2 of be is destructed (a1 is destructed only when explicitly called with delete[]). and at the very end
	// the constructor of the base A (since B is derived from A) is destructed.

private:
	A a2;
	A* a1;
};

int main()
{
	{ B b(20); }

	return 0;
}