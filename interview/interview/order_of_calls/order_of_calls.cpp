#include <iostream>
using namespace std;

class A
{
public:
	A(int n = 1) : ia(n) { cout << "constructor A (Base)" << endl; }
	~A() { cout << "Destructor A (Base)" << endl; }

protected:
	int ia;
};

class B : public A
{
public:
	B(int n) : ib(n) { cout << "constructor B (Derived)" << endl; }
	~B() { cout << "Destructor B (Derived)" << endl; }

private:
	int ib;
};

int main()
{
	B b(2);

	
	return 0;
}