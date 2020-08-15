#include <iostream>
using namespace std;

class B;

class A
{
private:
	A() { cout << "A()" << endl; };
	friend class B;
};

// B can access A() because of the "friend"
class B : public A
{
public: B(){ cout << "B()" << endl; }
};

class Derived : public B
{
public: Derived() { cout << "Derived()" << endl; }
};

int main()
{
	Derived dd;
	return 0;
}