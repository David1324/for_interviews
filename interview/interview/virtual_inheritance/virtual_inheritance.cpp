#include <iostream>
using namespace std;

class B;

class A
{
private:
	A() { cout << "A constructor" << endl; };
	friend class B;
	friend class Derived;
};

class B : virtual public A {};

class Derived : public B {};
// Error :  cannot access to  A()

int main()
{
	Derived dd;
	return 0;
}